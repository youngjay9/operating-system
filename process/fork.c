#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t fork_return;
    fork_return = fork();

    if (fork_return < 0)
    {
        fprintf(stderr, "Fork Failed!!");
    }

    /* pid == 0, child process  */
    if (fork_return == 0)
    {
        printf("child process: %d\n", fork_return);
        exit(EXIT_SUCCESS);
    }
    /* pid > 0, parent process */
    else
    {
        printf("parent process: %d\n", fork_return);
        exit(EXIT_SUCCESS);
    }

    return 0;
}