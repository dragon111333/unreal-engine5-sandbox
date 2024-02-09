#include "CharacterControllerSandboxScript.h"
#include "EngineUtils.h"
#include "EnhancedInputComponent.h"
#include <EnhancedInputSubsystems.h>



ACharacterControllerSandboxScript::ACharacterControllerSandboxScript()
{
	PrimaryActorTick.bCanEverTick = true;

	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MianCharacter"));
	MainMesh->SetupAttachment(RootComponent);

	TCHAR* MeshLocation = (TCHAR*)TEXT("/Game/StarterContent/Props/SM_Couch");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> NewMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(MeshLocation);
	if (NewMesh.Succeeded()) {
		MainMesh->SetStaticMesh(NewMesh.Object);
	}
}

void ACharacterControllerSandboxScript::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,  TEXT("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Created Character!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
}

void ACharacterControllerSandboxScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

}

void ACharacterControllerSandboxScript::MoveForward() {
	UE_LOG(LogTemp, Warning, TEXT("------------------- Test input -----------------"));
}

void ACharacterControllerSandboxScript::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PC = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	PEI->BindAction(ACharacterControllerSandboxScript::InputActions->InputMove, ETriggerEvent::Triggered, this, &AInputExampleCharacter::Move);
}

