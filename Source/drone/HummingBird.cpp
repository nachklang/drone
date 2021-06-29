// Fill out your copyright notice in the Description page of Project Settings.

#include "HummingBird.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AHummingBird::AHummingBird()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	Mesh->SetupAttachment(GetRootComponent());

	RunningTime = 0;

	Dimensions = FVector(300, 0, 0);
	AxisVector = FVector(0, 0, 1);
	Multiplier = 50.f;
}

// Called when the game starts or when spawned
void AHummingBird::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHummingBird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	AngleAxis += DeltaTime * Multiplier;

	if (AngleAxis >= 360.0f)
	{
		AngleAxis = 0;
	}

	FVector NewLocation = ObjectLocation;
	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z = ObjectLocation.Z + Amplitude * FMath::Sin(B * RunningTime - C) + D;

	FRotator NewRotation = FRotator(0, AngleAxis, 0);

	FQuat QuatRotation = FQuat(NewRotation);

	SetActorLocationAndRotation(NewLocation, QuatRotation, false, 0, ETeleportType::None);
}
