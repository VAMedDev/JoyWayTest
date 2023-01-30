
#include "Actors/Item.h"
#include "GameFramework/Actor.h"

AItem::AItem()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
    check(StaticMesh);
    SetRootComponent(StaticMesh);

    StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    StaticMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

    GrabComponentCustom = CreateDefaultSubobject<UGrabComponentCustom>("GrabComponentCustom");

}

void AItem::BeginPlay()
{
    Super::BeginPlay();
}

void AItem::OnGrab(UMotionControllerComponent* MotionControllerComponent)
{
    if (GrabComponentCustom->GetIsGrababble())
    {
        ItemOwner = Cast<APawn>(MotionControllerComponent->GetOwner());

        if (IsValid(ItemOwner))
        {
            AttachToComponent(MotionControllerComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
            SetOwner(ItemOwner);
        }
    }

    // #TODO: simulatePhysics toggling
}

void AItem::OnReleaseGrab()
{
    if (GrabComponentCustom->GetIsGrabbed())
    {
        DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        SetOwner(NULL);
        ItemOwner = NULL;
    }
    // #TODO: simulatePhysics toggling
}

void AItem::OnTriggerPressed_Implementation(){};
void AItem::OnTriggerReleased_Implementation() {}

void AItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
