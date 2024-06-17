// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//지역 변수임
	// FVector LocalVector = MyVector;
	// LocalVector.Z = LocalVector.Z +10;
	// MyVector.Y = MyVector.Y+1;
	// SetActorLocation(LocalVector);



	//이 위는 아래 작성하기 전에 사용했음

	//플랫폼 위치를 옮여야 하기 때문에 슴
		//현재 위치를 가져오고, 로케이션을 가져오며
	FVector CurrentLocation = GetActorLocation();
		//벡터 추가하기
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		//로케이션 설정하기
	SetActorLocation(CurrentLocation);

	
	//플랫폼이 너무 멀리가면 되돌려 보내기
		//얼마나 이동했는지 체크하고
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation); //double값을 반환 값으로 업데이트함
		//너무 멀리 갔으면 반대로 오게 하기
	if(DistanceMoved > MoveDistance)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDirection;
		SetActorLocation(CurrentLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}

