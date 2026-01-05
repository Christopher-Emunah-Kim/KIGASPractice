// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilitySystem/ResourceAtrributeSet.h"
#include "GameplayEffectExtension.h"

UResourceAtrributeSet::UResourceAtrributeSet()
{
	InitMaxHealth(100.f);
	InitHealth(100.f);
	InitMaxMana(100.f);
	InitMana(100.f);
}

void UResourceAtrributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
		
		UE_LOG(LogTemp, Log, TEXT("Health가 변경되었음(%.1f -> %.1f)"), GetHealth(), NewValue);
	}
	
}

void UResourceAtrributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		UE_LOG(LogTemp, Log, TEXT("현재 Health : %.1f"), GetHealth());
		if (GetHealth() <= 0.0f)
		{
			UE_LOG(LogTemp, Log, TEXT("캐릭터 사망"));
			
		}
	}
}

void UResourceAtrributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

