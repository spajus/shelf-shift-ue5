// Fill out your copyright notice in the Description page of Project Settings.


#include "Book.h"

// Sets default values
ABook::ABook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;



	TArray<FString> MeshPaths;
	for (int i = 1; i <= 5; ++i) {
		auto path = FString::Printf(TEXT("/Script/Engine.StaticMesh'/Game/Collections/3dModels/book_Book0%d.book_Book0%d'"), i, i);
    	MeshPaths.Add(path);
	}

 	int32 RandomIndex = FMath::RandRange(0, MeshPaths.Num() - 1);
    FString RandomAssetPath = MeshPaths[RandomIndex];

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(*RandomAssetPath);
    if (MeshAsset.Succeeded()) {
        MeshComponent->SetStaticMesh(MeshAsset.Object);

		/*
		UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(MeshComponent->GetMaterial(0), this);
		float R = FMath::RandRange(0.0f, 1.0f);
		float G = FMath::RandRange(0.0f, 1.0f);
		float B = FMath::RandRange(0.0f, 1.0f);
		DynamicMaterial->SetVectorParameterValue(FName("Color"), FLinearColor(R, G, B, 1.0f));
		MeshComponent->SetMaterial(0, DynamicMaterial);
		*/

    }
	MeshComponent->SetSimulatePhysics(true);
	// Increase mass
	MeshComponent->SetMassOverrideInKg(NAME_None, 10.0f, true);

	// Increase damping
	MeshComponent->BodyInstance.LinearDamping = 1.0f;
	MeshComponent->BodyInstance.AngularDamping = 15.0f;
}

void ABook::ThrowAt(FVector dir) {
	float Speed = 1000.0f;  // Adjust speed as needed
	FVector InitialVelocity = dir * Speed;

	MeshComponent->SetPhysicsLinearVelocity(InitialVelocity);
}



// Called when the game starts or when spawned
void ABook::BeginPlay()
{
	//TArray<FString> BookMeshPaths;
	Super::BeginPlay();
	// TODO: spawn a book
}

// Called every frame
void ABook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

