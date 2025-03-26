// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"

void UMenu::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Display, TEXT("Native Destruct()"));

	this->bIsFocusable = true;
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

	UE_LOG(LogTemp, Display, TEXT("Menu: SetMenuInterface"));
	this->MI = MenuInterface;
}

void UMenu::Setup()
{
	UE_LOG(LogTemp, Display, TEXT("Menu: Setup"));

	FInputModeUIOnly UIOnlyInputModeData;
	UIOnlyInputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	UIOnlyInputModeData.SetWidgetToFocus(this->TakeWidget());

	FInputModeGameAndUI MultiInputModeData;
	MultiInputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	MultiInputModeData.SetWidgetToFocus(this->TakeWidget());

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetInputMode(MultiInputModeData);
	PlayerController->bShowMouseCursor = true;
}
