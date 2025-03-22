// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstance.h"

#include "Engine/Engine.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.h"
#include "InGameMenu.h"

UCustomGameInstance::UCustomGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Display, TEXT("Game Instance Constructor"));

	ConstructorHelpers::FClassFinder<UMainMenu> WBP_MainMenu(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (WBP_MainMenu.Class == nullptr) return;

	WBP_MainMenuClass = WBP_MainMenu.Class;

	ConstructorHelpers::FClassFinder<UInGameMenu> WBP_InGameMenu(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	if (WBP_InGameMenu.Class == nullptr) return;

	WBP_InGameMenuClass = WBP_InGameMenu.Class;
}

void UCustomGameInstance::Init()
{
	UE_LOG(LogTemp, Display, TEXT("Game Instance Init, Found Class MainMenu Class %s"), *WBP_MainMenuClass->GetName());
	UE_LOG(LogTemp, Display, TEXT("++				   Found Class InGameMenu Class %s"), *WBP_InGameMenuClass->GetName());

}

void UCustomGameInstance::LoadMenu()
{
	if (WBP_MainMenuClass == nullptr) return;
	MainMenu = CreateWidget<UMainMenu>(this, WBP_MainMenuClass);

	if (MainMenu == nullptr) return;
	MainMenu->AddToViewport();
	MainMenu->SetMenuInterface(this);
	MainMenu->Setup();
}

void UCustomGameInstance::Host()
{
	if (MainMenu != nullptr) {
		MainMenu->RemoveFromParent();
	}

	UEngine* Engine = GetEngine();

	if (Engine == nullptr) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString("Hosting"));

	UWorld* World = GetWorld();
	if (World == nullptr) return;

	World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void UCustomGameInstance::Join(const FString& Address)
{
	if (MainMenu != nullptr) {
		MainMenu->RemoveFromParent();
	}

	UEngine* Engine = GetEngine();

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString("join"));

	if (Engine == nullptr) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	
	if (PlayerController == nullptr) return;
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UCustomGameInstance::LoadInGameMenu()
{
	if (WBP_InGameMenuClass == nullptr) return;
	InGameMenu = CreateWidget<UInGameMenu>(this, WBP_InGameMenuClass);

	if (InGameMenu == nullptr) return;
	InGameMenu->AddToViewport();
	InGameMenu->SetMenuInterface(this);
	InGameMenu->Setup();
}

