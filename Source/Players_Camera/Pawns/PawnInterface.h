// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PLAYERS_CAMERA_API IPawnInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// ポーン移動
	virtual void MoveDirection(FVector2D Direction) = 0;

	// カメラ移動
	virtual void MoveCamera(FVector2D CameraDirection) = 0;

	// ズームイン
	virtual void ZoomIn() = 0;

	// ズームアウト
	virtual void ZoomOut() = 0;
};
