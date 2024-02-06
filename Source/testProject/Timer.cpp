// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"

ATimer::ATimer()
{
	PrimaryActorTick.bCanEverTick = false;
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;
	CountdownTime = 3;
}

void ATimer::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimer::AdvanceTimer, 1.0f, true);
}

void ATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATimer::UpdateTimerDisplay() const
{
	CountdownText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountdownTime, 0))));
}

void ATimer::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ATimer::CountdownHasFinished() const
{
	CountdownText->SetText(FText::FromString(TEXT("GO!")));
}

