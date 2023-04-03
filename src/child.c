# include "../pipex.h"

int child(int fd_in, int fd_out, char **envp, int n)
{
	char *path;
	if (dup2(fd_in, STDIN_FILENO) == -1)
		printf("ola\n");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		printf("ola\n");
	close(fd_in);
	close(fd_out);
	path = do_comand(*cmds(), get_path(envp), n);
	fprintf(stderr ,"comando -> %s\n", path);
	if (execve(path, cmds()[0][n].cmd, envp) == -1)
		exit(-1);
	return (0);
}