#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "publicdef.h"

int main()
{
    int shmid = shmget(SHMKEY, MEMSIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        std::cout << "create shared memory error." << std::endl;
        return -1;
    }

    char* addr = reinterpret_cast<char*>(shmat(shmid, nullptr, 0));
    if (addr < 0)
    {
        std::cout << "get shared memory error." << std::endl;
        return -1;
    }

    strcpy(addr, "hello shared memory!");
    sleep(5);

    int ret = shmdt(addr);
    if(ret < 0)
    {
        std::cout << "drop shared memory link error." << std::endl;
        return -1;
    }
    ret = shmctl(shmid, IPC_RMID, nullptr);
    if (ret < 0)
    {
        std::cout << "destroy shared memory error." << std::endl;
        return -1;
    }
    return 0;
}
