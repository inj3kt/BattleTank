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
		
protected:
	

public:	
	
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	) override;
	
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:

	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 InitialHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = InitialHealth;
	
};
