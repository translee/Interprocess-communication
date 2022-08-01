#include "publicdef.h"

// first run mainwrite(this), then run mainread in 10s
int main()
{
    int sid = semget(SEMKEY, 1, IPC_CREAT | 0666);
    if (sid < 0)
    {
        std::cout << "create/get semaphore error." << std::endl;
        return -1;
    }
    // init ref-number from 0 to 1
    doSemV(sid);

    // occupy semaphore
    doSemP(sid);
    printCurrentTime();
    std::cout << "get the sem and would release after 10s." << std::endl;
    sleep(10);
    printCurrentTime();
    // release semaphore
    doSemV(sid);
    return 0;
}