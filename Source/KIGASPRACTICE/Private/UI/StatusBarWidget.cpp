// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StatusBarWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UStatusBarWidget::SetBarColor(FLinearColor color)
{
	BackgroundProgressBar->SetFillColorAndOpacity(color);
}

void UStatusBarWidget::UpdateCurrentValue_Implementation(float inValue)
{
	CurrentValueText->SetText(FText::AsNumber(FMath::RoundToInt(inValue)));
	BackgroundProgressBar->SetPercent(inValue / maxValue);
}

void UStatusBarWidget::UpdateMaxValue_Implementation(float inValue)
{
	MaxValueText->SetText(FText::AsNumber(FMath::RoundToInt(inValue)));
	maxValue = inValue;
}
