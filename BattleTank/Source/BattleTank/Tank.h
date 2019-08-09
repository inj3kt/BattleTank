// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{ 
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	/*UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent* TankFromBP);*/

	void AimAt(FVector HitLocation);

private:
	////reference from blueprint
	//UChildActorComponent* Tank = nullptr;
	////rotate tank at speed, -ve for CCW
	//void MoveTank(float);
	//void RotateTank(float);

	////reference from blueprint
	//UChildActorComponent* Turret = nullptr;
	////rotate turret at speed, -ve for CCW
	//void RotateTurret(float);
	//
	//UChildActorComponent* Barrel = nullptr;
	////elevate turret at speed, -ve for positive altitude
	//void ElevateBarrel(float);

	//UPROPERTY(EditAnywhere)
	//float RotationSpeed = 120.f;

	//UPROPERTY(EditAnywhere)
	//float MovementSpeed = 120.f;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.0; //TODO find sensible default
	


	


};
