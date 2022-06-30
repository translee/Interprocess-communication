#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "publicdef.h"

// first run mainwrite(this), then run mainread in 5s
int main()
{
    int msgId = msgget(1234, IPC_CREAT| IPC_EXCL | 0666);
    if (msgId < 0)
    {
        std::cout << "Error. Maybe message queue already exist." << std::endl;
        return -1;
    }
    MsgGroup msg;
    msg.msgType = MSGTYPE;
    strcpy(msg.text, "hello message queue!");
    int ret = msgsnd(msgId, &msg, sizeof(msg.text), IPC_NOWAIT); 
    if (ret < 0)
    {
        std::cout << "send message error." << std::endl;
    }
    else 
    {
        sleep(5);
    }
    ret = msgctl(msgId, IPC_RMID, NULL);
    if (ret < 0)
    {
        std::cout << "close message queue error." << std::endl;
	return -1;
    }
    return 0;
}
