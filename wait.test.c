/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:41:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/31 15:38:53 by gissao-m         ###   ########.fr       */
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
 
void waitexample()
{
    int stat;
 
    // This status 1 is reported by WEXITSTATUS
    if (fork() == 0)
        exit(1);
    else
        wait(&stat);
    if (WIFEXITED(stat))
        printf("Exit status: %d\n", WEXITSTATUS(stat));
    else if (WIFSIGNALED(stat))
        psignal(WTERMSIG(stat), "Exit signal");
}
 
// Driver code
int main()
{
    waitexample();
    return 0;
}