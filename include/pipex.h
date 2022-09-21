/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:23 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/20 17:37:22 by gissao-m         ###   ########.fr       */
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
	char	**cmd;
	char	*path;
	int		infile;
	int		outfile;
	int		fd[2];
	int		exit;
}	t_data;

void	error_check(int argc);
char	*find_the_path(t_data *data, char **env);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*find_the_path(t_data *data, char **env);
void	free_matrix(char **s);
void	invalid_path(char **check, t_data *data);
int		count_find(char *str_cmd);
char	**matrix_cmd(char *cmd);
char	**matrix_block_cmd(char *cmd);
void	parent_process(int *fd, int pid1, int pid2);
void	child_process_cmd1(char **argv, char **env, t_data *data);
void	child_process_cmd2(char **argv, char **env, t_data *data);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *p, int ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t d_size);
char	*ft_strdup(const char *src);
void	ft_bzero(void *str, size_t n);
void	allow_access(char **argv, char **envp);

#endif