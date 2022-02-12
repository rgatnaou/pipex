/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:28:45 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/12 16:28:46 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int file(char *path,int inout)
{
	if(inout == 0)
	{
		if(access(path,R_OK))
		{
			write(2, "Pipex:\"", 7);
			write(2, path, ft_strlen(path));
			write(2, "\":No such file or directory", 27);
		}
		return(open(path, O_RDONLY));
	}
	else
		return(open(path, O_CREAT | O_WRONLY | O_TRUNC,
						S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP  | S_IROTH));
}

char	*get_path(char *cmd, char **envp)
{
	char	*env;
	char	*dir;
	char	*path;
	int		i;

	i = 0;
	while(envp[i] && str_check(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return(cmd);
	env = envp[i] + 5;
	while(env && char_check(env, ':') != -1)
	{
		dir =str_ncp(env,char_check(env,':'));
		path=str_join(dir,cmd);
		free(dir);
		if(!access(path,X_OK))
			return(path);
		free(path);
		env += char_check(env,':') + 1;
	}
	return(cmd);
}

void	exec(char *cmd, char **envp)
{
	char	**cd;
	char	*path;

	cd = str_split(cmd,' ');
	if (!cd)
	{
		write(2, "Pipex:\"", 7);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\": Command Not Found\n", 21);
	}
	if (char_check(cd[0],'/') != -1)
		path = cd[0];
	else
		path = get_path(cd[0], envp);
	execve(path, cd, envp);
	ft_free(cd);
	write(2, "Pipex:\"", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\": Command Not Found\n", 21);
}

void reader(char *cmd, char **envp)
{
	int	fdpipe[2];
	pid_t	pid;

	pipe(fdpipe);
	pid =fork();
	if(pid)
	{
		close(fdpipe[1]);
		dup2(fdpipe[0],0);
		waitpid(pid,NULL,0);
	}
	else	
	{
		close(fdpipe[0]);
		dup2(fdpipe[1],1);
		exec(cmd,envp);
	}
}

int main(int argc, char **argv, char **envp)
{
	int fd_r;
	int fd_w;
	int	i;

	if (argc >= 5)
	{
		i = 3;
		fd_r = file(argv[1], 0);
		fd_w = file(argv[argc - 1], 1);
		dup2(fd_r, 0);
		dup2(fd_w, 1);
		reader(argv[2], envp);
		while (i < argc - 2)
			reader(argv[i++],envp);
		exec(argv[i],envp);
	}
}