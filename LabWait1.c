#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int status;
    pid_t pid_L, pid_D;

    pid_L = fork();
    
    if( pid_L == 0 )
    {
        sleep(3);
        printf("Terminé mi ejecución. Soy L. Mi id es: %d. El id de mi padre es: %d\n", getpid(), getppid());
        return 0;

    } else

    {
        pid_D = fork();

        if( pid_D == 0 )
        { 
            sleep(1);
            printf("Terminé mi ejecución. Soy D. Mi id es: %d. El id de mi padre es: %d\n", getpid(), getppid());
            return 0;
        }
    }

    if(pid_L > 0)
    {
        wait(&status);
        printf("Uno de mis hijos terminó su ejecución.\nMi id es: %d\n", getpid());
        return 0;
    }

}
