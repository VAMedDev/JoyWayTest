
#include "Components/HealthComponent.h"
#include "GameFramework/Actor.h"

class AActor;
class ASniperRifle;

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;

    AActor* OwnerComponent = GetOwner();
    if (OwnerComponent)
    {
        // OwnerComponent->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamage);
        OwnerComponent->OnTakePointDamage.AddDynamic(this, &UHealthComponent::OnTakePointDamage);
        OwnerComponent->OnTakeRadialDamage.AddDynamic(this, &UHealthComponent::OnTakeRadialDamage);
    }
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0 || IsDead()) return;

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

    Health -= Damage;

    if (IsDead())
    {
        OnDeath.Broadcast();
    };
}

void UHealthComponent::OnTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation,
    UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser)
{
    Health -= Damage;
}

void UHealthComponent::OnTakeRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin,
    FHitResult HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0 || IsDead()) return;

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

    Health -= Damage;

    if (IsDead())
    {
        OnDeath.Broadcast();
    };
}
