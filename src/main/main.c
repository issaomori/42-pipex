/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:19 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/21 11:15:11 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	allow_access(char **argv, char **envp)
{
	t_data	*data;
	int		pid1;
	int		pid2;

	if (access(argv[1], F_OK) != 0)
	{	
		open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		perror("Error");
		exit (1);
	}
	data = malloc (sizeof(t_data) * 1);
	ft_bzero(data, sizeof(t_data));
	if (pipe(data->fd) == -1)
		perror("Error");
	pid1 = fork();
	if (pid1 == 0)
		child_process_cmd1(argv, envp, data);
	pid2 = fork();
	if (pid2 == 0)
		child_process_cmd2(argv, envp, data);
	parent_process(data, pid1, pid2);
	free(data);
}

void	error_check(int argc)
{
	if (argc < 5)
		write(2, "Error\nToo few arguments.\n", 26);
	if (argc > 5)
		write(2, "Error\nToo many arguments.\n", 27);
	write(1, "Try again with: ./pipex <file1> <cmd1> <cmd2> file2\n", 53);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data data;

	data.exit = 0;
	if (argc != 5)
		error_check(argc);
	allow_access(argv, envp);
	return (data.exit);
}
