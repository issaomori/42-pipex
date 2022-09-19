/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:19 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/19 18:06:21 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		pid1;
	int		pid2;

	if (argc != 5)
	{
		error_check(argc);
	}
	else
	{
		if (access(argv[1], F_OK) != 0)
		{	
			perror("Error: NAO EXISTE");
			exit (127);
		}
		data = malloc (sizeof(t_data) * 1);
		ft_bzero(data, sizeof(t_data));
		if (pipe(data->fd) == -1)
			perror("Error: aqui");
		pid1 = fork();
		if (pid1 == 0)
			child_process_cmd1(argv, envp, data);
		pid2 = fork();
		if (pid2 == 0)
			child_process_cmd2(argv, envp, data);
		parent_process(data->fd,pid1, pid2);
		free(data);
	}
	return (0);
}

void	error_check(int argc)
{
	if (argc < 5)
	{
		printf("ERROR\nToo few arguments.\n");
		printf("Try again with: ./pipex <file1> <cmd1> <cmd2> file2\n");
		exit(0);
	}
	if (argc > 5)
	{
		printf("ERROR\nToo many arguments.\n");
		printf("Try again with: ./pipex <file1> <cmd1> <cmd2> file2\n");
		exit(0);
	}
}
