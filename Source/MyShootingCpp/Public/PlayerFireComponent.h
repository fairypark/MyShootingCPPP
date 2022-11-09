// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerFireComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSHOOTINGCPP_API UPlayerFireComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerFireComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// BP_Bullet을 담을 포인터변수
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> bulletFactory;

	void OnActionFire(); //선언	

	void SetupInput(class UInputComponent* PlayerInputComponent);

	UPROPERTY(EditAnywhere)
	class USoundBase* fireSound;

};
