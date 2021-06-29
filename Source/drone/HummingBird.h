// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "HummingBird.generated.h"

UCLASS()
class DRONE_API AHummingBird : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHummingBird();

	/*Base static mesh.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone variables")
	float Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone variables")
	float B;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone variables")
	float C;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone variables")
	float D;

	float AngleAxis;

	UPROPERTY(EditAnywhere, Category = Movement)
	FVector Dimensions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
	FVector ObjectLocation;

	UPROPERTY(EditAnywhere, Category = Movement)
	FVector AxisVector;

	UPROPERTY(EditAnywhere, Category = Movement)
	float Multiplier;

private:
	float RunningTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
