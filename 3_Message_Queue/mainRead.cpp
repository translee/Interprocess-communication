#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "publicdef.h"

// first run mainwrite, then run mainread(this) in 5s
int main()
{
    int msgId = msgget(MSGKEY, 0666);
    if (msgId < 0)
    {
        std::cout << "get message queue error." << std::endl;
        return -1;
    }
    MsgGroup msg;
    int ret = msgrcv(msgId, &msg, sizeof(msg.text), MSGTYPE, 0);
    if (ret < 0)
    {
        std::cout << "receive message error." << std::endl;
        return -1;
    }
    else 
    {
        std::cout << msg.text << std::endl;
    }
    return 0;
}
