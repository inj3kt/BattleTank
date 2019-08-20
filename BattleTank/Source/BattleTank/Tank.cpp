// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "BattleTank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; //stop tank ticking
	
	
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
	
}

float ATank::TakeDamage
(
	float DamageAmount,
	struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator,
	AActor* DamageCauser
) {
	int32 DamageHP = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamageHP, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("TankDied"));
	}
	return DamageToApply;
}






