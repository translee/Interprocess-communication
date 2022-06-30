#include <iostream>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "publicdef.h"

int main()
{
    int shmid = shmget(SHMKEY, 0, 0666);
    if (shmid < 0)
    {
        std::cout << "find shared memory error." << std::endl;
        return -1;
    }
    
    char* addr = reinterpret_cast<char*>(shmat(shmid, nullptr, 0));
    if (addr < 0)
    {
        std::cout << "get shared memory error." << std::endl;
        return -1;
    }

    char buff[1024];
    memcpy(buff, addr, 1024);
    std::cout << buff << std::endl;

    int ret = shmdt(addr);
    if(ret < 0)
    {
        std::cout << "drop shared memory link error." << std::endl;
        return -1;
    }
    return 0;
}
