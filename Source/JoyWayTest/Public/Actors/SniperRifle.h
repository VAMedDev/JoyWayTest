// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Gun.h"
#include "SniperRifle.generated.h"

/**
 *
 */
UCLASS()
class JOYWAYTEST_API ASniperRifle : public AGun
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FVector DistanceOfShot{1500.0f};

public:
    virtual bool FireShot() override;
};
