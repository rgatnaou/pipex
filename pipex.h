/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:26:24 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/10 18:26:26 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>

char    *str_join(char *path, char *cmd);
char    **str_split(char *str,char sp);
int     ft_strlen(char *str);
char	*str_ncp(char *str,int n);
int     char_check(char *str,char c);
int     str_check(char *str1,char *str2,int n);

#endif