// #include "ExtinguishFire.h"
//
// AExtinguishFire::AExtinguishFire()
// {
// }
//
// void AExtinguishFire::BeginPlay()
// {
// 	Super::BeginPlay();
// 	
// 	if (!OnFireDied.IsBound())
// 	{
// 		OnFireDied.AddDynamic(this, &AExtinguishFire::FireDied);
// 	}
// }
//
// void AExtinguishFire::FireDied(AFireActor* Fire)
// {
// 	const FVector Location(0.0f, 0.0f, 0.0f);
// 	const FRotator Rotation(0.0f, 0.0f, 0.0f);
// 	GetWorld()->SpawnActor<AFireActor>(AFireActor::StaticClass(), Location, Rotation);
// }