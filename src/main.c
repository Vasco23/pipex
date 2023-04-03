# include "../pipex.h"

int main(int ac, char **av, char **envp)
{
	int i;

	i = 0;
	utils()->ac = ac;
	/* if (num_of_arguments(ac) == 1)
		return (printf("error\n")); */
	malloc_struct(file(), cmds(), ac);
	get_array_of_structs(*file(), *cmds(), ac, av);
	while (i < ac - 3)
	{
		wait(NULL);
		child_or_parente(envp, i);
		i++;
	}
	i = 0;
	/* while (i++ < ac - 3)
		waitpid(-1, NULL, 0); */
	close(file()[0][0].fd);
	close(file()[0][1].fd);
	fprintf(stderr ,"aqui\n");
	return(0);
}

t_utils *utils(void)
{
	static t_utils utils;
	return (&utils);
}