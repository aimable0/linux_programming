#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* SIGINT handler */
void handle_sigint(int sig)
{
    printf("\nMonitor Service shutting down safely.\n");
    exit(0);
}

/* SIGUSR1 handler */
void handle_sigusr1(int sig)
{
    printf("\nSystem status requested by administrator.\n");
}

/* SIGTERM handler */
void handle_sigterm(int sig)
{
    printf("\nEmergency shutdown signal received.\n");
    exit(0);
}

int main()
{
    /* Register signal handlers */
    signal(SIGINT, handle_sigint);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGTERM, handle_sigterm);

    printf("Monitor Service started. PID: %d\n", getpid());

    /* Continuous service loop */
    while (1)
    {
        printf("[Monitor Service] System running normally...\n");
        sleep(5);
    }

    return 0;
}

