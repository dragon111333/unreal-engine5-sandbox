// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerMuanualInputConfigData.generated.h"
#include <EnhancedInputLibrary.h>

/**
 * 
 */
UCLASS()
class FIRSTFORMEPROJECT_API UPlayerMuanualInputConfigData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* InputMove;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* InputLook;
	
};
