#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    pid_t pid;
    int fd[2];

    /* create the pipe */
    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    /* now fork a child process */
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    /* parent process */
    if (pid > 0)
    {
        /* close the unused end of the pipe */
        close(fd[READ_END]);

        /* write to the pipe via fd[1]*/
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);

        /* close the write end of the pipe */
        close(fd[WRITE_END]);
    }

    else
    { /* child process */
        /* close the unused end of the pipe */
        close(fd[WRITE_END]);

        /* read from the pipe */
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("child read %s\n", read_msg);

        /* close the write end of the pipe */
        close(fd[READ_END]);
    }

    return 0;
}