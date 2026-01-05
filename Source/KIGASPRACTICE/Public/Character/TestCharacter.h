// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameAbilitySystem/ResourceAtrributeSet.h"
#include "TestCharacter.generated.h"

UCLASS()
class KIGASPRACTICE_API ATestCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATestCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnHealthChanged(const FOnAttributeChangeData& InData);
	void OnManaChanged(const FOnAttributeChangeData& InData);
	
public:	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return abilitySystemComp;
	}
	
	UFUNCTION(BlueprintCallable)
	void TestHealthChange(float amount);
	
private:
	UPROPERTY()
	TObjectPtr<UResourceAtrributeSet> resourceAttributes = nullptr;

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category= "Ability")
	TObjectPtr<UAbilitySystemComponent> abilitySystemComp = nullptr;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category= "UI")
	TObjectPtr<class UWidgetComponent> barWidgetComp = nullptr;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Test")
	float TestValue = 10.f;
	
	
};
