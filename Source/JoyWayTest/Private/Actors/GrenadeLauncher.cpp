
#include "Actors/GrenadeLauncher.h"
#include "Actors/SpawnedProjectile.h"
#include "Components/SphereComponent.h"

bool AGrenadeLauncher::FireShot()
{
    Super::FireShot();

    //const FVector ShotStart = ArrowTransform.GetLocation();
    const FVector ShotDirection = ArrowTransform.GetRotation().GetForwardVector();
    //const FVector ShotEnd = ShotStart + ShotDirection * FVector{DistanceOfShot};

    auto Projectile = GetWorld()->SpawnActorDeferred<ASpawnedProjectile>(
        SpawnedProjectileClass, ArrowTransform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    Projectile->SetFireDirection(ShotDirection);
    Projectile->SetDamage(FiredDamage);
    Projectile->SetOwner(GetOwner());

    if (Projectile) Projectile->FinishSpawning(ArrowTransform);

    return true;
}
