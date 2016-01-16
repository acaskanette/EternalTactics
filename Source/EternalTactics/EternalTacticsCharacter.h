// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "EternalTacticsCharacter.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EActionType
{
	AT_WALK 		UMETA(DisplayName = "Walk"),
	AT_RUN 			UMETA(DisplayName = "Run"),
	AT_ATTACK		UMETA(DisplayName = "Attack")
};


UCLASS(Blueprintable)
class AEternalTacticsCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;


public:
	AEternalTacticsCharacter();

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }




	UFUNCTION(BlueprintCallable, Category = "Actions")
		bool PerformAction(EActionType Action_, int32 APCost_);
	// Action Points
	UFUNCTION(BlueprintCallable, Category = "Actions")
		bool CanSpendActionPoints(int32 APCost_);
	UFUNCTION(BlueprintCallable, Category = "Actions")
		void SetActionPoints(int32 APSpent_);
	UFUNCTION(BlueprintCallable, Category = "Actions")
		void RefreshActionPoints();	



	// How much health you have left before dying
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 hitPoints;
	// Maximum health you can heal back up to
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 maxHitPoints;
	// How far you can move in meters per Action Point
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 speed;
	// Action Points allow you to take actions per turn
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 actionPoints;	
	// Action Points gained per turn
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 maxActionPoints;
	// Power points allow you to cast spells, each spell has a specific power point cost
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 powerPoints;
	// How many Power points you can have total
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 maxPowerPoints;
	// Determines likelihood to hit and be hit in melee
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 prowess;
	// Determines likelihood to hit enemies at range
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 accuracy;
	// Determines power with which you hit enemies in melee
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 strength;
	// Determines how resistant you are to status effects
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 endurance;
	// Determines how well you can dodge attacks that reflexes would assist with
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 agility;
	// Determines likelihood you are to retreat and how many Power Points you regenerate each turn
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 willpower;
	// Determines strength of spells
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 intelligence;
	// Determines how resistant to damage you are
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 armour;
	// Determines how big you are, therefore what you can hide behind
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 size;




};

