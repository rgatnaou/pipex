#ifndef PIPEX_H
# define PIPEX_H

#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>

char    *str_join(char *path, char *cmd);
char    **str_split(char *str,char *sp);
int     ft_strlen(char *str);
char	*str_ncp(char *str,int n);
