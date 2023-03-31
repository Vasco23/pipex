# include "../pipex.h"

int main(int ac, char **av, char **envp)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (num_of_arguments(ac) == 1)
		return (printf("error\n"));
	malloc_struct(file(), cmds(), ac);
	get_array_of_structs(*file(), *cmds(), ac, av);
	/* do_comand(*cmds(), envp, get_path(envp), 2); */
	while (i < ac - 1)
	{
		fprintf(stderr, "entrou_69\n");
		child_or_parente(forking(*cmds(), j++), envp);
		i++;
	}

	/* if (id == 0)
		"child"
	else if (id > 0)
		"parent"
	else
		"error" */
	return(0);
}

/* void split_cmd(t_cmds *cmds)
{
	int i;

	i = 0;
	while(cmds[i].)
}
 */
t_utils *utils(void)
{
	static t_utils utils;
	return (&utils);
}