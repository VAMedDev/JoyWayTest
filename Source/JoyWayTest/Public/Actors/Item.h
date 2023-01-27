#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Interfaces/InteractionInterface.h"
#include "Components/GrabComponentCustom.h"
#include "Item.generated.h"

class UStaticMeshComponent;

// #TODO: сделать абстрактным
// UCLASS(Abstract, Blueprintable)
UCLASS()
class JOYWAYTEST_API AItem : public AActor, public IInteractionInterface
{
    GENERATED_BODY()

public:
    AItem();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Static Mesh")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(BlueprintReadWrite)
    UGrabComponentCustom* GrabComponentCustom;

    virtual void OnGrab(UMotionControllerComponent* MotionControllerComponent) override;
    virtual void OnRelease() override;
    virtual void OnTrigger() override;

public:
    virtual void Tick(float DeltaTime) override;
};
