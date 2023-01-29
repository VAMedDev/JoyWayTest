#include "Components/GrabComponentCustom.h"
#include "Interfaces/InteractionInterface.h"

class IInteractionInterface;

UGrabComponentCustom::UGrabComponentCustom()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UGrabComponentCustom::BeginPlay()
{
    Super::BeginPlay();

    Owner = GetOwner();
}

void UGrabComponentCustom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UGrabComponentCustom::TryGrab(UMotionControllerComponent* MotionControllerComponent)
{
    if (IsGrabbed) return false;
    IInteractionInterface* Interface = Cast<IInteractionInterface>(Owner);

    if (!Interface) return false;
    Interface->OnGrab(MotionControllerComponent);

    IsGrabbed = true;
    return true;
}

bool UGrabComponentCustom::TryRelease()
{
    if (!IsGrabbed) return false;
    IInteractionInterface* Interface = Cast<IInteractionInterface>(Owner);

    if (!Interface) return false;
    Interface->OnReleaseGrab();

    IsGrabbed = false;
    return true;
}
