# include "../pipex.h"

char *get_path(char **envp)
{
	int i;

	i = 0;
	while (envp && envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_substr(envp[i], 5, strlen(envp[i])));
		i++;
	}
	return (NULL);
}

char *do_comand(t_cmds *cmds, char *path, int n)
{
	char **div_path;
	char *path_send;
	int i;

	i = 0;
	div_path = ft_split(path, ':');
	while (div_path[i])
	{
		path_send = ft_strjoin_2(div_path[i], cmds[n].cmd[0]);
		if (access(path_send, F_OK) == 0)
		{
			fprintf(stderr, "ola\n");
			return (path_send);
		}
		free(path_send);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_2(char const *s1, char const *s2)
{
	int		i;
	int		v;
	char	*newstr;

	i = 0;
	v = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!newstr)
		return (NULL);
	if (s1 == 0 && s2 == 0)
		return (NULL);
	while (s1[v])
	{
		newstr[i] = s1[v];
		i++;
		v++;
	}
	newstr[i++] = '/';
	v = 0;
	while (s2[v])
		newstr[i++] = s2[v++];
	newstr[i] = '\0';
	return (newstr);
}