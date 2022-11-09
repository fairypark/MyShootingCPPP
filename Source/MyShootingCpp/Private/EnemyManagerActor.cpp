// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"
#include <Components/ArrowComponent.h>
#include "EnemyActor.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spawnArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("spawnArrow"));

	spawnArrow->SetRelativeRotation(FRotator(-90, 0, 0));
}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &AEnemyManagerActor::MakeEnemy, makeTime, true);
	
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//currentTime += DeltaTime;

	//if (currentTime > makeTime)
	//{
	//	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, spawnArrow->GetComponentTransform());

	//	currentTime = 0;
	//}
}

void AEnemyManagerActor::MakeEnemy()
{
	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, spawnArrow->GetComponentTransform());
}

