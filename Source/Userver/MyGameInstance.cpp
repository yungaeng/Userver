// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Sockets.h"
#include "Common\TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "protocol.h"

void UMyGameInstance::ConnectToServer()
{
	//소켓 만들기
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Srream"), TEXT("Client Socket"));

	// 소켓에 서버 ip 할당
	FIPv4Address ip;
	FIPv4Address::Parse(IPAddr, ip);

	// 포트와 ip를 주소포인터에 할당
	TSharedRef<FInternetAddr> internetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	internetAddr->SetIp(ip.Value);
	internetAddr->SetPort(Port);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connecting to Server..."), true, true, FColor::Red, 5.f);

	// 소켓을 해당 주소로 연결시도 후 결과 반환
	bool isconnect = Socket->Connect(*internetAddr);

	if (isconnect)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connection Success"), true, true, FColor::Blue, 5.f);
		
	}
	else
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connection Failed"), true, true, FColor::Red, 5.f);
}

void UMyGameInstance::DisconnectToServer()
{
	if (Socket)
	{
		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
		SocketSubsystem->DestroySocket(Socket);
		Socket = nullptr;
	}
}

void UMyGameInstance::SendLogin()
{
	FString name = "Unreal Player";
	int32 bytesSent;
	CS_LOGIN_PACKET login_packet{};
	login_packet.size = sizeof(login_packet);
	login_packet.type = CS_LOGIN;
	Socket->Send((uint8*)&login_packet, sizeof(login_packet), bytesSent);
}

void UMyGameInstance::SendCreateSession()
{
	FString name = "Unreal Player";
	int32 bytesSent;
	CS_CREATESESSION_PACKET create_packet{};
	create_packet.size = sizeof(create_packet);
	create_packet.type = CS_CREATE;
	Socket->Send((uint8*)&create_packet, sizeof(create_packet), bytesSent);
}

void UMyGameInstance::SendJoinSession()
{
	FString name = "Unreal Player";
	int32 bytesSent;
	CS_JOINSESSION_PACKET join_packet{};
	join_packet.size = sizeof(join_packet);
	join_packet.type = CS_JOIN;
	Socket->Send((uint8*)&join_packet, sizeof(join_packet), bytesSent);
}
