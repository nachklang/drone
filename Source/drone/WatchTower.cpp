// Fill out your copyright notice in the Description page of Project Settings.

#include "WatchTower.h"

#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AWatchTower::AWatchTower()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateOptionalDefaultSubobject<UCapsuleComponent>("Root Capsule");

		Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	Mesh->SetupAttachment(GetRootComponent());

	// Create springArm.
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 5000.f;

	// Rotate arm based on controller.
	CameraBoom->bUsePawnControlRotation = true;

	// Create camera.
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;


}

// Called when the game starts or when spawned
void AWatchTower::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWatchTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AWatchTower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("CameraYaw", this, &AWatchTower::Turn);
	PlayerInputComponent->BindAxis("CameraPitch", this, &AWatchTower::LookUp);

	PlayerInputComponent->BindAxis("CameraYawRate", this, &AWatchTower::TurnAtRate);
	PlayerInputComponent->BindAxis("CameraPitchRate", this, &AWatchTower::LookUpAtRate);
}

void AWatchTower::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AWatchTower::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AWatchTower::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AWatchTower::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
