#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class AController;
class UPrimitiveComponent;
class UDamageType;

DECLARE_MULTICAST_DELEGATE(FOnDeath)
// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHealthComponent();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Health", meta = (ClampMin = "0.0"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditAnywhere, Category = "Health", meta = (ClampMin = "0.0"))
    float Health = 0.0f;

    UFUNCTION()
    void OnTakeAnyDamage(
        AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    UFUNCTION()
    void OnTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation,
        UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);

    UFUNCTION()
    void OnTakeRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, FHitResult HitInfo,
        AController* InstigatedBy, AActor* DamageCauser);

public:
    // UFUNCTION(BlueprintAssignable, Category = "DeathEvents")
    // UFUNCTION()
    FOnDeath OnDeath;

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable)
    bool IsDead() const { return Health <= 0.0f; };

    UFUNCTION(BlueprintCallable)
    float GetHealth() const { return Health; };

    UFUNCTION(BlueprintCallable)
    float GetMaxHealth() const { return MaxHealth; };

    UFUNCTION(BlueprintCallable)
    void SetMaxHealth(float InMaxHealth) { MaxHealth = InMaxHealth; };
};
