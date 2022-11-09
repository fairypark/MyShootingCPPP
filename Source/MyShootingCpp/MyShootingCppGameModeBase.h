// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyShootingCppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTINGCPP_API AMyShootingCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	int score;
	void AddScore(int value);
	UPROPERTY(EditAnywhere)
	int killPoint = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UScoreWidget> scoreWidgetFactory;
	
	class UScoreWidget* scoreWidget;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UGameOverWidget> gameOverWidgetFactory;

	class UGameOverWidget* gameOverWidget;

	void ShowGameOverUI();

	


};
