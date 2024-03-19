#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int x = 0;
    pid_t pid = fork();
    if (pid < 0)
        return 1;
    /* fork error */
    if (pid > 0)
    {
        x++;
        printf("[Parent] x: %d (%p)\n", x, &x);
    }
    else
        printf("[Child] x: %d (%p)\n", x, &x);

    return 0;
}
