#include "FireActor.h"
#include "Particles/ParticleSystemComponent.h"

AFireActor::AFireActor()
{
	PrimaryActorTick.bCanEverTick = true;
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));
	RootComponent = ParticleSystemComponent;

	ParticleSystemComponent->SetTemplate(ParticleSystemAsset);
}

void AFireActor::BeginPlay()
{
	Super::BeginPlay();
	ParticleSystemComponent->ActivateSystem();
}

void AFireActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

