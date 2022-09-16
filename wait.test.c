/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:41:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/09/06 13:05:53 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include<sys/wait.h>
// #include<unistd.h>
 
// int main()
// {
//     if (fork()== 0)
//         printf("HC: hello from child\n");
//     else
//     {
//         printf("HP: hello from parent\n");
//         wait(NULL);
//         printf("CT: child has terminated\n");
//     }
 
//     printf("Bye\n");
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

// void waitexample()
// {
//     int stat;
 
//     // This status 1 is reported by WEXITSTATUS
//     if (fork() == 0)
//         exit(1);
//     else
//         wait(&stat);
//     if (WIFEXITED(stat))
//         printf("Exit status: %d\n", WEXITSTATUS(stat));
//     else if (WIFSIGNALED(stat))
//         psignal(WTERMSIG(stat), "Exit signal");
// }
 
// // Driver code
// int main()
// {
//     waitexample();
//     return 0;
// }


// void    pipex(int f1, int f2)
// {
//     int   end[2];
//     pid_t parent;
//     pipe(end);
//     parent = fork();
//     if (parent < 0)
//          return (perror("Fork: "));
//     if (!parent) // if fork() returns 0, we are in the child process
//         child_process(f1, cmd1);
//     else
//         parent_process(f2, cmd2);
// }

// void    pipex(int f1, int f2)
// {
//     int end[2];
//     pipe(end);
// }

// int main(int ac, char **ag, char **envp)
// {
//      int f1;
//      int f2;
//      f1 = open(ag[1], O_RDONLY);
//      f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
//      if (f1 < 0 || f2 < 0)
//           return (-1);
//      pipex(f1, f2);
//      return (0);
// }

// int	main(int argc, char* argv[])
// {
// 	int pid1 = fork();

// 	if (pid1 == -1)
// 	{
// 		printf("error creating process\n");
// 		return (1);
// 	}

// 	if (pid1 == 0)
// 	{
// 		sleep(4);
// 		printf("PAIfinished execution %d\n", getpid());
// 		return (0);
// 	}
	
// 	int pid2 = fork();
// 	if (pid1 == -1)
// 	{
// 		printf("error creating process\n");
// 		return (2);
// 	}
// 	if (pid2 == 0)
// 	{
// 		sleep(1);
// 		printf("FILHOfinished execution %d\n", getpid());
// 	}
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);

// 	return (0);

// }

// int main(void) 
// {
//   printf("Main program started\n");
//   char* argv[] = { "jim", "jams", NULL };
//   char* envp[] = { "some", "environment", NULL };
//   if (execve("./test.exe", argv, envp) == -1)
//     perror("Could not execve");
// 	printf("Hallo?");
//   return 1;
// }


// int	main(int argc, char* argv[])
// {
// 	char cmd[] = "/bin/ls -l";
// 	char *arg_vec[] = {"ls", NULL};
// 	char *en_vec[] = {NULL};


// 	printf("start of execve call %s: \n", cmd);
// 	printf("---------------------\n");
// 	if (execve(cmd, arg_vec, en_vec) != -1)
// 	{
// 		printf("couldnt execute");
// 	}
// 	printf( "Hello world\n");
// 	return (0);

// }

// int	main(int argc, char* argv[])
// {
// 	int id = fork();
// 	if (id == 0)
// 	{
//         printf("OLAFILHO\n");
// 		printf("child\n");
// 	}
// 	else
// 	{
// 		fork();
// 	}
// 	printf( "Hello world %d\n", id);
// 	return (0);

// }

// int	main(int argc, char* argv[])
// {
// 	int fd[2];
	
// 	if (pipe(fd) == -1)
// 	{
// 		printf("pipe error\n");
// 		return (1);
// 	}
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		int x;
// 		printf("Input a number: ");
// 		scanf("%d", &x);
// 		write(fd[1], &x, sizeof(int));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		close(fd[1]);
// 		int y;
// 		read(fd[0], &y, sizeof(int));
// 		close(fd[0]);
// 		printf("y: %d\n", y);
// 	}
	
// 	return (0);
// }

// int	main(int argc, char* argv[])
// {
// 	int fd[2];

// 	if (pipe(fd) == -1)
// 	{
// 		return (1);
// 	}
// 	int pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		return (2);
// 	}
	
// 	if (pid1 == 0) // child (ping)
// 	{
// 		//char *argv[] = {"/bin/ls", NULL};
// 		char *argv[] = {"ping", "-c", "5", "google.com", NULL};
// 		char *envp[] = {NULL};
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 		execve("/sbin/ping", argv, envp);
// 	}

// 	int pid2 = fork();
// 	if (pid2 == -1)
// 	{
// 		return (3);
// 	}
// 	if (pid2 == 0) // child process 2 (grep)
// 	{
// 		char *argv[] = {"grep", "statistics", NULL};
// 		char *envp[] = {NULL};
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execve("/usr/bin/grep", argv, envp);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }

