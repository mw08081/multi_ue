// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_2_1_API UInGameMenu : public UMenu
{
	GENERATED_BODY()

protected:
	//virtual bool Initialize() override;

	virtual void NativeConstruct() override;


	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Game;

	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Lobby;

	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Quit;

public:
	UFUNCTION()
	void GoToGame();
	UFUNCTION()
	void GoToLobby();
	UFUNCTION()
	void QuitGame();
};
