
#include "pipex.h"
void	ft_free(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
}

char	*str_ncp(char *str,int n)
{
	char	*cp;
	int		i;

	i = 0;
	cp = malloc(n + 1);
	if(!cp)
	{
		free(cp);
		return(NULL);
	}
	while (i < n)
	{
		cp[i] = str[i];
		i++;
	}
	cp[n] = 0;
	return(cp);
}

char	**str_split(char *str,char sp)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == sp)
			count++;
	tab = (char**)malloc(sizeof(char*) * (count + 2));
	if (!tab)
	{
		ft_free(tab);
		return(NULL);
	}
	tab[count + 1] = NULL;
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sp)
			j++;
		tab[i++] = str_ncp(str, j);
		str = str + j + 1;
	}
	return(tab);
}