#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "ForkFailed");
    }
    /* child process */
    else if (pid == 0)
    {
        printf("child process: %d\n", pid);
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        printf("parent process: %d\n", pid);
        /* parent wait for the child to complete*/
        wait(NULL);
        printf("child process complete");
    }

    printf("PARENT: value = %d\n", 5); /* LINE A */

    return 0;
}