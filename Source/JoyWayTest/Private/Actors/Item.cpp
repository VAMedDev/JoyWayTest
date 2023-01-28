#include "GameFramework/Actor.h"
#include "Actors/Item.h"

AItem::AItem()
{
    PrimaryActorTick.bCanEverTick = true;

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
    if (GrabComponentCustom->GetIsGrababble())
    {
        AttachToComponent(MotionControllerComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
    }

    // #TODO: simulatePhysics toggling
}

void AItem::OnReleaseGrab()
{
    // if (GrabComponentCustom->GetIsGrabbed()) DetachRootComponentFromParent();
    if (GrabComponentCustom->GetIsGrabbed()) DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

    // #TODO: simulatePhysics toggling
}

void AItem::OnTriggerPressed_Implementation(){};
void AItem::OnTriggerReleased_Implementation() {}

void AItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
