/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:23 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/16 15:58:12 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
    char    **cmd;
    char    *path;
    int     infile;
    int     outfile;
    int     fd[2];
}   t_data;


void    error_check(int argc);
char    *find_the_path(t_data *data, char **env);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);
char    *find_the_path(t_data *data, char **env);
void	free_matrix(char **s);
void	invalid_path(char **check, t_data *data);
int     count_find (char *str_cmd);
char    **matrix_cmd(char *cmd);
char    **matrix_block_cmd(char *cmd);
void    parent_process(int *fd, int pid1, int pid2);
void    child_process_cmd1(char **argv, char **env, t_data *data);
void    child_process_cmd2(char **argv, char **env, t_data *data);
int     ft_strncmp(const char *str1, const char *str2, size_t n);

#endif