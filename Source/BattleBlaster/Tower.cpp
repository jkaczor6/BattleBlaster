// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle FireTimerHandle;
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

bool ATower::IsInFireRange()
{
	bool Result = false;
	if (Tank)
	{
		float DistanceToTank = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		Result = (DistanceToTank <= FireRange);
	}
	return Result;
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsInFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}

}

void ATower::CheckFireCondition()
{
	if (IsInFireRange())
	{
		Fire();
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();

	Destroy();
}