// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();


protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjetileSpawnPoint;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Super Duper",meta = (AllowPrivateAccess = "true"))
	float State_Health_float = 34.6f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Super Duper", meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt = 12;



};
