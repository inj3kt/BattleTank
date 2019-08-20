// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations



UCLASS()
class BATTLETANK_API ATank : public APawn
{ 
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
		
protected:
	

public:	
	// Called when the game starts or when spawned
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 InitialHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = InitialHealth;
	
};
