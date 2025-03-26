// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "MenuInterface.h"
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

void UInGameMenu::GoToGame()
{
	UE_LOG(LogTemp, Display, TEXT("GoToGame"));

	if (MI == nullptr) return;
	MI->GoToGame();
}

void UInGameMenu::GoToLobby()
{
	UE_LOG(LogTemp, Display, TEXT("GoToLobby"));
	if (MI == nullptr) return;
	MI->GoToLobby();
}

void UInGameMenu::QuitGame()
{
	UE_LOG(LogTemp, Display, TEXT("Quit Game"));

	if (MI == nullptr) return;
	MI->QuitGame();
}
