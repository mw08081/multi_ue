// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM"));
	RootComponent = SM;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	TargetLocation = StartLocation + MovingDirection.GetSafeNormal() * MovingDistance;

	DrawDebugSphere(GetWorld(), StartLocation, 20, 24, FColor::Red, true);
	DrawDebugSphere(GetWorld(), TargetLocation, 20, 24, FColor::Red, true);

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Moving(DeltaTime);
}

void AMovingPlatform::SetIsActivate(bool IsActivate)
{
	bIsActivate = IsActivate;
}

void AMovingPlatform::Moving(float dt)
{
	// 액터의 움직임을 서버와 클라이언트에서 모두하는것이아니고
	// 서버에서 움직이고, 복제(리플리케이션)하여 전달하는 것임
	// 따라서 서버가 아니라면 동작하지 않고, 변경된 사항을 전달받게됨

	// 클라이언트가 단독적으로 업데이트한다면, 서버는 그것을 믿지않고 전달받지도 않음
	if (HasAuthority() == false) return;

	if (bIsActivate) {
		FVector _MovingDirection = (bGoingToTargetLocation) ? (MovingDirection.GetSafeNormal()) : (MovingDirection.GetSafeNormal() * -1);
		CurMovingDistance += (_MovingDirection * MovingSpeed * dt).Size();
		SetActorLocation(GetActorLocation() + _MovingDirection * MovingSpeed * dt);

		if ((GetActorLocation() - StartLocation).Size() >= MovingDistance) {
			FVector tmp = StartLocation;
			StartLocation = TargetLocation;
			TargetLocation = tmp;

			bGoingToTargetLocation = !bGoingToTargetLocation;
		}
	}	
}

