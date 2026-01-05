// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interface/ResourceInterface.h"
#include "StatusBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class KIGASPRACTICE_API UStatusBarWidget : public UUserWidget, public IResourceInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetBarColor(FLinearColor color);
	
	virtual void UpdateCurrentValue_Implementation(float inValue) override;
	virtual void UpdateMaxValue_Implementation(float inValue) override;
	
private:
	float maxValue = 1.f;
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> BackgroundProgressBar = nullptr;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> CurrentValueText = nullptr;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> MaxValueText = nullptr;
	
};
