// Fill out your copyright notice in the Description page of Project Settings.


#include "TowersCounter.h"

void UTowersCounter::SetTowersText(FString Message)
{
	FText MessageText = FText::FromString(Message);
	TowersTextBlock->SetText(MessageText);
}