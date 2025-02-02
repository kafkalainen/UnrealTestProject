#include "FireActor.h"

#include "Particles/ParticleSystemComponent.h"
#include "Engine/World.h"
#include "Perception/AISense_Sight.h"

AFireActor::AFireActor()
{
	PrimaryActorTick.bCanEverTick = true;
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));
	RootComponent = ParticleSystemComponent;

	// Initialize the AI Perception Stimuli Source Component
	PerceptionStimuliSourceComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("PerceptionStimuliSourceComponent"));

	// Register the actor as a source of stimuli
	PerceptionStimuliSourceComponent->RegisterForSense(UAISense_Sight::StaticClass());
	PerceptionStimuliSourceComponent->RegisterWithPerceptionSystem();
	PerceptionStimuliSourceComponent->bAutoRegister = true;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Script/Engine.ParticleSystem'/Game/Realistic_Starter_VFX_Pack_Vol2/Particles/Fire/P_Fire_Big.P_Fire_Big'"));
	ParticleSystemComponent->SetTemplate(ParticleSystemAsset.Object);

	// Add Fire as tag for the actor for AI perception to spot it.
	Tags.Add(FName("Fire"));

	Health = 0.0f;
	MaxHealth = 300.0f;
	CurrentTime = 0.0f;
	TimeToRespawn = 3.0f;
}

void AFireActor::BeginPlay()
{
	Super::BeginPlay();
	InitialScale = GetActorScale3D();
	Start();
}

void AFireActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsDead())
	{
		return;
	}
	
	if (CurrentTime + DeltaTime < TimeToRespawn)
	{
		CurrentTime += DeltaTime;
		return;
	}

	CurrentTime = 0;
	Start();
}

void AFireActor::Start()
{
	const float x = FMath::FRandRange(-5000.0f, 5000.0f);
	const float y = FMath::FRandRange(-5000.0f, 5000.0f);
	const FVector NewLocation = FVector(x, y, GetHeightAtLocation(GetWorld(), x, y));
	SetActorLocation(NewLocation);
	SetActorScale3D(InitialScale);
	ParticleSystemComponent->ActivateSystem();
	Health = MaxHealth;
	UE_LOG(LogInit, Display, TEXT("Starting health: %f"), Health);
}

void AFireActor::Stop() const
{
	ParticleSystemComponent->DeactivateSystem();
}


void AFireActor::OnExtinguishFire(float Damage)
{
	if (Health <= 0)
	{
		UE_LOG(LogInit, Display, TEXT("Health at zero."));
		return;
	}
	
	Health -= Damage;
	SetActorScale3D(GetActorScale3D() * (Health / MaxHealth));
	UE_LOG(LogInit, Display, TEXT("Current health: %f"), Health);
	if (Health <= 0)
	{
		Health = 0;
		UE_LOG(LogInit, Display, TEXT("Health at zero."));
		Stop();
	}
}

float AFireActor::GetHeightAtLocation(const UWorld *World, const float X, const float Y)
{
	if (!World)
	{
		UE_LOG(LogInit, Warning, TEXT("No world was loaded."));
		return 0.0f;
	}

	const FVector Start(X, Y, 10000.0f);
	const FVector End(X, Y, -10000.0f);

	FHitResult HitResult;
	if (World->LineTraceSingleByChannel(HitResult, Start, End, ECC_WorldStatic) && HitResult.bBlockingHit)
	{
		return HitResult.ImpactPoint.Z;
	}

	return 0.0f;
}

bool AFireActor::IsDead() const
{
	return Health <= 0;
}




