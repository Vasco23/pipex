/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:13:00 by vcacador          #+#    #+#             */
/*   Updated: 2023/06/20 15:17:27 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_cmds
{
	char	**cmd;
	int		fd[2];

}	t_cmds;

typedef struct s_utils
{
	char	*path;
	int		ac;
	int		here_doc;

}	t_utils;

typedef struct s_file
{
	char	*file;
	int		fd;

}	t_file;

t_utils		*utils(void);
t_cmds		**cmds(void);
t_file		**file(void);
int			num_of_arguments(int ac);
void		malloc_struct(t_file **file, t_cmds **cmds, int ac);
void		get_array_of_structs(t_file *file, t_cmds *cmds, int ac, char **av);
char		*ft_strcpy(char *str1);
void		forking(void);
char		*get_path(char **envp);
char		*do_comand(t_cmds *cmds, char *path, int n);
char		*ft_strjoin_2(char const *s1, char const *s2);
int			child_or_parente(char **envp, int n, int j);
int			child(int fd_in, int fd_out, char **envp, int n);
int			here_doc(char **av);
void		free_two_pointers(char **frees);
void		free_all(void);
void		close_fds(void);

#endif