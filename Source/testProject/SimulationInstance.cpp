// Fill out your copyright notice in the Description page of Project Settings.


#include "SimulationInstance.h"
#include "Engine/World.h"
#include "FireActor.h"

void USimulationInstance::StartSimulation()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		const FVector Location(0.0f, 0.0f, 0.0f);
		const FRotator Rotation(0.0f, 0.0f, 0.0f);
		
		FireActor = World->SpawnActor<AFireActor>(AFireActor::StaticClass(), Location, Rotation);
	}
	UE_LOG(LogInit, Display, TEXT("Simulation Started."));
}

void USimulationInstance::OnStart()
{
	StartSimulation();
}
