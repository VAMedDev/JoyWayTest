
#include "Actors/HelperItem.h"
#include "Components/HealthComponent.h"

class UHealthComponent;

void AHelperItem::BeginPlay()
{
    Super::BeginPlay();

    OnActorBeginOverlap.AddDynamic(this, &AHelperItem::OnActorBeginOverlapWithComp);
}

void AHelperItem::OnActorBeginOverlapWithComp(AActor* OverlappedActor, AActor* OtherActor)
{
    if (!GrabComponentCustom->GetIsGrabbed()) return;
    auto HasInterface = OtherActor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass());
    if (HasInterface)
    {
        IInteractionInterface::Execute_OnOverlapWithHelperItem(OtherActor, this);
        DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        //tick must be enabled for destroy event
        if (!IsActorTickEnabled()) return;
        Destroy();
    }
}

