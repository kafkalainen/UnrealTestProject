// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireActor.generated.h"

UCLASS()
class TESTPROJECT_API AFireActor : public AActor
{
	GENERATED_BODY()
	static float GetHeightAtLocation(const UWorld *World, float X, float Y);
public:
	AFireActor();
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* ParticleSystemAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystemComponent *ParticleSystemComponent;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void Start();
	void Stop();
};
