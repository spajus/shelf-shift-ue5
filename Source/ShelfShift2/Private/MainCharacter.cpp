// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Book.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SpawnBookActionCB(const FInputActionInstance& Instance)
{
	bool BoolValue = Instance.GetValue().Get<bool>();
	if (BoolValue)
	{
		SpawnBook();
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// You can bind to any of the trigger events here by changing the "ETriggerEvent" enum value
	Input->BindAction(SpawnBookAction, ETriggerEvent::Triggered, this, &AMainCharacter::SpawnBookActionCB);

}

void AMainCharacter::SpawnBook()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<ABook>(bookBlueprint, GetActorTransform(), spawnParams);
}
