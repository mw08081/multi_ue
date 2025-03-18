// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALPROJECT_2_1_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM;


#pragma region Moving
public:
protected:
private:
	UPROPERTY(EditAnywhere)
	bool bIsActivate = true;

	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector MovingDirection;
	UPROPERTY(EditAnywhere, Category = "Moving")
	float MovingDistance = 500;
	UPROPERTY(EditAnywhere, Category = "Moving")
	float MovingSpeed = 100;

	bool bGoingToTargetLocation = true;
	float CurMovingDistance = 0;
	FVector StartLocation;
	FVector TargetLocation;

public:
	void SetIsActivate(bool IsActivate);
protected:
private:

	void Moving(float dt);
#pragma endregion
};
