#pragma once
#include <iostream>
#include <sys/sem.h>
#include <sys/time.h>
#include <unistd.h>
constexpr key_t SEMKEY = 1236;

int doSem(int sid, int val)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = val;
    sem_b.sem_flg = SEM_UNDO;
    return semop(sid, &sem_b, 1);
}

void doSemP(int sid)
{   
    if (doSem(sid, -1) < 0)
    {
        std::cout << "P operator error." << std::endl;
    }
    return;
}

void doSemV(int sid)
{
    if (doSem(sid, 1) < 0)
    {
        std::cout << "P operator error." << std::endl;
    }
    return;
}

void printCurrentTime()
{
    time_t tNow = -1;
    time(&tNow);
    if (tNow < 0)
    {
        std::cout << "get time error." << std::endl;
        return;
    }
    struct tm tmNow;
    localtime_r(&tNow, &tmNow);
    std::cout << tmNow.tm_mon << "月" << tmNow.tm_mday << "日" << 
        tmNow.tm_hour << ":" << tmNow.tm_min << ":" << tmNow.tm_sec 
        << std::endl;
    return;
}