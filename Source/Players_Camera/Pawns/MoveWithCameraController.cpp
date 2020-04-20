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
	auto PawnInterface = GetPawnInterface();
	if (PawnInterface)
	{
		// 移動呼び出し
		PawnInterface->MoveDirection(MoveDirection);

		// 回転呼び出し
		PawnInterface->MoveCamera(CameraDirection);
	}

	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, TEXT("Move direction -> ") + MoveDirection.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, TEXT("Camera direction -> ") + CameraDirection.ToString());
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
	InputComponent->BindAxis("CameraPitch", this, &AMoveWithCameraController::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AMoveWithCameraController::YawCamera);

	// ズーム
	InputComponent->BindAction("ZoomIn", EInputEvent::IE_Pressed, this, &AMoveWithCameraController::ZoomIn);
	InputComponent->BindAction("ZoomIn", EInputEvent::IE_Released, this, &AMoveWithCameraController::ZoomOut);
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
	CameraDirection.Y = AxisValue;
}

void AMoveWithCameraController::YawCamera(float AxisValue)
{
	CameraDirection.X = AxisValue;
}

void AMoveWithCameraController::ZoomIn()
{
	auto PawnInterface = GetPawnInterface();
	if (PawnInterface)PawnInterface->ZoomIn();
}

void AMoveWithCameraController::ZoomOut()
{
	auto PawnInterface = GetPawnInterface();
	if (PawnInterface)PawnInterface->ZoomOut();
}

IPawnInterface* AMoveWithCameraController::GetPawnInterface()
{
	// あるときはインターフェースを返す
	if (GetPawn<APawn>()->GetClass()->ImplementsInterface(UPawnInterface::StaticClass()))
	{
		return Cast<IPawnInterface>(GetPawn());
	}
	// ないときはnull
	return nullptr;
}
