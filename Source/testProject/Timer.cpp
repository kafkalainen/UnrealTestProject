// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"


// Sets default values
ATimer::ATimer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;
	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ATimer::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimer::AdvanceTimer, 1.0f, true);
}

// Called every frame
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
		//We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ATimer::CountdownHasFinished() const
{
	//Change to a special readout
	CountdownText->SetText(FText::FromString(TEXT("GO!")));
}

