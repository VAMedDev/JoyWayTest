#include "GameFramework/Actor.h"
#include "Actors/Item.h"

AItem::AItem()
{
    PrimaryActorTick.bCanEverTick = true;

    // #TODO: добавить в наследника код ниже; этот класс будет абстрактным
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
    SetRootComponent(StaticMesh);

    StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    StaticMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

    GrabComponentCustom = CreateDefaultSubobject<UGrabComponentCustom>("GrabComponentCustom");

    // UE_LOG(LogTemp, Error, TEXT("Constraction ended"));
}

void AItem::BeginPlay()
{
    Super::BeginPlay();
}

void AItem::OnGrab(UMotionControllerComponent* MotionControllerComponent)
{
    UE_LOG(LogTemp, Error, TEXT("GRAB!!"));

    AttachToComponent(MotionControllerComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void AItem::OnRelease()
{
    DetachRootComponentFromParent();
}

void AItem::OnTrigger() {}

void AItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
