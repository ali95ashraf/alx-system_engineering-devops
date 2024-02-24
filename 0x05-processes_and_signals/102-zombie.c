#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - Infinite loop to keep the program running
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t zombie_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        zombie_pid = fork();
        if (zombie_pid > 0)
        {
            printf("Zombie process created, PID: %d\n", zombie_pid);
            sleep(1); // Sleep to allow parent to print first
        }
        else
        {
            exit(0); // Child exits immediately, becoming a zombie
        }
    }

    infinite_while();

    return (0);
}
