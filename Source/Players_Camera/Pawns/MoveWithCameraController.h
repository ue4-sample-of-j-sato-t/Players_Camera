// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MoveWithCameraController.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERS_CAMERA_API AMoveWithCameraController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
};
