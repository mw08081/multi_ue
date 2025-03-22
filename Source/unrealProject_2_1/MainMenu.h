// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"


#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_2_1_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	//virtual bool Initialize() override;

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	void SetMenuInterface(class IMenuInterface* MenuInterface);
	void Setup();
protected:
private:
	class  IMenuInterface* MI;

	
private:
	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Host;

	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Join;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* WidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* EditableTxt_IPAddress;

	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Join_IP;

public:
	UFUNCTION()
	void HostServer();
	UFUNCTION()
	void SwitchWidget();
	UFUNCTION()
	void Join();
};
