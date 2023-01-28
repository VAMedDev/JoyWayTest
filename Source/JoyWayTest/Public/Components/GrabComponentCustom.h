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

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    AActor* Owner;

    // whether this item is taken right now
    bool IsGrabbed = false;

    // whether if can we grab that item in general
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
    bool IsGrababble = true;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable)
    bool TryGrab(UMotionControllerComponent* MotionControllerComponent);

    UFUNCTION(BlueprintCallable)
    bool TryRelease();

    bool GetIsGrabbed() { return IsGrabbed; };
    void SetIsGrabbed(bool InIsGrabbed) { IsGrabbed = InIsGrabbed; };
    bool GetIsGrababble() { return IsGrababble; };
    void SetIsGrababble(bool InIsGrabbable) { IsGrababble = InIsGrabbable; };
};
