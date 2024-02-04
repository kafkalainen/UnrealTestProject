// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireActor.generated.h"

UCLASS()
class TESTPROJECT_API AFireActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFireActor();
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* ParticleSystemAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystemComponent *ParticleSystemComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
