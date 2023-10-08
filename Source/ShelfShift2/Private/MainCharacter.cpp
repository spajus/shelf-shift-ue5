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
	PlayerController = Cast<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasMouseMotion) {
		FRotator rot = PlayerController->GetControlRotation();
		rot.Pitch += MouseMotion.Y;
		rot.Yaw += MouseMotion.X;
		HasMouseMotion = false;
		PlayerController->SetControlRotation(rot);
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// You can bind to any of the trigger events here by changing the "ETriggerEvent" enum value
	Input->BindAction(SpawnBookAction, ETriggerEvent::Started, this, &AMainCharacter::SpawnBookActionCB);
	Input->BindAction(FreeLookAction, ETriggerEvent::Triggered, this, &AMainCharacter::FreeLookActionCB);

}

void AMainCharacter::SpawnBook()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<ABook>(bookBlueprint, GetActorTransform(), spawnParams);
}

void AMainCharacter::FreeLookActionCB(const FInputActionInstance& Instance)
{
	MouseMotion = Instance.GetValue().Get<FVector2D>();
	HasMouseMotion = true;
	//GLog->Logf(TEXT("Input: %f:%f"), MouseMotion.X, MouseMotion.Y);
}
