#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Interfaces/InteractionInterface.h"
#include "Components/GrabComponentCustom.h"
#include "Item.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract)
class JOYWAYTEST_API AItem : public AActor, public IInteractionInterface
{
    GENERATED_BODY()

public:
    AItem();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Static Mesh")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    UGrabComponentCustom* GrabComponentCustom;

    UPROPERTY(BlueprintReadOnly, Category = "Components")
    APawn* ItemOwner;

    virtual void OnGrab(UMotionControllerComponent* MotionControllerComponent) override;
    virtual void OnReleaseGrab() override;
    void OnTriggerPressed_Implementation() override;
    void OnTriggerReleased_Implementation() override;

public:
    virtual void Tick(float DeltaTime) override;

    bool SetStaticMesh(UStaticMeshComponent* InNewStaticMesh)
    {
        StaticMesh = InNewStaticMesh;
        if (!IsValid(StaticMesh)) return false;
        return true;
    }
};
