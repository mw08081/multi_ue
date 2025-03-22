// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"


#include "Components/Button.h"

void UInGameMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (Btn_Game == nullptr) return;
	Btn_Game->OnClicked.AddDynamic(this, &UInGameMenu::GoToGame);

	if (Btn_Lobby == nullptr) return;
	Btn_Lobby->OnClicked.AddDynamic(this, &UInGameMenu::GoToLobby);

	if (Btn_Quit == nullptr) return;
	Btn_Quit->OnClicked.AddDynamic(this, &UInGameMenu::QuitGame);
}

void UInGameMenu::NativeDestruct()
{
	Super::NativeDestruct();
	UE_LOG(LogTemp, Display, TEXT("Native Destruct()"));

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController == nullptr) return;
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
}

void UInGameMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MI = MenuInterface;
}

void UInGameMenu::Setup()
{
	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetWidgetToFocus(this->TakeWidget());

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController == nullptr) return;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UInGameMenu::GoToGame()
{
	UE_LOG(LogTemp, Display, TEXT("GoToGame"));
}

void UInGameMenu::GoToLobby()
{
	UE_LOG(LogTemp, Display, TEXT("GoToLobby"));
}

void UInGameMenu::QuitGame()
{
	UE_LOG(LogTemp, Display, TEXT("Quit Game"));
}
