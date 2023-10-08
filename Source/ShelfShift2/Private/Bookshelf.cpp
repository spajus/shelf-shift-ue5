// Fill out your copyright notice in the Description page of Project Settings.


#include "Bookshelf.h"

// Sets default values
ABookshelf::ABookshelf()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABookshelf::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABookshelf::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

