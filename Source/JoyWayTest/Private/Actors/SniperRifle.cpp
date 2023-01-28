// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/AimComponent.h"
#include "Actors/SniperRifle.h"

class UAimComponent;

bool ASniperRifle::FireShot()
{
    Super::FireShot();

    const FVector ShotStart = ArrowTransform.GetLocation();
    const FVector ShotDirection = ArrowTransform.GetRotation().GetForwardVector();
    const FVector ShotEnd = ShotStart + ShotDirection * DistanceOfShot;

    DrawDebugLine(GetWorld(), ShotStart, ShotEnd, FColor::Magenta, false, 4.0f, 0, 3.0f);

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, ShotStart, ShotEnd, ECollisionChannel::ECC_Visibility);

    if (HitResult.bBlockingHit)
    {
        
        HitResult.Actor->GetComponentByClass(TSubclassOf<UAimComponent>());
    }
    
    return true;
}
