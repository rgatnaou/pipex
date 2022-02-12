/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:26:14 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/11 15:38:41 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count(char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

int	len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	leak(char **split, int l)
{
	int	i;

	i = -1;
	while (++i < l)
		free(split[i]);
	free(split);
}

void	write_sp(char **split, char *s, char c, int w)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	while (++i < w)
	{
		while (c == *s)
			s++;
		l = len(s, c);
		split[i] = (char *)malloc(sizeof(char) * l + 1);
		if (!split[i])
			leak(split, i);
		j = 0;
		while (j < l)
			split[i][j++] = *s++;
		split[i][j] = '\0';
	}
}

char	**str_split(char *s, char c)
{
	int		w;
	char	**split;

	if (!s)
		return (NULL);
	w = count(s, c);
	if (w == 0)
		return(NULL);
	split = (char **)malloc(sizeof(char *) * w + 1);
	if (!split)
		return (NULL);
	write_sp(split, s, c, w);
	split[w] = 0;
	return (split);
}