// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "FireActor.generated.h"

UCLASS()
class TESTPROJECT_API AFireActor : public AActor
{
	GENERATED_BODY()
	static float GetHeightAtLocation(const UWorld *World, float X, float Y);
	float Health;
	float MaxHealth;
	float CurrentTime;
	float TimeToRespawn;
	FVector InitialScale;
	
public:
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* ParticleSystemAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystemComponent *ParticleSystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "AI")
	UAIPerceptionStimuliSourceComponent* PerceptionStimuliSourceComponent;

	AFireActor();
	
	UFUNCTION(BlueprintCallable)
	bool IsDead() const;

	UFUNCTION(BlueprintCallable)
	void OnExtinguishFire(float Damage);
	
protected:
	virtual void BeginPlay() override;
	// virtual void Destroyed();

public:
	virtual void Tick(float DeltaTime) override;
	void Start();
	void Stop() const;
};
