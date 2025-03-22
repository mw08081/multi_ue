// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"

#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_2_1_API UCustomGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	UCustomGameInstance(const FObjectInitializer & ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void Init() override;


public:
protected:
private:
	TSubclassOf<class UMainMenu> WBP_MainMenuClass;
	class UMainMenu* MainMenu;


public:
	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);



public:
protected:
private:
	TSubclassOf<class UInGameMenu> WBP_InGameMenuClass;
	class UInGameMenu* InGameMenu;

public:
	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

};
