/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:23 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/16 13:43:31 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_data
{
    char    **cmd;
    char    *path;
    int     infile;
    int     fd[2];
}   t_data;


void    error_check(int argc);
char    *find_the_path(t_d_fd *d_fd, char **path_env);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);
char    *find_the_path(t_d_fd *d_fd, char **path_env);
void	free_matrix(char **s);
void	invalid_path(char **check, t_d_fd *d_fd);
int     count_find (char *str_cmd);
char    **matrix_cmd(char *cmd);
char    **matrix_block_cmd(char *cmd);
void    parent_process(int *fd, int pid1, int pid2);

#endif