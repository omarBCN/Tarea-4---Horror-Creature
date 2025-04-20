// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorC/Public/AICore/AIDataComponent.h"


// Sets default values for this component's properties
UAIDataComponent::UAIDataComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAIDataComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

AActor* UAIDataComponent::GetNextTarget()
{
	if (!TargetsToMoveTo.IsEmpty())
	{
		if (CurrentPatrolIndex != TargetsToMoveTo.Num() -1)
		{
			return TargetsToMoveTo[CurrentPatrolIndex++];
		}
		else
		{
			CurrentPatrolIndex = 0;
			return TargetsToMoveTo.Last();
		}
	}
		
	return nullptr;
}


// Called every frame
void UAIDataComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

