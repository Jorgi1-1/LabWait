#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t pid_A, pid_B, pid_C, pid_D;

    pid_A = fork();
    if (pid_A == 0) 
    {
        waitpid(pid_D, &status, 0);
        printf("A, ID: %d. PID: %d\n", getpid(), getppid());
        execl("/bin/rm", "rm", "-r", "new_folder", NULL);
        pid_D = fork();
        if (pid_D == 0) 
        {
            printf(" D, ID: %d. PID: %d\n", getpid(), getppid());
            execl("/bin/ls", "ls", NULL);
        } 
    }

    pid_B = fork();
    if (pid_B == 0) 
    {
        printf("B, ID: %d PID: %d\n", getpid(), getppid());
        execl("/bin/mkdir", "mkdir", "new_folder", NULL);
    }

    pid_C = fork();
    if (pid_C == 0) {
        printf("C, ID: %d. PID: %d\n", getpid(), getppid());
        execl("/bin/ls", "ls", NULL);
    }

    if (pid_A > 0 && pid_B > 0 && pid_C > 0) {
        waitpid(pid_A, &status, 0);
        printf("M, ID: %d\n", getpid());
        execl("/bin/ls", "ls", NULL);
    }

    return 0;
}
