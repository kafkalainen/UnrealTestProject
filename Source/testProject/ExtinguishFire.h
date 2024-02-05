// // Fill out your copyright notice in the Description page of Project Settings.
//
// #pragma once
//
// #include "CoreMinimal.h"
// #include "FireActor.h"
// #include "GameFramework/GameModeBase.h"
// #include "ExtinguishFire.generated.h"
// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFireDiedSignature, AFireActor*, Fire);
//
// /**
//  * 
//  */
// UCLASS(minimalapi)
// class TESTPROJECT_API AExtinguishFire : public AGameModeBase
// {
// 	GENERATED_BODY()
//
// public:
// 	AExtinguishFire();
// 	const FOnFireDiedSignature& GetOnFireDied() const { return OnFireDied; }
// 	
// protected:
// 	virtual void BeginPlay() override;
//
// 	UFUNCTION()
// 	virtual void FireDied(AFireActor* Fire);
//
// 	UPROPERTY()
// 	FOnFireDiedSignature OnFireDied;
// };
