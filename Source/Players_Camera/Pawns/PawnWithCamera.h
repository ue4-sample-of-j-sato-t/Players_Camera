﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnWithCamera.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PLAYERS_CAMERA_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* OurCameraSpringArm;

	UCameraComponent* OurCamera;

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
