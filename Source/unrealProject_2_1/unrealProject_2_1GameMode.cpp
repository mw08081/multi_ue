// Copyright Epic Games, Inc. All Rights Reserved.

#include "unrealProject_2_1GameMode.h"
#include "unrealProject_2_1Character.h"
#include "UObject/ConstructorHelpers.h"

AunrealProject_2_1GameMode::AunrealProject_2_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
