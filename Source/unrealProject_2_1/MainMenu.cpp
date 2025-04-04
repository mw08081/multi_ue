// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "MenuInterface.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

#include "CustomGameInstance.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Display, TEXT("MainMenu Init!"));

	if (Btn_Host == nullptr) return;
	Btn_Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (Btn_Join == nullptr) return;
	Btn_Join->OnClicked.AddDynamic(this, &UMainMenu::SwitchWidget);

	if (Btn_Join_IP == nullptr) return;
	Btn_Join_IP->OnClicked.AddDynamic(this, &UMainMenu::Join);
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Hosting..."));
	
	if (MI == nullptr)return;
	MI->Host();
}

void UMainMenu::SwitchWidget()
{
	if (WidgetSwitcher == nullptr) return;
	int32 CurWidgetIdx = WidgetSwitcher->GetActiveWidgetIndex();
	
	WidgetSwitcher->SetActiveWidgetIndex(++CurWidgetIdx);
}

void UMainMenu::Join()
{
	if (EditableTxt_IPAddress == nullptr) return;

	FText IPAddress = EditableTxt_IPAddress->GetText();

	UE_LOG(LogTemp, Display, TEXT("IP Addrss : %s"), *IPAddress.ToString());

	if (MI == nullptr) return;
	MI->Join(IPAddress.ToString());
}