// Fill out your copyright notice in the Description page of Project Settings.

#include "Boss.h"
#include "Projectile.h"

ABoss::ABoss()
{
	SecondTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Second Turret Mesh"));
	SecondTurretMesh->SetupAttachment(BaseMesh);

	ThirdTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Third Turret Mesh"));
	ThirdTurretMesh->SetupAttachment(BaseMesh);

	SecondProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Second Projectile Spawn Point"));
	SecondProjectileSpawnPoint->SetupAttachment(SecondTurretMesh);

	ThirdProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Third Projectile Spawn Point"));
	ThirdProjectileSpawnPoint->SetupAttachment(ThirdTurretMesh);
}

void ABoss::RotateTurret(FVector LookAtTarget)
{
	SetRotationTurret(LookAtTarget, TurretMesh);
	SetRotationTurret(LookAtTarget, SecondTurretMesh);
	SetRotationTurret(LookAtTarget, ThirdTurretMesh);
}

void ABoss::Fire()
{
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
	AProjectile* SecondProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SecondProjectileSpawnPoint->GetComponentLocation(), SecondProjectileSpawnPoint->GetComponentRotation());
	AProjectile* ThirdProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ThirdProjectileSpawnPoint->GetComponentLocation(), ThirdProjectileSpawnPoint->GetComponentRotation());
	if (Projectile && SecondProjectile && ThirdProjectile)
	{
		Projectile->SetOwner(this);
		SecondProjectile->SetOwner(this);
		ThirdProjectile->SetOwner(this);
	}
}

void ABoss::SetRotationTurret(FVector LookAtTarget, UStaticMeshComponent* SelectTurretMesh)
{
	FVector ToTarget = LookAtTarget - SelectTurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	SelectTurretMesh->SetWorldRotation(LookAtRotation);
}