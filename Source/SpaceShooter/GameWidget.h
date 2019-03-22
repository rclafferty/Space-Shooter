// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Load();

	void SetScore(int score);
	void OnGameOver(int score);
	
	UPROPERTY()
		UTextBlock* ScoreText;
};
