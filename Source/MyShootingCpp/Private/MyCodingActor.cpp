// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCodingActor.h"
#include <Components/StaticMeshComponent.h>

// Sets default values
AMyCodingActor::AMyCodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	number = 0;
}

// Called when the game starts or when spawned
void AMyCodingActor::BeginPlay()
{
	Super::BeginPlay();
	 // 객체가 자기자신을 부를때 this라고 부른다.
	
	//반복문
	number = 0;

	TMap<FString, int> b;

	b.Add(TEXT("aaa"), 0);

	UE_LOG(LogTemp, Warning, TEXT("%d"), b[TEXT("aaa")]);

	TArray<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.Add(i+1);
	}
	a.RemoveAt(2);
	UE_LOG(LogTemp, Warning, TEXT("%d"), a[0]);

	// sudo코드(의사코드)
	// number에 0~10까지 반복하면서 짝수만 누적해서 더하세요.
	//for (int i = 0; i < 10; i++)
	//{
	//	// 만약 i를 2로 나눈 나머지가 0이라면
	//	if (i % 2 == 0)
	//	{
	//		// 그값을 number에 누적하고싶다.
	//		number = number + i;
	//	}
	//}
	//// number를 출력해보세요.
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number);

	//int result = PlusPure(10, 30);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), result);

	// 주석 단축키 Ctrl + K+ C   / Ctrl + K + U
	// shift+ctrl + /
	//if (number == 0)// 만약 number가 0이라면
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("안녕"));// "안녕" 을 출력하고싶다.
	//}
	//else if (number >= 1 && number <= 3)// 그렇지 않고 number가 1이상 그리고  number가 3이하라면
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Hello"));// "Hello"를 출력하고싶다.
	//}
	//else // 이도저도 아니라면
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Bye"));// "Bye"를 출력하고싶다.
	//}

	



}

// Called every frame
void AMyCodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCodingActor::NotifyActorBeginOverlap(AActor* OtherActor)
{

}

int AMyCodingActor::PlusCallable(int a, int b)
{
	return a + b;
}
int AMyCodingActor::PlusPure(int a, int b)
{
	return a + b;
}
