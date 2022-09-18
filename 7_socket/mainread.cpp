#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "publicdef.h"

// first run mainread(this), then run mainwrite

int main()
{   
    int ret = 0;
    // 1.socket
    // if transfer By TCP/UDP, use "AF_INET" instead of "AF_UNIX"
    int listenFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(listenFd < 0)
    {
        std::cout << "create socket error." << std::endl;
        return -1;
    }

    // 2.bind
    struct sockaddr_un srvAddr;
    srvAddr.sun_family = AF_UNIX;
    strncpy(srvAddr.sun_path, DOMAIN, sizeof(srvAddr.sun_path) - 1);
    unlink(DOMAIN);
    ret = bind(listenFd, (struct sockaddr*)&srvAddr, sizeof(srvAddr));
    if(ret < 0)
        return closeFD(listenFd, "bind local sockaddr error.");

    // 3.listen
    ret = listen(listenFd, 1);
    if(ret < 0)
        return closeFD(listenFd, "listen client connect error.");

    // 4.accept
    struct sockaddr_un cltAddr;
    socklen_t cltLen = 0;
    int connectFd = accept(listenFd, (struct sockaddr*)&cltAddr, &cltLen);
    if(connectFd < 0)
        return closeFD(listenFd, "accept client connect error.");

    // 5.read
    char buf[128];
    ret = read(connectFd, buf, 128);
    if (ret > 0)
    {
        std::cout << buf << std::endl;
    }
    return 0;
}

int closeFD(int listenFd, const std::string& msg)
{   
    if (!msg.empty())
        std::cout << msg << std::endl;
    close(listenFd);
    unlink(DOMAIN);
    return -1;
}