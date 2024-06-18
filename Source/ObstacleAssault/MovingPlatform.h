// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 이전까지 사용한 코드 삭제 대신 주속으로 처리함
	// UPROPERTY(EditAnywhere)
	// FVector MyVector = FVector(-13700.0,-3100.0,4056);

private:
	//private 추가

	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 500;
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;


	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);


	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
