// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMoveComponent.h"
#include "PlayerPawn.h"

// Sets default values for this component's properties
UPlayerMoveComponent::UPlayerMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	myOwner = Cast<APlayerPawn>(GetOwner());
	// ...
	
}


// Called every frame
void UPlayerMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector direction = myOwner->GetActorRightVector() * h + myOwner->GetActorUpVector() * v;
	direction.Normalize();
	// P = P0 + vt
	// 그 방향으로 이동하고싶다.
	FVector p0 = myOwner->GetActorLocation();
	FVector velocity = direction * speed;
	float t = DeltaTime;

	myOwner->SetActorLocation(p0 + velocity * t);
}

void UPlayerMoveComponent::SetupInput(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMoveComponent::OnAxisHorizontal);

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMoveComponent::OnAxisVertical);

}

void UPlayerMoveComponent::OnAxisHorizontal(float value)
{
	h = value;
}

void UPlayerMoveComponent::OnAxisVertical(float value)
{
	v = value;
}