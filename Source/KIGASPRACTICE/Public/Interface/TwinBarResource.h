// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TwinBarResource.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTwinBarResource : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class KIGASPRACTICE_API ITwinBarResource
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Resource")
	void UpdateCurrentHealth(float inValue);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Resource")
	void UpdateMaxHealth(float inValue);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Resource")
	void UpdateCurrentMana(float inValue);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Resource")
	void UpdateMaxMana(float inValue);
	
};
