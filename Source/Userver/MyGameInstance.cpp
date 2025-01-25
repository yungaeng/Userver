// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Sockets.h"
#include "Common\TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

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