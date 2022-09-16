/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:19 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/16 17:23:54 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"
#include <strings.h>
// int main(int argc, char const *argv[], char **envp)
// {
//     char **matriz;
	
//     matriz = malloc(sizeof(char*) * 3);
//     matriz[0] = "ls";
//     matriz[1] = "-l";
//     matriz[2] = NULL;

//     execve("/usr/bin/ls",matriz , envp);
//     return 0;
// }

int	main(int argc, char **argv, char **envp)
{
	t_data *data;
	int	pid1;
	int pid2;
	//process id

	if (argc != 5)
	{
		error_check(argc);
		//talvez fazer uma limpeza de memória, ou aqui, ou antes de eu dar exit
		//na minha func error_check.
	}
	else
	{
		data = malloc (sizeof(t_data) * 1);
		//assim que maloca uma struct!
		bzero(data, sizeof(t_data));
		if (pipe(data->fd) == -1)
			perror("Error: aqui");
			//alem de ser uma checagem de erro, essa condicao faz com que a func pipe ja seja executada.
		pid1 = fork();
		if (pid1 == 0)
			child_process_cmd1(argv, envp, data);        
		pid2 = fork();
		if (pid2 == 0)
			child_process_cmd2(argv, envp, data);
		parent_process(data->fd,pid1, pid2);
	}
	return (0);
}

void    child_process_cmd1(char **argv, char **env, t_data *data)
{
	data->infile = open(argv[1], O_RDONLY, 0777);
	if (data->infile < 0)
		{
			perror("Error: vem");
			close(data->infile);
			exit(127);
		}   
	dup2(data->fd[1], STDOUT_FILENO);
	dprintf(2, "%dfdin\n", data->fd[1]);
	dup2(data->infile, STDIN_FILENO);
	dprintf(2, "%dinfile\n", data->infile);
	close(data->fd[0]);
	data->cmd = matrix_block_cmd(argv[2]);
	data->path = find_the_path(data, env);
	execve(data->path, data->cmd, env);
}

void    child_process_cmd2(char **argv, char **env, t_data *data)
{
	data->outfile = open(argv[4], O_CREAT | O_WRONLY, 0777);
	if (data->outfile < 0)
	{
		perror("Error: este");
		close(data->outfile);
		exit(127);
	}   
	dup2(data->fd[0], STDIN_FILENO);
	dprintf(2, "%dfdout\n", data->fd[0]);
	dup2(data->outfile, STDOUT_FILENO);
	dprintf(2, "%doutfile\n", data->outfile);
	close(data->fd[1]);
	data->cmd = matrix_block_cmd(argv[3]);
	data->path = find_the_path(data, env);
	execve(data->path, data->cmd, env);
}

void    parent_process(int *fd, int pid1, int pid2)
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
		exit(status_code);
	}

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

char    *find_the_path(t_data *data, char **path_env)
{
	int		count;
	char	*path;
	char	*row;
	char	**matrix;
	char	*temp;

	count = 0;
	while (ft_strncmp(path_env[count],"PATH", 4))
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

void	free_matrix(char **s)
{
	int	count;

	count = 0;
	while (s[count] != NULL)
		free(s[count++]);
	free(s);
}

void	invalid_path(char **check, t_data *data)
{
	free_matrix(check);
	write (2, data->cmd[0], ft_strlen(data->cmd[0]));
	write (2, ": command not found\n", 20);
	free_matrix(data->cmd);
	free(data);
}

int     count_find (char *str_cmd)
{
	int     count;
	int     find;
	char    quote;

	count = 0;
	find = 0;
	
	while (str_cmd[count] == ' ')
		count++;
	if ((str_cmd[count] == '\'' || str_cmd[count] == '\"') \
	&& str_cmd[count + 1] != '\0')
		quote = str_cmd[count];
	while (count < ft_strlen(str_cmd))
	{
		if (str_cmd[count] == quote)
			find++;
		count++;
	}
	return (find);
}

char    **matrix_cmd(char *cmd)
{
	char    **matrix;
	int     x;
	int     y;
	
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

// char    **search_cmd(char *cmd)
// {
//     int     count_size;
//     char    **aux;

//     count_size = 0;
//     if (count_find(cmd) % 2 == 0)
//     {
//         while (cmd[count_size] && cmd[count_size] != '\'')
//             count_size++;
//         if (cmd[count_size] && cmd [count_size + 1])
//             count_size++;
//         while (cmd[count_size] && cmd[count_size] != '\'')
//         {
//             if (cmd[count_size] == ' ')
//                 cmd[count_size] = 1;
//             count_size++;
//         }
//     }
//     else
//         write(2, "Error: ", 7);
//     aux = split_cmd(cmd);
//     return (aux);
// }

char    **matrix_block_cmd(char *cmd)
{
	char    **matrix;
	int     count;
	
	count = 0;
	if (count_find(cmd) % 2 != 0)
		write(2, "Error: sera", 7);
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
