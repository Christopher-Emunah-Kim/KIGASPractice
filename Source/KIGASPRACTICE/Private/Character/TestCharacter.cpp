// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TestCharacter.h"
#include "AbilitySystemComponent.h"
#include "Components/WidgetComponent.h"
#include "GameAbilitySystem/StatusAtrributeSet.h"
#include "Interface/TwinBarResource.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	barWidgetComp = CreateDefaultSubobject<UWidgetComponent>("BarWidgetComp");
	barWidgetComp->SetupAttachment(RootComponent);
	
	abilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	statusAttributes = CreateDefaultSubobject<UStatusAtrributeSet>("StatusAttributes");
	
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (abilitySystemComp)
	{
		abilitySystemComp->InitAbilityActorInfo(this, this);
		
		//Attribute값 변경에 대한 델리게이트 
		FOnGameplayAttributeValueChange& onHealthChanged = abilitySystemComp->GetGameplayAttributeValueChangeDelegate(UStatusAtrributeSet::GetHealthAttribute());
		onHealthChanged.AddUObject(this, &ATestCharacter::OnHealthChanged);
	}
	
	if (statusAttributes)
	{
		UUserWidget* barUI = barWidgetComp->GetWidget();
		check(barWidgetComp && barUI);
		
		if (barUI->Implements<UTwinBarResource>())
		{
			ITwinBarResource::Execute_UpdateMaxHealth(barUI, statusAttributes->GetMaxHealth());
			ITwinBarResource::Execute_UpdateCurrentHealth(barUI, statusAttributes->GetHealth());
			ITwinBarResource::Execute_UpdateMaxMana(barUI, statusAttributes->GetMaxMana());
			ITwinBarResource::Execute_UpdateCurrentMana(barUI, statusAttributes->GetMana());
		}
	}
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FString healthString = FString::Printf(TEXT("Health: %.1f / %.1f"), statusAttributes->GetHealth(), statusAttributes->GetMaxHealth());
	DrawDebugString(GetWorld(), GetActorLocation(), healthString, nullptr, FColor::Red, 0, true);
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestCharacter::OnHealthChanged(const FOnAttributeChangeData& InData)
{
	UE_LOG(LogTemp, Warning, TEXT("OnHealthChanged :: Health changed! %.1f -> %.1f"), InData.OldValue, InData.NewValue);
	ITwinBarResource::Execute_UpdateCurrentHealth(barWidgetComp->GetWidget(), statusAttributes->GetHealth());
}

void ATestCharacter::OnManaChanged(const FOnAttributeChangeData& InData)
{
	ITwinBarResource::Execute_UpdateCurrentMana(barWidgetComp->GetWidget(), statusAttributes->GetMana());
}

void ATestCharacter::TestHealthChange(float amount)
{
	if (statusAttributes)
	{
		float currentValue = statusAttributes->GetHealth();
		statusAttributes->SetHealth(currentValue+amount);
	}
}

