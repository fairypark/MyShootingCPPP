// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTINGCPP_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Restart;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Quit;

	virtual void NativeConstruct() override;


	UFUNCTION()
	void OnMyRestart();
	UFUNCTION()
	void OnMyQuit();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetAnim), Transient)
		class UWidgetAnimation* AniGameOver;
};
