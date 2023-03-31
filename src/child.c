# include "../pipex.h"

int child(t_cmds *cmds, t_file *file, int n, char **envp)
{
	int fd_2;
	int fd_3;
	char *path;

	if (n == 1)
	{
		file[0].fd = open(file[0].file, O_RDONLY);
		fd_2 = file[0].fd;
		dup2(fd_2, STDIN_FILENO);
		fd_3 = cmds[n].fd[1];
		dup2(fd_3, STDOUT_FILENO);
		/* close(file[0].fd); */
	}
	else if (n > 1 && n < utils()->ac - 3)
	{
		fd_2 = cmds[n].fd[0];
		dup2(fd_2, STDIN_FILENO);
		fd_3 = cmds[n].fd[1];
		dup2(fd_3, STDOUT_FILENO);
	}
	else if (n == utils()->ac - 3)
	{
		file[1].fd = open(file[1].file, O_RDWR);
		fd_2 = cmds[n].fd[0];
		dup2(fd_2, STDIN_FILENO);
		fd_3 = file[1].fd;
		dup2(fd_3, STDOUT_FILENO);
		/* close(file[1].fd); */
	}
	close(cmds[n].fd[0]);
	close(cmds[n].fd[0]);
	path = do_comand(cmds, get_path(envp), n);
	execve(path, &cmds[n].cmd, envp);
	return (0);
}