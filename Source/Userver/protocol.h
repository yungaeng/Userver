#pragma once

constexpr size_t MAX_CLIENT = 100;
constexpr auto MAX_NAME_LEN = 10;
constexpr auto MAX_CHAT_LEN = 20;
constexpr auto BUFFER_SIZE = 256;

constexpr auto PORT = 9000;

// 클라가 서버에게 (서버에서 처리)
constexpr char CS_LOGIN = 0;
constexpr char CS_MOVING = 1;

constexpr char CS_CREATE = 2;
constexpr char CS_JOIN = 3;
constexpr char CS_QUIT = 4;

// 서버가 클라에게 (클라에서 처리)
constexpr char SC_LOGIN_OK = 5;
constexpr char SC_ENTER = 6;
constexpr char SC_MOVE = 7;
constexpr char SC_LEAVE = 8;

constexpr char SC_CREATE = 9;
constexpr char SC_JOIN = 10;
constexpr char SC_QUIT = 11;

#pragma pack(push, 1)

struct CS_LOGIN_PACKET
{
    unsigned char size;
    char type;
    char name[MAX_NAME_LEN];
};

struct CS_MOVING_PACKET
{
    unsigned char size;
    char type;
    char key;
};

struct SC_LOGIN_OK_PACKET
{
    unsigned char size;
    char type;
    short id;
    float loc[3];
    float rot[3];
};

struct SC_ENTER_PACKET
{
    unsigned char size;
    char type;
    short id;
    char name[MAX_NAME_LEN];
    float loc[3];
    float rot[3];
};

struct SC_MOVE_PACKET
{
    unsigned char size;
    char type;
    short id;
    char dir;
};

struct SC_LEAVE_PACKET
{
    unsigned char size;
    char type;
    short id;
};

struct CS_CREATESESSION_PACKET
{
    unsigned char size;
    char type;
    short id;
};

struct SC_CREATESESSION_PACKET
{
    unsigned char size;
    char type;
    short id;
};

struct CS_JOINSESSION_PACKET
{
    unsigned char size;
    char type;
    short id;
};

struct SC_JOINSESSION_PACKET
{
    unsigned char size;
    char type;
    short id;
};

struct CS_QUITSESSION_PACKET
{
    unsigned char size;
    char type;
    short id;
};

struct SC_QUITSESSION_PACKET
{
    unsigned char size;
    char type;
    short id;
};
#pragma pack(pop)
