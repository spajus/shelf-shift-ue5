// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Book.generated.h"

UCLASS()
class SHELFSHIFT2_API ABook : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABook();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent = nullptr;

	void ThrowAt(FVector Direction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
