// Distributed by Shirasho Media 2016. All rights reserved. Available for distribution under the GNU GENERAL PUBLIC LICENSE v3.

#pragma once

#include "MahjongGameMode.h"
#include "MahjongGameMode_Japanese.generated.h"

class AMahjongPlayerState;

UCLASS()
class AMahjongGameMode_Japanese : public AMahjongGameMode {

	GENERATED_BODY()

protected:

	AMahjongGameMode_Japanese();

protected:
	
	/** The player who won the game. */
	UPROPERTY(transient)
	AShooterPlayerState* WinnerPlayerState;

	/** Determine who won the game. */
	virtual void DetermineGameWinner() override;
};