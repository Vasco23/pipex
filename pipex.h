#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_cmds
{
	char 	**cmd;
	int		fd[2];
}	t_cmds;

typedef struct s_utils
{
	int 	ac;
}	t_utils;


typedef struct s_file
{
	char 	*file;
	int 	fd;

}	t_file;

t_utils 		*utils(void);
t_cmds  		**cmds(void);
t_file  		**file(void);
int 			num_of_arguments(int ac);
void 			malloc_struct(t_file **file, t_cmds **cmds ,int ac);
void 			get_array_of_structs(t_file *file, t_cmds *cmds, int ac, char **av);
char			*ft_strcpy(char *str1);
int 			forking(int n);
char 			*get_path(char **envp);
char 			*do_comand(t_cmds *cmds, char *path, int n);
char			*ft_strjoin_2(char const *s1, char const *s2);
int				child_or_parente(char **envp, int n, int id);
int 			child(int fd_in, int fd_out, char **envp, int n);

#endif