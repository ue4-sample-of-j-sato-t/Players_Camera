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
private:

	FVector MoveDirection;


public:
	AMoveWithCameraController();

	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void SetupInputComponent() override;

private:
	UFUNCTION()
	void MoveForward(float AxisValue);

	UFUNCTION()
	void MoveRight(float AxisValue);

	UFUNCTION()
	void PitchCamera(float AxisValue);

	UFUNCTION()
	void YawCamera(float AxisValue);
};
