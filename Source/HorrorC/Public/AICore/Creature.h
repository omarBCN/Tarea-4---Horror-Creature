// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Creature.generated.h"

class UAIDataComponent;

UCLASS()
class HORRORC_API ACreature : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="AI Data", meta = (AllowPrivateAccess = "true"))
	UAIDataComponent* AIDataComponent;

public:
	ACreature();
	
};
