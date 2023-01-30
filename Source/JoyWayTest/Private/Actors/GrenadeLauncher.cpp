
#include "Actors/GrenadeLauncher.h"
#include "Actors/SpawnedProjectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"

bool AGrenadeLauncher::FireShot()
{
    Super::FireShot();

    // const FVector ShotStart = ArrowTransform.GetLocation();
    const FVector ShotDirection = ArrowTransform.GetRotation().GetForwardVector();
    // const FVector ShotEnd = ShotStart + ShotDirection * FVector{DistanceOfShot};

    auto Projectile = GetWorld()->SpawnActorDeferred<ASpawnedProjectile>(
        SpawnedProjectileClass, ArrowTransform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    Projectile->SetFireDirection(ShotDirection);
    Projectile->SetDamage(FiredDamage);
    Projectile->SetOwner(GetOwner());

    if (Projectile) Projectile->FinishSpawning(ArrowTransform);

    return true;
}

void AGrenadeLauncher::OnGrab(UMotionControllerComponent* MotionControllerComponent)
{
    Super::OnGrab(MotionControllerComponent);

    if (MotionControllerComponent->MotionSource == "Right") return;
    
    auto CurrentDirection = StaticMesh->GetForwardVector();
    
    StaticMesh->SetRelativeRotation(FQuat::FindBetween(CurrentDirection, CurrentDirection * -1));
}
