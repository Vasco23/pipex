# include "../inc/pipex.h"

int here_doc(char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[2]) > 0)
		utils()->here_doc = 1;
	else
		return (1);
	return (0);
}

