// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnInterface.h"
#include "PawnWithCamera.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PLAYERS_CAMERA_API APawnWithCamera : public APawn, public IPawnInterface
{
	GENERATED_BODY()

private:
	// ズームイン中か
	bool bZoomingIn;
	// ズームの因子
	float ZoomFactor;

	// 相対的な移動方向
	FVector2D MovingDirection;

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


	// IPawnInterface
	virtual void MoveDirection(FVector2D Direction) override;
	virtual void MoveCamera(FVector2D CameraDirection) override;
	virtual void ZoomIn() override;
	virtual void ZoomOut() override;

private:
	/**
		ズーム処理
		@note Tickから呼ぶ
	*/
	void Zooming(float DeltaTime);

	/**
		移動処理
	*/
	void Moving(float DeltaTime);
};
