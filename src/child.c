# include "../pipex.h"

int child(int fd_in, int fd_out, char **envp)
{
	char *path;
	path = do_comand(cmds, get_path(envp), n);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	execve(path, *cmds()[1].cmd, envp);
	return (0);
}