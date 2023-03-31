# include "../pipex.h"

int child(t_cmds *cmds, t_file *file, int n, char **envp)
{
	int fd_2;
	/* int fd_3; */
	char *path;
	path = do_comand(cmds, get_path(envp), n);
	if (n == 0)
	{
		/* path = do_comand(cmds, get_path(envp), n); */
		fprintf(stderr, "entrou_2\n");
		file[0].fd = open(file[0].file, O_RDONLY);
		fd_2 = file[0].fd;
		dup2(fd_2, 0);
		fd_2 = cmds[n].fd[1];
		dup2(fd_2, 1);
		/* close(cmds[n].fd[0]);
		close(cmds[n].fd[1]);
		execve(path, cmds[n].cmd, envp); */
	}
	/* if (n > 0 && n < utils()->ac - 4)
	{
		printf("entrou_5\n");
		fd_2 = cmds[n - 1].fd[0];
		dup2(fd_2, STDIN_FILENO);
		fd_2 = cmds[n - 1].fd[1];
		dup2(fd_2, STDOUT_FILENO);
	} */
	if (n == 1)
	{
		printf("entrou_4\n");
		file[1].fd = open(file[1].file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		fd_2 = cmds[n].fd[0];
		dup2(fd_2, STDIN_FILENO);
		fd_2 = file[1].fd;
		dup2(fd_2, STDOUT_FILENO);
		/* close(file[1].fd); */
	}
	fprintf(stderr, "entrou_3\n");
	close(cmds[n].fd[1]);
	close(cmds[n].fd[0]);
	fprintf(stderr, "path -> %s\n", path);
	execve(path, cmds[n].cmd, envp);
	return (0);
}