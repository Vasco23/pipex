# include "../inc/pipex.h"

int main(int ac, char **av, char **envp)
{
	int i;

	i = 0;
	utils()->ac = ac;
	if (num_of_arguments(ac) == 1)
		return (printf("error\n"));
	here_doc(av);
	malloc_struct(file(), cmds(), ac);
	get_array_of_structs(*file(), *cmds(), ac, av);
	forking();
	if (utils()->here_doc == 1)
		i = 1;
	while (i < ac - 3)
	{
		if (child_or_parente(envp, i++, utils()->here_doc) == 1)
			printf("error opening files\n");
	}
	i = 0;
	while (i++ < ac - 3)
		waitpid(-1, NULL, -1);
	free_all();
	return(0);
}

void free_all(void)
{
	int i;
	int j;
	
	i = 0;
	while (i < 2)
		free(file()[0][i++].file);
	i = 0;
	while (i < utils()->ac - 3)
	{
		j = 0;
		while (cmds()[0][i].cmd[j])
			free(cmds()[0][i].cmd[j++]);
		free(cmds()[0][i++].cmd);
	}
	if (*file())
		free(*file());
	if (*cmds())
		free(*cmds());
}

t_utils *utils(void)
{
	static t_utils utils;
	return (&utils);
}

void free_two_pointers(char **frees)
{
	int i;

	i = -1;
	if (!frees)
		return ;
	while(frees[++i])
		free(frees[i]);
	free(frees);
}