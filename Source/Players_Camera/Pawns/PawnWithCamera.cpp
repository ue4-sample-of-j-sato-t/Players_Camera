// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnWithCamera.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine.h"

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


	// パラメータ初期化
	ZoomFactor = 0.f;
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

	Zooming(DeltaTime);
}

// Called to bind functionality to input
void APawnWithCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APawnWithCamera::MoveDirection(FVector2D Direction)
{
	// カメラ方向に合わせて回転
	// 速さセット
	// 移動
}

void APawnWithCamera::MoveCamera(FVector2D CameraDirection)
{
}

void APawnWithCamera::ZoomIn()
{
	bZoomingIn = true;
}

void APawnWithCamera::ZoomOut()
{
	bZoomingIn = false;
}

void APawnWithCamera::Zooming(float DeltaTime)
{
	if (bZoomingIn)
	{
		ZoomFactor += DeltaTime / 0.5f;
	}
	else
	{
		ZoomFactor -= DeltaTime / 0.25f;
	}
	ZoomFactor = FMath::Clamp(ZoomFactor, 0.f, 1.f);

	// FOVとスプリングアームを調整
	OurCamera->FieldOfView = FMath::Lerp<float>(90.f, 60.f, ZoomFactor);
	OurCameraSpringArm->TargetArmLength = FMath::Lerp<float>(400.f, 300.f, ZoomFactor);

	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, TEXT("ZoomFactor = ") + FString::SanitizeFloat(ZoomFactor));
}


