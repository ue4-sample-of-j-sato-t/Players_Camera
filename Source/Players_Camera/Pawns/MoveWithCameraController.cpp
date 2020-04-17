// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveWithCameraController.h"
#include "Engine.h"

void AMoveWithCameraController::SetupInputComponent()
{
	Super::SetupInputComponent();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("OnSetupInputComponent from controller"));

	if (InputComponent == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("InputComponent is not valid!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("InputComponent is valid"));
	}
}