// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"
#include <Components/TextBlock.h>
#include "GameOverWidget.h"
#include <Animation/WidgetAnimation.h>

void AMyShootingCppGameModeBase::AddScore(int value)
{
	score += value;

	scoreWidget->txtScore->SetText(FText::AsNumber(score));
}

void AMyShootingCppGameModeBase::BeginPlay()
{
	// scoreWidget 생성해서 화면에 출력한다.

	scoreWidget = CreateWidget< UScoreWidget>(GetWorld(), scoreWidgetFactory);


	scoreWidget->AddToViewport();

	// gameOverWidget 생성만

	gameOverWidget = CreateWidget< UGameOverWidget>(GetWorld(), gameOverWidgetFactory);

	// 마우스 커서 감추기
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

}

void AMyShootingCppGameModeBase::ShowGameOverUI()
{
	gameOverWidget->AddToViewport();

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());



}
