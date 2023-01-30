#pragma once

#include "CoreMinimal.h"
#include "Actors/Gun.h"
#include "SniperRifle.generated.h"

UCLASS()
class JOYWAYTEST_API ASniperRifle : public AGun
{
    GENERATED_BODY()

protected:


public:
    UFUNCTION(BlueprintCallable)
    virtual bool FireShot() override;
};
