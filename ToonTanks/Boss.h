// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "Boss.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ABoss : public ATower
{
	GENERATED_BODY()

public:
	ABoss();

protected:
	virtual void RotateTurret(FVector LookAtTarget) override;
	virtual void Fire() override;

private:
	UPROPERTY(VisibleAnyWhere, BluePrintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Components")
	UStaticMeshComponent* SecondTurretMesh;
	UPROPERTY(VisibleAnyWhere, BluePrintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Components")
	UStaticMeshComponent* ThirdTurretMesh;
	UPROPERTY(VisibleAnyWhere, BluePrintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Components")
	USceneComponent* SecondProjectileSpawnPoint;
	UPROPERTY(VisibleAnyWhere, BluePrintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Components")
	USceneComponent* ThirdProjectileSpawnPoint;
	void SetRotationTurret(FVector LookAtTarget, UStaticMeshComponent* SelectTurretMesh);
};
