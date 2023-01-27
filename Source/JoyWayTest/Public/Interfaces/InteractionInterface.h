#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI)
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
    virtual void OnRelease() = 0;

    UFUNCTION()
    virtual void OnTrigger() = 0;

    // #TODO: заготовки под вызываемые в BP функции
    //  UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
    //  void OnGrab();
    //  void OnGrab_Implementation();

    // UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    // void OnTrigger();
    // void OnTrigger_Implementation();
};