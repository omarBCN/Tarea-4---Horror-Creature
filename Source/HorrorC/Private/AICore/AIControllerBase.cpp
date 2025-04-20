// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorC/Public/AICore/AIControllerBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HorrorC/Public/AICore/AIDataComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"


// Sets default values
AAIControllerBase::AAIControllerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Components Brain (Behavior Tree) & Blackboard Components
	BrainComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior"));
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));

	// PerceptionComponent
	Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));		

	// Sight Config
	UAISenseConfig_Sight* Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(FName("Sight"));
	Sight->SightRadius = 900.f;
	Sight->LoseSightRadius = 1100.f;
	Sight->PeripheralVisionAngleDegrees = 60.f;
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = true;
	Sight->DetectionByAffiliation.bDetectNeutrals = true;
	Sight->SetMaxAge(10.f);
	
	// Hearing Config
	UAISenseConfig_Hearing* Hearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing"));
	Hearing->HearingRange = -1.f;
	Hearing->DetectionByAffiliation.bDetectEnemies = false;
	Hearing->DetectionByAffiliation.bDetectFriendlies = false;
	Hearing->DetectionByAffiliation.bDetectNeutrals = false;
	 
	Perception->ConfigureSense(*Sight);
	Perception->ConfigureSense(*Hearing);
}

// Called when the game starts or when spawned
void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();

	// if (!Perception)
	// 	return;
	//
	// Perception->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::OnCreaturePerceptionUpdated);
	
}

void AAIControllerBase::SetupBehaviorLogic(APawn* InPawn) const
{
	// Inicilización de Behavior tree y Blackboard

	if (const UAIDataComponent* AIDataComponent = InPawn->FindComponentByClass<UAIDataComponent>())
	{
		if (Blackboard && AIDataComponent->GetBlackboardAsset())
		{
			Blackboard->InitializeBlackboard(*AIDataComponent->GetBlackboardAsset());
		}

		if (UBehaviorTreeComponent* BehaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent); BehaviorTreeComponent && AIDataComponent->GetBehaviorTreeAsset())
		{
			BehaviorTreeComponent->StartTree(*AIDataComponent->GetBehaviorTreeAsset());
		}
	}
} 

// void AAIControllerBase::OnCreaturePerceptionUpdated(AActor* Actor, FAIStimulus)
// {
// 	
// }

void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	AttachToPawn(InPawn);

	SetupBehaviorLogic(InPawn);		
}

// Called every frame
void AAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


	
