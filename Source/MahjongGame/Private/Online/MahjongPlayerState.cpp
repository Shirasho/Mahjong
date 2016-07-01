// Distributed by Shirasho Media 2016. All rights reserved. Available for distribution under the GNU GENERAL PUBLIC LICENSE v3.

#include "MahjongGame.h"
#include "MahjongPlayerState.h"

#include "MahjongGameState.h"


AMahjongPlayerState::AMahjongPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {

	PlayerWind = static_cast<uint8>(EMahjongPlayerWind::WIND_NONE);
	bQuitter = false;
}

void AMahjongPlayerState::Reset() {

	Super::Reset();

	PlayerWind = static_cast<uint8>(EMahjongPlayerWind::WIND_NONE);
	bQuitter = false;
}

void AMahjongPlayerState::ClientInitialize(AController* InController) {

	Super::ClientInitialize(InController);
}

void AMahjongPlayerState::SetQuitter(bool bInQuitter) {
	bQuitter = bInQuitter;
}

bool AMahjongPlayerState::IsQuitter() const {
	return bQuitter;
}

int32 AMahjongPlayerState::GetScore() const {
	return Score;
}

void AMahjongPlayerState::ScoreWin(TArray<TPair<AMahjongPlayerState*, float>> FromArray) {

	AMahjongGameState* MyGameState = Cast<AMahjongGameState>(GetWorld()->GameState);

	int32 ScoreToAdd = 0;

	if (MyGameState) {

		for (auto WinData : FromArray) {
			ScoreLoss(WinData.Key, WinData.Value);
			ScoreToAdd += WinData.Value;
			//@TODO: Add score to MyGameState->TeamScores[findMYGAMESTATE]
		}
	}

	Score += ScoreToAdd;
}

void AMahjongPlayerState::ScoreLoss(AMahjongPlayerState* Player, int32 PointLoss) {

}

void AMahjongPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMahjongPlayerState, PlayerWind);
}