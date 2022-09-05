/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:19 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/02 12:50:14 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
	int	fd[2];
	int	pid1;

    if (argc != 5)
    {
        error_check(argc);
        //talvez fazer uma limpeza de memória, ou aqui, ou antes de eu dar exit
        //na minha func error_check.
    }
    else
    {
        
    }
    
}

void    error_check(int argc)
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
