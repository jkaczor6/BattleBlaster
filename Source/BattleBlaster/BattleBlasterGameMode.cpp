// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleBlasterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tower.h"

void ABattleBlasterGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Towers);
	TowerCount = Towers.Num();
	UE_LOG(LogTemp, Display, TEXT("TowerCount: %d"), TowerCount);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn)
	{
		Tank = Cast<ATank>(PlayerPawn);
		if (!Tank)
		{
			UE_LOG(LogTemp, Display, TEXT("Cast Failed!"));
		}
	}
	int32 i = 0;
	while (i < TowerCount)
	{
		if (Towers[i])
		{
			ATower* TowerPawn = Cast<ATower>(Towers[i]);
			if (TowerPawn && Tank)
			{
				TowerPawn->Tank = Tank;
				UE_LOG(LogTemp, Display, TEXT("%s: setting the Tank"), *TowerPawn->GetActorNameOrLabel());
			}
		}
		i++;
	}
}
