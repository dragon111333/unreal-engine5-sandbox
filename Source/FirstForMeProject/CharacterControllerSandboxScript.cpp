#include "CharacterControllerSandboxScript.h"
#include "EngineUtils.h"
#include "../../../../../../../Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"

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
}

void ACharacterControllerSandboxScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

}

void ACharacterControllerSandboxScript::MoveForward(const FInputActionInstance& Instance) {
	UE_LOG(LogTemp, Warning, TEXT("TESTTTTT %f"),Value);
}

void ACharacterControllerSandboxScript::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("MoveForward",this,&ACharacterControllerSandboxScript::MoveForward);

	UEnhancedInputComponent* fdasf = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	fdsf->BindAction(AimingInputAction, ETriggerEvent::Triggered, this, &ACharacterControllerSandboxScript::MoveForward);

}

