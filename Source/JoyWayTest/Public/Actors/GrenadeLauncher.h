// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Gun.h"
#include "GrenadeLauncher.generated.h"

/**
 *
 */
UCLASS()
class JOYWAYTEST_API AGrenadeLauncher : public AGun
{
    GENERATED_BODY()

public:
    virtual bool FireShot() override;
};
