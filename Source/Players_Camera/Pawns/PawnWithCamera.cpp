// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnWithCamera.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APawnWithCamera::APawnWithCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ルートコンポーネント
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// バネコンポーネント
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSprintArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	// 初期位置
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 50.f), FRotator(-60.f, 0.f, 0.f));
	// 長さ
	OurCameraSpringArm->TargetArmLength = 400.f;
	// カメラ用設定
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.f;

	// カメラコンポーネント
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	// バネにアタッチ
	OurCamera->SetupAttachment(OurCameraSpringArm);

	// プレイヤー設定
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APawnWithCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnWithCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnWithCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

