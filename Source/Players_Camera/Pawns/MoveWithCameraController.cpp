// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveWithCameraController.h"
#include "Engine.h"

AMoveWithCameraController::AMoveWithCameraController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMoveWithCameraController::Tick(float DeltaTime)
{
	MoveDirection.Normalize();
	// 移動呼び出し

	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, TEXT("Move direction -> ") + MoveDirection.ToString());
}

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

	// 移動
	InputComponent->BindAxis("MoveForward", this, &AMoveWithCameraController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMoveWithCameraController::MoveRight);

	// カメラ
	InputComponent->BindAxis("PitchCamera", this, &AMoveWithCameraController::PitchCamera);
	InputComponent->BindAxis("YawCamera", this, &AMoveWithCameraController::YawCamera);
}

void AMoveWithCameraController::MoveForward(float AxisValue)
{
	MoveDirection.X = AxisValue;
}

void AMoveWithCameraController::MoveRight(float AxisValue)
{
	MoveDirection.Y = AxisValue;
}

void AMoveWithCameraController::PitchCamera(float AxisValue)
{
	// カメラピッチ呼び出し
}

void AMoveWithCameraController::YawCamera(float AxisValue)
{
	// カメラヨー呼び出し
}
