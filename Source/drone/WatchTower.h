// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "WatchTower.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DRONE_API AWatchTower : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWatchTower();

	/*Base static mesh.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WatchTower | Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/*Scale turning functions for the camera.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	float BaseTurnRate;
	/*Scale look up functions for the camera.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	float BaseLookUpRate;

	/*Called for Yaw rotation.*/
	void Turn(float Value);

	/*Called for Pitch rotation.*/
	void LookUp(float Value);

	/**Called via input to turn at a given input.
	 * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate.
	 */
	void TurnAtRate(float Rate);

	/**Called via input to look up/down at a given input.
	 * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired look up/down rate.
	 */
	void LookUpAtRate(float Rate);

	/*Camera movement is active in play mode.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Logic")
	bool IsPlayMode;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
