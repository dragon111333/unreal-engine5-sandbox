// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterControllerSandboxScript.generated.h"

UCLASS()
class FIRSTFORMEPROJECT_API ACharacterControllerSandboxScript : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterControllerSandboxScript();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "VALUE")
	UStaticMeshComponent * MainMesh;

private :
		void MoveForward(const FInputActionInstance& Instance);

};
