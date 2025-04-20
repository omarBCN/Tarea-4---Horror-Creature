// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

struct FAIStimulus;

UCLASS()
class HORRORC_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAIControllerBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void SetupBehaviorLogic(APawn* InPawn) const;

	virtual void OnPossess(APawn* InPawn) override;

private:
	// UFUNCTION()
	// void OnCreaturePerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components");
	TObjectPtr<UAIPerceptionComponent> Perception;

	// UPROPERTY()
	// class UAISenseConfig_Sight* Sight;
	//
	// UPROPERTY()
	// class UAISenseConfig_Hearing* Hearing;

	
};

