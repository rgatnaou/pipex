
#include<unistd.h>

char	*str_ncp(char *str,int n)
{
	char	*cp;
	int		i;

	i = 0;
	cp = malloc(n + 1);
	while (i < n)
	{
		cp[i] = str[i];
		i++;
	}
	cp[n] = 0;
	return(cp)
}

char	**str_split(char *str,char *sp)
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