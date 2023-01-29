#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

class UStaticMeshComponent;
class UAimComponent;
class UHealthComponent;
class UTextRenderComponent;

UCLASS()
class JOYWAYTEST_API ATarget : public AActor
{
    GENERATED_BODY()

public:
    ATarget();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Static Mesh")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Static Mesh")
    UHealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Static Mesh")
    UTextRenderComponent* HealthScoreComponent;

public:
    virtual void Tick(float DeltaTime) override;
};
