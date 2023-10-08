// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameInputComponent.h"
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

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void SpawnBook();

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void SpawnBookActionCB(const FInputActionInstance& Instance);

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABook> bookBlueprint;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SpawnBookAction;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
