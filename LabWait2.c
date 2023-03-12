#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int status;
    pid_t pid_B, pid_C, pid_E;

    pid_B = fork();
    pid_C = fork();
    pid_E = fork();

    if( pid_B == 0 )
    {
        sleep(3);
        return 1;

    } else 
    
    if( pid_C == 0 )
    {
        sleep(1);
        return 2;
    } else

    if( pid_E == 0 )
    {
        return(3);
    }

    if(pid_B > 0)
    {
        waitpid(pid_B, &status, 0);
        printf("El proceso B terminó con valor de retorno: %d.\n", WEXITSTATUS(status));
        waitpid(pid_C, &status, 0);
        printf("El proceso C terminó con valor de retorno: %d.\n", WEXITSTATUS(status));
        waitpid(pid_E, &status, 0);
        printf("El proceso E terminó con valor de retorno: %d.\n", WEXITSTATUS(status));
    }

}
