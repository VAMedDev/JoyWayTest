// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/SpawnedProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/ProjectileMovementComponent.h"

ASpawnedProjectile::ASpawnedProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereCollisionComponent");
    SphereCollisionComponent->InitSphereRadius(5.0f);
    SphereCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SphereCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    SetRootComponent(SphereCollisionComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
}

void ASpawnedProjectile::BeginPlay()
{
    Super::BeginPlay();

    check(MovementComponent);
    check(SphereCollisionComponent);
    MovementComponent->Velocity = FireDirection * MovementComponent->InitialSpeed;

    SetLifeSpan(LifeSpan);
    SetDamageRadius(SphereCollisionComponent->GetScaledSphereRadius());

    SphereCollisionComponent->OnComponentHit.AddDynamic(this, &ASpawnedProjectile::OnHitActions);
}

void ASpawnedProjectile::OnHitActions(
    UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    MovementComponent->StopMovementImmediately();

    UGameplayStatics::ApplyRadialDamage(
        GetWorld(), Damage, Hit.ImpactPoint, DamageRadius, UDamageType::StaticClass(), {}, this, nullptr, true);

    DrawDebugSphere(GetWorld(), GetActorLocation(), DamageRadius, 30, FColor::Cyan, false, 5.0f);

    Destroy();
}
