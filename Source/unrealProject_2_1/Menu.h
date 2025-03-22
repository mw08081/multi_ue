// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_2_1_API UMenu : public UUserWidget
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
	class  IMenuInterface* MI;
private:
};
