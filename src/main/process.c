/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:55 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/19 18:18:51 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_cmd1(char **argv, char **env, t_data *data)
{
	char	*temp;
	int		i;

	data->infile = open(argv[1], O_RDONLY, 0777);
	if (data->infile < 0)
	{
		perror("Error: vem");
		close(data->infile);
		exit(127);
	}
	dup2(data->fd[1], STDOUT_FILENO);
	dup2(data->infile, STDIN_FILENO);
	close(data->fd[0]);
	data->cmd = matrix_block_cmd(argv[2]);
	data->path = find_the_path(data, env);
	i = 0;
	while (data->cmd[i])
	{
		temp = ft_strtrim(data->cmd[i], "\'");
		free (data->cmd[i]);
		data->cmd[i] = ft_strdup(temp);
		free (temp);
		i++;
	}
	if (execve(data->path, data->cmd, env) == -1)
	{
		perror("Error");
		free(data->path);
		free_matrix(data->cmd);
		free(data);
		exit (127);
	}
}

void	child_process_cmd2(char **argv, char **env, t_data *data)
{
	char	*temp;
	int		i;

	data->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (data->outfile < 0)
	{
		perror("Error: este");
		close(data->outfile);
		exit(127);
	}
	dup2(data->fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->fd[1]);
	data->cmd = matrix_block_cmd(argv[3]);
	data->path = find_the_path(data, env);
	i = 0;
	while (data->cmd[i])
	{
		temp = ft_strtrim(data->cmd[i], "\'");
		free (data->cmd[i]);
		data->cmd[i] = ft_strdup(temp);
		free (temp);
		i++;
	}
	if (execve(data->path, data->cmd, env) == -1)
	{
		perror("Error");
		free(data->path);
		free_matrix(data->cmd);
		free(data);
		exit(127);
	}
}

int	parent_process(int *fd, int pid1, int pid2)
{
	int	wstatus;
	int	status_code;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		return (status_code);
	}
	return (0);
}

//for(int i = 0;data->cmd[i];i++)
// for(int i = 0;data->cmd[i];i++)