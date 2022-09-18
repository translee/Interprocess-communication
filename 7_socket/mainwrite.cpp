#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "publicdef.h"

// first run mainread, then run mainwrite(this)

int main()
{   
    // 1.create client socket
    int connectFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (connectFd < 0)
    {
        std::cout << "create socket error." << std::endl;
        return -1;
    }

    // 2.connect
    struct sockaddr_un srvAddr;
    srvAddr.sun_family = AF_UNIX;
    strncpy(srvAddr.sun_path, DOMAIN, sizeof(srvAddr.sun_path) - 1);
    int ret = connect(connectFd, (struct sockaddr*)&srvAddr, sizeof(srvAddr));
    if(ret == -1)
    {
        std::cout << "connect to server error." << std::endl;
        close(connectFd);
        return -1;
    }
    else 
    {   
        char buf[] = "hello unix domain socket!";
        write(connectFd, &buf, sizeof(buf));
    }

    return 0;
}