#include "pipex.h"

int     char_check(char *str,char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] !=c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

int     str_check(char *str1,char *str2,int n)
{
	int	i;

	i = 0;
	while(str1[i] && str2[i] && str1[i] == str2[i] && (i < n - 1))
		i++;
	return(str1[i] - str2[i]);
}
