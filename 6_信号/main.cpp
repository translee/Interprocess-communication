#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{   
    pid_t parentPid = getpid();
    pid_t pid = fork();
    if (pid < 0)
    {
        std::cout << "fork error." << std::endl;
        return -1;
    }
    else if (pid > 0)
    {
        signal(SIGUSR1, [](int signal){
        std::cout << "signal " << signal << " received!" << std::endl;
        });
        wait(nullptr);
    }
    else
    {
        kill(parentPid, SIGUSR1);
    }

    return 0;
}