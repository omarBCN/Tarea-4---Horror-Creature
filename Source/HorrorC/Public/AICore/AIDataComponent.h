// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIDataComponent.generated.h"


class UBlackboardData;
class UBehaviorTree;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HORRORC_API UAIDataComponent : public UActorComponent
{
	GENERATED_BODY()

	// Array of Actors where Creature can move to. 
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI Data | Objectives", meta=(AllowPrivateAccess=true))
	TArray<AActor*> TargetsToMoveTo;

	// Behavior Tree
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI Data | Behavior", meta=(AllowPrivateAccess=true))
	TObjectPtr<UBehaviorTree>Behavior;
	
	// BlackBoard
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI Data | Behavior", meta=(AllowPrivateAccess=true))
	TObjectPtr<UBlackboardData>BlackboardData;

public:
	UAIDataComponent();

	FORCEINLINE UBehaviorTree* GetBehaviorTreeAsset() const {return Behavior;} 
	FORCEINLINE UBlackboardData* GetBlackboardAsset() const {return BlackboardData;}

protected:
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)   
	AActor* GetNextTarget();
	 	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:

	uint32 CurrentPatrolIndex = 0;	
};
