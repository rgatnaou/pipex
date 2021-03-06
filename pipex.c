/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:26:34 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/12 10:38:03 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file(char *path, int inout)
{
	if (inout == 0)
	{
		if  (access(path, R_OK))
		{
			write(2,"Pipex: \"", 8);
			write(2, path, ft_strlen(path));
			write(2, "\": No such file or directory\n", 29);
			return(0);
		}
		return(open(path, O_RDONLY));
	}
	else
		return (open(path, O_CREAT | O_WRONLY | O_TRUNC,
						S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

char	*get_path(char *cmd, char **envp)
{
	char	*env;
	char	*dir;
	char 	*path;
	int		i;

	i = 0;
	while (envp[i] && str_check(envp[i],"PATH=",5))
		i++;
	if (!envp[i])
		return(cmd);
	env = envp[i] + 5;
	while (env && char_check(env,':') != -1)
	{
		dir = str_ncp(env,char_check(env,':'));
		path = str_join(dir,cmd);
		free(dir);
		if (!access(path, X_OK))
			return (path);
		free(path);
		env += char_check(env,':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **envp)
{
	char	**sp_cmd;
	char	*path;
	
	sp_cmd = str_split(cmd,' ');
	if (!sp_cmd)
	{
		write(2,"pipex: \"", 8);
		write(2, "\":Command Not Found\n", 20);
		exit(1);
	}
	if (char_check(sp_cmd[0],'/' ) != -1)
		path = sp_cmd[0];
	else
		path = get_path(sp_cmd[0], envp);
	execve(path, sp_cmd, envp);
	ft_free(sp_cmd);
	write(2,"pipex: \"", 8);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\":Command Not Found)\n", 21);
	exit(1);
}

void	readir(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL , 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		exec(cmd, envp);
	}
}

int	main (int argc, char **argv, char **envp)
{
	int		fd_w;
	int		fd_r;

	if (argc == 5)
	{
		fd_r = file(argv[1], 0);
		fd_w = file(argv[4], 1);
		dup2(fd_r, 0);
		dup2(fd_w, 1);
		readir(argv[2], envp);
		exec(argv[3], envp);
	}
	else
		write(2,"Pipex: (Invalid args.)\n",23);	
	return (1);
		
}