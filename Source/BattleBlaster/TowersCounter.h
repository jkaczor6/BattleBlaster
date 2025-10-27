// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "TowersCounter.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEBLASTER_API UTowersCounter : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* TowersTextBlock;

	void SetTowersText(FString Message);
};
