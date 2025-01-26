// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class USERVER_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void ConnectToServer();

	UFUNCTION(BlueprintCallable)
	void DisconnectToServer();

private:
	UFUNCTION(BlueprintCallable)
	void SendLogin();

	UFUNCTION(BlueprintCallable)
	void SendCreateSession();

	UFUNCTION(BlueprintCallable)
	void SendJoinSession();

public:
	// GameServer
	class FSocket* Socket;
	FString IPAddr = TEXT("127.0.0.1");
	int16 Port = 9000;
	TSharedPtr<class PacketSession> GameServerSession;
};
