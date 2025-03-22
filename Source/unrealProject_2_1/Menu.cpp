// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"

void UMenu::NativeConstruct()
{
}

void UMenu::NativeDestruct()
{
	Super::NativeDestruct();
	UE_LOG(LogTemp, Display, TEXT("Native Destruct()"));

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController == nullptr) return;
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
}

void UMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MI = MenuInterface;
}

void UMenu::Setup()
{
}
