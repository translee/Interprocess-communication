#include <iostream>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
 
// first run mainWrite(this), then run mainRead
int main()
{
    int ret = mkfifo("my_fifo", 0666);
    if(ret != 0)
    {
        std::cout << "filo create error." << std::endl;
        return -1;
    }
    
    int fd = open("my_fifo", O_WRONLY);
    if(fd < 0)
    {
        std::cout << "open fifo error." << std::endl;
        return -1;
    }

    sleep(3);
    const char* message = "hello fifo!";
    ssize_t len = write(fd, message, strlen(message));
    if (len < 0)
    {
        std::cout << "write to fifo error." << std::endl;
        return -1;
    }
    
    close(fd);
    int unlinkRet = unlink("my_fifo");
    if (unlinkRet < 0)
    {
        std::cout << "close my_fifo error." << std::endl;
        return -1;
    }
    return 0;
}
