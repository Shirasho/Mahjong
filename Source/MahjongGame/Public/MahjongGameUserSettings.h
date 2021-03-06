// Distributed by Shirasho Media 2016. All rights reserved. Available for distribution under the GNU GENERAL PUBLIC LICENSE v3.

#pragma once

#include "MahjongGameUserSettings.generated.h"

UCLASS()
class UMahjongGameUserSettings : public UGameUserSettings
{
	GENERATED_UCLASS_BODY()

public:

	/** Applies all current user settings to the game and saves to permanent storage (e.g. file), optionally checking for command line overrides. */
	virtual void ApplySettings(bool bCheckForCommandLineOverrides) override;

	int32 GetGraphicsQuality() const
	{
		return GraphicsQuality;
	}

	void SetGraphicsQuality(int32 InGraphicsQuality)
	{
		GraphicsQuality = FMath::Clamp(InGraphicsQuality, 0, 3);
	}

    float GetResolutionScale() const
    {
        return ResolutionScale;
    }

    void SetResolutionScale(float InResolutionScale)
    {
        ResolutionScale = FMath::Clamp(InResolutionScale, 10.f, 100.f);
    }

	bool IsLanMatch() const
	{
		return bIsLanMatch;
	}

	void SetLanMatch(bool InbIsLanMatch)
	{
		bIsLanMatch = InbIsLanMatch;
	}

	// interface UGameUserSettings
	virtual void SetToDefaults() override;

private:
	/**
	* Graphics Quality
	*	0 = Low
	*	1 = High
	*/
	UPROPERTY(config)
	int32 GraphicsQuality;

    UPROPERTY(config)
    float ResolutionScale;

	/** is lan match? */
	UPROPERTY(config)
	bool bIsLanMatch;
};
