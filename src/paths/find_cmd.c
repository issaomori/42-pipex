/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:12:31 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/20 13:54:18 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_find(char *str_cmd)
{
	int		count;
	int		find;

	count = 0;
	find = 0;
	while (str_cmd[count] == ' ')
		count++;
	while (count < ft_strlen(str_cmd))
	{
		if (str_cmd[count] == '\'')
			find++;
		count++;
	}
	return (find);
}

char	**matrix_cmd(char *cmd)
{
	char	**matrix;
	int		x;
	int		y;

	x = 0;
	y = 0;
	matrix = ft_split(cmd, ' ');
	while (matrix[y] != NULL)
	{
		x = 0;
		while (matrix[y][x] && matrix[y][x] != '\'')
			x++;
		if (matrix[y][x] && matrix[y][x + 1])
			x++;
		while (matrix[y][x] && matrix[y][x] != '\'')
		{
			if (matrix[y][x] == 1)
				matrix[y][x] = ' ';
			x++;
		}
		y++;
	}
	return (matrix);
}

char	**matrix_block_cmd(char *cmd)
{
	char	**matrix;
	int		count;

	count = 0;
	if (count_find(cmd) % 2 != 0)
		write(2, "Error:", 7);
	else
	{
		while (cmd[count] && cmd[count] != '\'')
			count++;
		if (cmd[count] == '\'' && cmd[count + 1])
			count++;
		while (cmd[count] && cmd[count] != '\'')
		{
			if (cmd[count] == ' ')
				cmd[count] = 1;
			count++;
		}
	}
	matrix = matrix_cmd(cmd);
	return (matrix);
}
