/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:26:06 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/10 20:11:01 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
} 
char *str_join(char *path, char *cmd)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if(!join)
	{
		free(join);
		return(NULL);
	}
	i = 0;
	j = 0;
	while(path[i])
		join[j++] = path[i++];
	join[j++] = '/';
	i = 0;
	while(cmd[i])
		join[j++] = cmd[i++];
	join[j] = 0;
	return(join);
}