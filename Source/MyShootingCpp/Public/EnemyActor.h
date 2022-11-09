// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION()
		void OnBox1ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	// 몸을만들고싶다.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// 태어날 때 방향을 정하고싶다. 30% 확률로 플레이어방향, 나머지는 앞방향으로 결정하고싶다.

	// 살아가면서 그 방향으로 이동하고싶다.
	UPROPERTY(EditAnywhere, Category = "Info")
	FVector direction;

	UPROPERTY(EditAnywhere, Category = "Info")
	float speed = 500;

	UPROPERTY(EditAnywhere, Category = "Info")
	float damage = 1;

public:
	// Enemy가 누군가(Bullet, Player)와 부딪히면 폭발하고 싶다.
	
	UPROPERTY(EditAnywhere,  Category = "Info")
	class UParticleSystem* explosionVFXFactory;
	
	void Explosion();

};
