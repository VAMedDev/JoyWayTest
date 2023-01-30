#pragma once

#include "CoreMinimal.h"
#include "Actors/Item.h"
#include "HelperItem.generated.h"

class AActor;

UCLASS()
class JOYWAYTEST_API AHelperItem : public AItem
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    //#TODO: prohibit access in BP
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float HealAmount = 10.f;

    UFUNCTION(BlueprintCallable)
    void OnActorBeginOverlapWithComp(AActor* OverlappedActor, AActor* OtherActor);

public:
    UFUNCTION(BlueprintCallable)
    float GetHealAmount() { return HealAmount; };
};
