// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "Timer.generated.h"

UCLASS()
class TESTPROJECT_API ATimer : public AActor
{
	GENERATED_BODY()
	int32 CountdownTime;
	UTextRenderComponent *CountdownText;
	void UpdateTimerDisplay() const;
	void AdvanceTimer();
	void CountdownHasFinished() const;
	FTimerHandle CountdownTimerHandle;

	
public:
	// Sets default values for this actor's properties
	ATimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
