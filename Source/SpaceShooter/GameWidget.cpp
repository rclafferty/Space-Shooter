// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"

void UGameWidget::Load()
{
	const FName TextBlockName = FName(TEXT("GameWidgetTextBlock"));

	// If score text object has not been assigned yet
	if (ScoreText == nullptr)
	{
		// Find the GameTextBlock and assign it to ScoreText
		ScoreText = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
	}
}

void UGameWidget::SetScore(int score)
{
	// if ScoreText isn't null --> has been assigned
	if (ScoreText != nullptr)
	{
		// Create the string to display
		FString toDisplay = FString(TEXT("Score: ")) + FString::FromInt(score);

		// Display the text
		ScoreText->SetText(FText::FromString(toDisplay));
	}
}

void UGameWidget::OnGameOver(int score)
{
	// if ScoreText isn't null --> has been assigned
	if (ScoreText != nullptr)
	{
		// Create the string to display
		FString toDisplay = FString(TEXT("Score: ")) + FString::FromInt(score) + TEXT("\nPress R to restart");

		// Display the text
		ScoreText->SetText(FText::FromString(toDisplay));
	}
}