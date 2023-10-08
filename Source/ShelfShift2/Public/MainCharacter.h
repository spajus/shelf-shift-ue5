// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Character.h"
#include "Book.h"
#include "MainCharacter.generated.h"

UCLASS()
class SHELFSHIFT2_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABook> bookBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SpawnBookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* FreeLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	// Expose a mapping context as a property in your header file...
    UPROPERTY(EditAnywhere, Category="Input")
	UInputMappingContext* InputMapping;

private:
	bool HasLook;
	bool HasMove;
	FVector2D LookMotion;
	FVector2D MoveMotion;
	APlayerController* PlayerController;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SpawnBookActionCB(const FInputActionInstance& Instance);
	void FreeLookActionCB(const FInputActionInstance& Instance);
	void MoveActionCB(const FInputActionInstance& Instance);

private:
	void SpawnBook();
};
