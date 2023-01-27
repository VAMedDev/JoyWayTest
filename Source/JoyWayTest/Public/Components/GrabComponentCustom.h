#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MotionControllerComponent.h"
#include "GrabComponentCustom.generated.h"

class UMotionControllerComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UGrabComponentCustom : public UActorComponent
{
    GENERATED_BODY()

public:
    UGrabComponentCustom();

    bool IsGrabbed = false;

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    AActor* Owner;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable)
    bool TryGrab(UMotionControllerComponent* MotionControllerComponent);

    UFUNCTION(BlueprintCallable)
    bool TryRelease();
};
