// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; //stop tank ticking

	//no need to protect pointers in constructor
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}




void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}

//void ATank::SetTankChildActor(UChildActorComponent* TankFromBP) {
//	if (!TankFromBP) { return; }
//	Tank = TankFromBP;
//}

//
//void ATank::SetTurretChildActor(UChildActorComponent* TurretFromBP) {
//	if (!TurretFromBP) { return; }
//	Turret = TurretFromBP;
//}
//
//void ATank::SetBarrelChildActor(UChildActorComponent* BarrelFromBP) {
//	if (!BarrelFromBP) { return; }
//	Barrel = BarrelFromBP;
//}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}



void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("%f: Firing"), GetWorld()->GetTimeSeconds());
}


// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	
//	InputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret); //Bind axis is expecting to take in an argument of speed 
//	InputComponent->BindAxis("Elevate_Barrel", this, &ATank::ElevateBarrel);
//	InputComponent->BindAxis("Move_Tank", this, &ATank::MoveTank);
//	InputComponent->BindAxis("Rotate_Tank", this, &ATank::RotateTank);
//
//}

//void ATank::RotateTurret(float Speed) {
//	
//	if (!Turret) { return; }
//	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;  //frame rate independence
//	Turret->AddRelativeRotation(FRotator(0, Rotation, 0));
//}
//
//void ATank::ElevateBarrel(float Speed) {
//	if (!Barrel) { return; }
//	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
//	Barrel->AddRelativeRotation(FRotator(Rotation, 0, 0)); //pitch, yaw, roll
//}
//
//void ATank::MoveTank(float Speed)
//{
//	if (!Tank) { return; }
//	float Distance = GetWorld()->DeltaTimeSeconds * Speed * MovementSpeed;
//	Tank->AddRelativeLocation(Tank->GetForwardVector() * Distance);
//}
//
//void ATank::RotateTank(float Speed)
//{
//	if (!Tank) { return; }
//	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
//	Tank->AddRelativeRotation(FRotator(0, Rotation, 0));
//}
//
