# include "../pipex.h"

void get_array_of_structs(t_file *file, t_cmds *cmds, int ac, char **av)
{
	int i;
	int f;
	int c;

	i = 1;
	c = 0;
	f = 0;
	while (i < ac)
	{
		if(i == 1 || i == ac - 1)
		{
			file[f].file = ft_strcpy(av[i]);
			ft_printf("%s\n", file[f].file);
			f++;
		}
		else
			cmds[c++].cmd = ft_split(av[i], ' ');
		i++;
	}
}

t_cmds  **cmds(void)
{
	static t_cmds *cmds;
	return (cmds);
}

t_file  **file(void)
{
	static t_file file[2];
	return (&file);
}

char	*ft_strcpy(char *str1)
{
	int		i;
	char	*tmp;


	i = 0;
	if (!str1)
		return (NULL);
	tmp = malloc(ft_strlen(str1) + 1);
	if (!tmp)
		return (NULL);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void malloc_struct(t_file **file, t_cmds **cmds ,int ac)
{
	*cmds = malloc(sizeof(t_cmds) * (ac - 2));
	*file = malloc(sizeof(t_file) * 3);
}
