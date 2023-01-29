// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Item.h"
#include "Components/ArrowComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Gun.generated.h"

/**
 *
 */
UCLASS(Abstract)
class JOYWAYTEST_API AGun : public AItem
{
    GENERATED_BODY()

public:
    AGun();

protected:
    UPROPERTY(EditDefaultsOnly)
    UArrowComponent* ArrowSpawn;

    UPROPERTY(BlueprintReadOnly)
    FTransform ArrowTransform;

    UPROPERTY(EditDefaultsOnly)
    float FiredDamage = 10.0f;

public:
    void OnTriggerPressed_Implementation() override;

    virtual bool FireShot();

    virtual void BeginPlay() override;
};
