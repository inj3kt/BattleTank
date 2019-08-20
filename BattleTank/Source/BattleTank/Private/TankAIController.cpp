// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);
		
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();	
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	if (AimingComponent->GetFiringState() == EFiringStatus::Locked) {
		AimingComponent->Fire();
	}
}
