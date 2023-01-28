#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractionInterface : public UInterface
{
    GENERATED_BODY()
};

class JOYWAYTEST_API IInteractionInterface
{
    GENERATED_BODY()

public:
    UFUNCTION()
    virtual void OnGrab(UMotionControllerComponent* MotionControllerComponent) = 0;

    UFUNCTION()
    virtual void OnReleaseGrab() = 0;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
    void OnTriggerPressed();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
    void OnTriggerReleased();
};