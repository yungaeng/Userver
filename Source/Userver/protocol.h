#pragma once

constexpr size_t MAX_CLIENT = 100;
constexpr auto MAX_NAME_LEN = 10;
constexpr auto MAX_CHAT_LEN = 20;
constexpr auto BUFFER_SIZE = 256;

constexpr auto PORT = 9000;

// Ŭ�� �������� (�������� ó��)
constexpr char CS_LOGIN = 0;
constexpr char CS_MOVING = 1;

constexpr char CS_CREATE = 2;
constexpr char CS_JOIN = 3;

// ������ Ŭ�󿡰� (Ŭ�󿡼� ó��)
constexpr char SC_LOGIN_OK = 4;
constexpr char SC_ENTER = 5;
constexpr char SC_MOVE = 6;
constexpr char SC_LEAVE = 7;

constexpr char SC_CREATE = 8;
constexpr char SC_JOIN = 9;

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

#pragma pack(pop)
