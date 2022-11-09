// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>
#include "EnemyActor.h"
#include "../MyShootingCppGameModeBase.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	// boxComp를 Root로 하고싶다.
	RootComponent = boxComp;

	// 충돌처리 case 1 : 직접 세팅
	//boxComp->SetGenerateOverlapEvents(true);
	//boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//boxComp->SetCollisionObjectType(ECC_GameTraceChannel3);
	//boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	//boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);

	// 충돌처리 case 2 : preset을 이용
	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Bullet"));

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::OnBoxComponentBeginOverlap);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 위로 이동하고싶다.
	// P = P0 + vt
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * speed * DeltaTime);
	
}

void ABulletActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//// 만약 부딪힌 상대가 Enemy라면
	//if (OtherActor->IsA(AEnemyActor::StaticClass()))
	//{
	//	// 너죽고 
	//	OtherActor->Destroy();
	//	// 나죽고 하고싶다.
	//	this->Destroy();
	//}
	
	//AEnemyActor* enemy = Cast<AEnemyActor>(OtherActor);
	//if (enemy != nullptr)
	//{

	//}
	
	
}

void ABulletActor::OnBoxComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	// 만약 부딪힌 상대가 Enemy라면
	if (OtherActor->IsA(AEnemyActor::StaticClass()))
	{
		auto enemy = Cast<AEnemyActor>(OtherActor);
		enemy->Explosion();

		// 너죽고 
		OtherActor->Destroy();

		// 나죽고 하고싶다.
		this->Destroy();

		// 1점 증가시키고 싶다.
		// = AddScore를 호출하고 싶다.
		auto gamemode = Cast<AMyShootingCppGameModeBase>(GetWorld()->GetAuthGameMode());

		gamemode->AddScore(gamemode->killPoint);


	}
}

