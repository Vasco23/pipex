# include "../inc/pipex.h"

int child(int fd_in, int fd_out, char **envp, int n)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			return (fprintf(stderr ,"error fd0\n"));
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			fprintf(stderr ,"error fd1\n");
		close(fd_in);
		close(fd_out);
	 	utils()->path = do_comand(*cmds(), get_path(envp), n);
		if (execve(utils()->path, cmds()[0][n].cmd, envp) == -1)
		{
			perror("error fds\n");
			return (1);
		}
	}
	close(fd_in);
	close(fd_out);
	return (0);
}
