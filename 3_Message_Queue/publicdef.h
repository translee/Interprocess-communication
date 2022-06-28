#pragma once

constexpr key_t MSGKEY = 1234;
constexpr long MSGTYPE = 3;

struct MsgGroup
{
    long msgType;
    char text[1024];
};
