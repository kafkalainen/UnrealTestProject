// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FireActor.h"
#include "Engine/GameInstance.h"
#include "SimulationInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API USimulationInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	AFireActor* FireActor;
public:
	void StartSimulation();
	virtual void OnStart() override;
};
