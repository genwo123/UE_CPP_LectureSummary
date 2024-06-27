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

	//FVector와 유사한 FString 
	FString Name = GetName();
	//UE_LOG(LogTemp, Display, TEXT("Begin Play : %s"),*Name);
	//UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance : %f"),MoveDistance);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}



void AMovingPlatform::MovePlatform(float DeltaTime){
	

	//지역 변수임
	// FVector LocalVector = MyVector;
	// LocalVector.Z = LocalVector.Z +10;
	// MyVector.Y = MyVector.Y+1;
	// SetActorLocation(LocalVector);



	if(ShouldPlatformReturn())
	{
		//UE_LOG(LogTemp, Display, TEXT("Loging Play : %s"),*Name);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDirection;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void  AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//UE_LOG(LogTemp, Display, TEXT("%s Rotaing..."),*GetName());

	FRotator CurrenRotation = GetActorRotation();
	//CurrenRotation = CurrenRotation +RotationVelocity * DeltaTime;
	//SetActorRotation(CurrenRotation);
	//위 두줄은 로테이션 회전을 시키기에는 오류가 발생할 수 잇는 코드이다. 아래의 코드로 대체됨
	AddActorLocalRotation(RotationVelocity * DeltaTime);
	
}


bool AMovingPlatform::ShouldPlatformReturn() const
{	
	
	return GetDistanceMoved() > MoveDistance; 
}


float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}