// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_2_1_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	UCustomGameInstance(const FObjectInitializer & ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void Init() override;

public: 
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);
};
