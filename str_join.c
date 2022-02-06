#include<unistd.h>

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

	join = (char*)malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	i = 0;
	j = 0;
	while(path[i])
		join[j++] = path[i++];
	join[j++] = '/';
	i = 0;
	while(cmd[i])
		join[j++] = cmd[i++];
	join[j++] = 0;
	return(join);
}