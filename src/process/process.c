/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:55 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/21 11:15:30 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_error(t_data *data, char **env)
{
	if (execve(data->path, data->cmd, env) == -1)
	{
		perror("Error");
		free(data->path);
		free_matrix(data->cmd);
		free(data);
		exit (127);
	}
}

void	child_process_cmd1(char **argv, char **env, t_data *data)
{
	char	*temp;
	int		i;

	data->infile = open(argv[1], O_RDONLY, 0777);
	if (data->infile < 0)
	{
		perror("Error");
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
	execve_error(data, env);
}

void	child_process_cmd2(char **argv, char **env, t_data *data)
{
	char	*temp;
	int		i;

	data->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (data->outfile < 0)
	{
		perror("Error");
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
	execve_error(data, env);
}

void	parent_process(t_data *data, int pid1, int pid2)
{
	int	wstatus;
	int	status_code;

	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		free(data);
		exit (status_code);
	}
}

// void	free_data(t_data *data)
// {
	
// }