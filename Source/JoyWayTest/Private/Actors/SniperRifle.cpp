
#include "Actors/SniperRifle.h"
#include "Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"


class UAimComponent;
class UHealthComponent;

bool ASniperRifle::FireShot()
{
    Super::FireShot();

    const FVector ShotStart = ArrowTransform.GetLocation();
    const FVector ShotDirection = ArrowTransform.GetRotation().GetForwardVector();
    const FVector ShotEnd = ShotStart + ShotDirection * FVector{DistanceOfShot};

    DrawDebugLine(GetWorld(), ShotStart, ShotEnd, FColor::Magenta, false, 4.0f, 0, 3.0f);

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, ShotStart, ShotEnd, ECollisionChannel::ECC_Visibility);

    if (!HitResult.bBlockingHit)
    {
        return false;
    }

    const auto AffectedActor = HitResult.GetActor();
    if (!IsValid(AffectedActor)) return false;

    // домножаем на нормализованное значение дистанции: пока falloff линейный; в идеале сделать как в overwatch(полный урон в одном радиусе,
    // постепенный falloff и после только минимальный урон)
    float RealDamage = FiredDamage * (1 - HitResult.Distance / DistanceOfShot);

    if (!ItemOwner)
    {
        UGameplayStatics::ApplyPointDamage(
            AffectedActor, RealDamage / 2.0f, ShotDirection, HitResult, nullptr, this, nullptr);
        return true;
    }

    UGameplayStatics::ApplyPointDamage(AffectedActor, RealDamage / 2.0f, ShotDirection, HitResult, ItemOwner->GetController(), this, nullptr);

    return true;
}
