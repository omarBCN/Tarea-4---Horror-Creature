// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorC/Public/AICore/Creature.h"
#include "HorrorC/Public/AICore/AIControllerBase.h"
#include "HorrorC/Public/AICore/AIDataComponent.h" 


ACreature::ACreature()
{
	PrimaryActorTick.bCanEverTick = true;
 
	//Assigns AI Controller
	AIControllerClass = AAIControllerBase::StaticClass();
	
	//Sets AutoPossess mode
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
	// AI Data Component Assign
	AIDataComponent = CreateDefaultSubobject<UAIDataComponent>(TEXT("AIDataComponent"));
}

