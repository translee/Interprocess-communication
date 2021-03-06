#include <iostream>
#include <unistd.h>
#include <fcntl.h>
constexpr int BUFF_SIZE = 1024;

// first run mainwrite, then run mainread(this)
int main()
{   
    int fd = open("my_fifo", O_RDONLY);
    if (fd < 0)
    {
        std::cout << "open fifo error." << std::endl;
        return -1;
    }
    char buff[BUFF_SIZE];
    ssize_t len = read(fd, buff, BUFF_SIZE);
    for (ssize_t i = 0; i < len; i++)
            std::cout << buff[i];
    std::cout << std::endl;
    close(fd);
    return 0;
}

