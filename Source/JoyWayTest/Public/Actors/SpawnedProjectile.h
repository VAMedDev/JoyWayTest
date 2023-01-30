#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SpawnedProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class JOYWAYTEST_API ASpawnedProjectile : public AActor
{
    GENERATED_BODY()

public:
    ASpawnedProjectile();

protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    USphereComponent* SphereCollisionComponent;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UProjectileMovementComponent* MovementComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float DamageRadius = 50.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float Damage = 10.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float LifeSpan = 5.0f;


    UFUNCTION()
    void OnHitActions(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
        const FHitResult& Hit);

    virtual void BeginPlay() override;

private:
    FVector FireDirection{0.0f};

public:
    UFUNCTION(BlueprintCallable)
    void SetFireDirection(FVector InFireDirectionVector) { FireDirection = InFireDirectionVector; }

    UFUNCTION(BlueprintCallable)
    void SetDamageRadius(float InDamageRadius) { DamageRadius = InDamageRadius; };

    UFUNCTION(BlueprintCallable)
    void SetDamage(float InDamage) { Damage = InDamage; };
};
