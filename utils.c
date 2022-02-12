/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:25:52 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/11 15:50:15 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	char_check(char *str,char c)
{
	int	i;

	i = 0;
	if(!str)
		exit(1);
	while (str[i] && str[i] !=c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

int	str_check(char *str1,char *str2,int n)
{
	int	i;

	if(!str1 || !str2)
		exit(1);
	i = 0;
	while(str1[i] && str2[i] && str1[i] == str2[i] && (i < n - 1))
		i++;
	return(str1[i] - str2[i]);
}

char	*str_ncp(char *str, int n)
{
	char	*cp;
	int		i;

	if(!str)
		exit(1);
	i = 0;
	cp = malloc(n + 1);
	if(!cp)
		return(NULL);
	while (i < n)
	{
		cp[i] = str[i];
		i++;
	}
	cp[n] = 0;
	return(cp);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}