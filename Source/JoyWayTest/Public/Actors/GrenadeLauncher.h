// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Gun.h"
#include "GrenadeLauncher.generated.h"

class ASpawnedProjectile;

UCLASS()
class JOYWAYTEST_API AGrenadeLauncher : public AGun
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    TSubclassOf<ASpawnedProjectile> SpawnedProjectileClass;

public:

    UFUNCTION(BlueprintCallable)
    virtual bool FireShot() override;
};
