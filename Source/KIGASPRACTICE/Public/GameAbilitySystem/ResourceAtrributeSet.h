// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ResourceAtrributeSet.generated.h"

/**
 * 
 */
 
//Attribute Getter/Setter/Initter Macro
 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) 
 
UCLASS()
class KIGASPRACTICE_API UResourceAtrributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UResourceAtrributeSet();
	
	//값 검증 및 제한, 순수한 수학적 처리 용도
	/*
	* 새로운 값을 클램핑(clamping) 하거나 조정
	  실제 값 변경 전에 NewValue를 수정 가능
	  GameplayEffect 적용 여부와 무관하게 모든 Attribute 변경에서 호출
	 */
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	//게임 로직 실행, 이벤트 발생, 다른 시스템과의 상호작용 용도
	/*
	* GameplayEffect로 인한 변경사항에 대한 게임 로직 처리
	  데미지 처리, 사망 체크, UI 업데이트 등
	  Data.EvaluatedData를 통해 실제 변경된 값 확인 가능
	 */
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;	
	
	//Attribute값 변경 이후 브로드캐스트나 반응처리
	/*
	* 값 변경에 대한 반응 처리 (리플리케이션 포함)
	  UI 업데이트, 이벤트 브로드캐스트
	  모든 Attribute 변경(SetBaseValue 등 직접 변경 포함)에서 호출
	 */
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "AtrributeSet")
	FGameplayAttributeData Health;
	
	ATTRIBUTE_ACCESSORS(UResourceAtrributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly, Category = "AtrributeSet")
	FGameplayAttributeData MaxHealth;
	
	ATTRIBUTE_ACCESSORS(UResourceAtrributeSet, MaxHealth)
	
	UPROPERTY(BlueprintReadOnly, Category = "AtrributeSet")
	FGameplayAttributeData Mana;
	
	ATTRIBUTE_ACCESSORS(UResourceAtrributeSet, Mana)
	
	UPROPERTY(BlueprintReadOnly, Category = "AtrributeSet")
	FGameplayAttributeData MaxMana;
	
	ATTRIBUTE_ACCESSORS(UResourceAtrributeSet, MaxMana)
	
};
