// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMoveComponent.generated.h"

class APlayerPawn;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSHOOTINGCPP_API UPlayerMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupInput(class UInputComponent* PlayerInputComponent);

	class APlayerPawn* myOwner;

	float h;
	float v;
	float speed = 500;
	void OnAxisHorizontal(float value);
	void OnAxisVertical(float value);
};
