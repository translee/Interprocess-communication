#include "publicdef.h"

// first run mainwrite, then run mainread(this) in 10s
int main()
{
    int sid = semget(SEMKEY, 0, IPC_CREAT | 0666);
    if (sid < 0)
    {
        std::cout << "get semaphore error." << std::endl;
        return -1;
    }

    // occupy semaphore
    doSemP(sid);
    printCurrentTime();
    std::cout << "get the sem and would release after 10s." << std::endl;
    sleep(10);
    printCurrentTime();
    // release semaphore
    doSemV(sid);
    // destory semaphore
    semctl(sid, 0, IPC_RMID);
    return 0;
}