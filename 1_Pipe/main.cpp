#include <iostream>
#include <cstring>
#include <unistd.h>
constexpr int BUFF_SIZE = 1024;

int main()
{
    char buff[BUFF_SIZE];
    int fd[2];  // 0:readFd 1:writeFd
    if (pipe(fd) < 0)
    {
        std::cout << "pipe error" << std::endl;
        return -1;
    }

    pid_t pid = fork();
    if (pid < 0) 
    {   
        std::cout << "fork error" << std::endl;
        return -1;
    } 
    else if (pid > 0) 
    {
        std::cout << "this is parent process" << std::endl;
        close(fd[0]);
        const char* message = "hello pipe\n";
        write(fd[1], message, strlen(message));
    }
    else 
    {   
        std::cout << "this is child process" << std::endl;
        close(fd[1]);
        ssize_t len = read(fd[0], buff, BUFF_SIZE);
        for (ssize_t i = 0; i < len; i++)
            std::cout << buff[i];
    }
    return 0;
}
