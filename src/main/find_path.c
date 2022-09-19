/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:13:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/19 17:19:19 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_the_path(t_data *data, char **path_env)
{
	int		count;
	char	*path;
	char	*row;
	char	**matrix;
	char	*temp;

	count = 0;
	while (ft_strncmp(path_env[count], "PATH", 4))
		count++;
	row = path_env[count] + 5;
	matrix = ft_split(row, ':');
	count = 0;
	while (matrix[count] != 0)
	{
		temp = ft_strjoin(matrix[count], "/");
		path = ft_strjoin(temp, data->cmd[0]);
		free (temp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_matrix(matrix);
			return (path);
		}
		free (path);
		count++;
	}
	invalid_path(matrix, data);
	exit (127);
}

void	invalid_path(char **check, t_data *data)
{
	free_matrix(check);
	write (2, data->cmd[0], ft_strlen(data->cmd[0]));
	write (2, ": command not found\n", 20);
	free_matrix(data->cmd);
	free(data);
}
