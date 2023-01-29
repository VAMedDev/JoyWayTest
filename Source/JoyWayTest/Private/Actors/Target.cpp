
#include "Actors/Target.h"
#include "Components/StaticMeshComponent.h"
#include "Components/HealthComponent.h"
#include "Components/TextRenderComponent.h"

ATarget::ATarget()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
    HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
    HealthScoreComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthScoreComponent");
    check(StaticMesh);
    check(HealthComponent);
    check(HealthScoreComponent);

    SetRootComponent(StaticMesh);
    HealthScoreComponent->SetupAttachment(GetRootComponent());
    // HealthScoreComponent->RegisterComponent();

    StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    StaticMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
}

void ATarget::BeginPlay()
{
    Super::BeginPlay();
}

void ATarget::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // #TODO сделать обновление не на тике, а на ивенте по получению урона
    float CurrentHealth = HealthComponent->GetHealth();
    HealthScoreComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f "), CurrentHealth)));
}
