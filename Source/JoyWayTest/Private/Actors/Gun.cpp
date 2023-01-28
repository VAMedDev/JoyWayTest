// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Gun.h"

AGun::AGun()
{
    ArrowSpawn = CreateDefaultSubobject<UArrowComponent>("Arrow");
    ArrowSpawn->SetupAttachment(GetRootComponent());

    check(StaticMesh);
    check(ArrowSpawn);
}

void AGun::BeginPlay()
{
    Super::BeginPlay();
}

bool AGun::FireShot()
{
    if (!GetWorld()) return false;

    ArrowTransform = ArrowSpawn->GetComponentTransform();

    return true;
}

void AGun::OnTriggerPressed_Implementation()
{
    FireShot();
}
