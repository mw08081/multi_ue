// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstance.h"

#include "Engine/Engine.h"

UCustomGameInstance::UCustomGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Display, TEXT("Game Instance Constructor %d"));
}

void UCustomGameInstance::Init()
{
	UE_LOG(LogTemp, Display, TEXT("Game Instance Init"));
}

void UCustomGameInstance::Host()
{
	UEngine* Engine = GetEngine();

	if (Engine == nullptr) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString("Hosting"));

	UWorld* World = GetWorld();
	if (World == nullptr) return;

	World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void UCustomGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString("join"));

	if (Engine == nullptr) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	
	if (PlayerController == nullptr) return;
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

