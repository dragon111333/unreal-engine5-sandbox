// Fill out your copyright notice in the Description page of Project Settings.
#include "TestScript.h"

// Sets default values
UPROPERTY(VisibleAnywhere)
UStaticMeshComponent* VisualMesh;

ATestScript::ATestScript()
{
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	VisualMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	VisualMesh->SetSimulatePhysics(true);

	TCHAR* targetMesh =(TCHAR *) TEXT("/Game/StarterContent/Shapes/Shape_Cube");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> NewCube(targetMesh);

	if (NewCube.Succeeded())
	{
		VisualMesh->SetStaticMesh(NewCube.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

		ConstructorHelpers::FObjectFinder<UMaterialInterface>  MaterialForRunner(TEXT("/Game/StarterContent/Materials/M_CobbleStone_Pebble"));
		if (MaterialForRunner.Succeeded())
		{
			UMaterialInterface* MaterialForRunnerPointer = MaterialForRunner.Object;
			VisualMesh->SetMaterial(0, MaterialForRunnerPointer);
		}
	}

}

void ATestScript::BeginPlay()
{
	Super::BeginPlay();
}

void ATestScript::MoveToFront() {
	FVector location = GetActorLocation();
	float speed = (float) FMath::RandRange(0.5f, MAX_SPEED);

	FTransform transform;
	location.X += speed;

	transform.SetLocation(location);
	//transform.SetRotation(FQuat::Identity); 

	SetActorRelativeTransform(transform);
}

void ATestScript::RotateThisObject(float DeltaTime){
	UE_LOG(LogTemp, Warning, TEXT("TESTTTT"));

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	UE_LOG(LogTemp,Warning,TEXT("Delta Height = %f"),DeltaHeight);
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);

}

// Called every frame
void ATestScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//RotateThisObject(DeltaTime);
	MoveToFront();

}

