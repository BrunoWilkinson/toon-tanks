// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 300.f;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRateMin = 2.f;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRateMax = 3.f;
	FTimerHandle FireRateTimerHandle;
	void CheckFireCondition();
	bool InFireRange();
	class ATank* Tank;
};
