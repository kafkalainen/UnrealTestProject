#include "FireActor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/World.h"

AFireActor::AFireActor()
{
	PrimaryActorTick.bCanEverTick = true;
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));
	RootComponent = ParticleSystemComponent;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Script/Engine.ParticleSystem'/Game/Realistic_Starter_VFX_Pack_Vol2/Particles/Fire/P_Fire_Big.P_Fire_Big'"));
	ParticleSystemComponent->SetTemplate(ParticleSystemAsset.Object);
}

void AFireActor::BeginPlay()
{
	Super::BeginPlay();
	Start();
}

void AFireActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFireActor::Start()
{
	const float x = FMath::FRandRange(-1500.0f, 1500.0f);
	const float y = FMath::FRandRange(-1500.0f, 1500.0f);
	const FVector NewLocation = FVector(x, y, GetHeightAtLocation(GetWorld(), x, y));
	SetActorLocation(NewLocation);
	ParticleSystemComponent->ActivateSystem();
}

void AFireActor::Stop()
{
	ParticleSystemComponent->DeactivateSystem();
}

float AFireActor::GetHeightAtLocation(const UWorld *World, const float X, const float Y)
{
	if (!World)
	{
		UE_LOG(LogInit, Warning, TEXT("Oops. No world was loaded."));
		return 0.0f;
	}

	const FVector Start(X, Y, 10000.0f);
	const FVector End(X, Y, -10000.0f);

	FHitResult HitResult;
	if (World->LineTraceSingleByChannel(HitResult, Start, End, ECC_WorldStatic) && HitResult.bBlockingHit)
	{
		UE_LOG(LogInit, Warning, TEXT("HitResult was %f"), HitResult.ImpactPoint.Z);
		return HitResult.ImpactPoint.Z;
	}

	UE_LOG(LogInit, Warning, TEXT("No hits."));
	return 0.0f;
}




