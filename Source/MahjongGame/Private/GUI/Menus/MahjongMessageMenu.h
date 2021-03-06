// Distributed by Shirasho Media 2016. All rights reserved. Available for distribution under the GNU GENERAL PUBLIC LICENSE v3.

#pragma once

DECLARE_DELEGATE(FMessageMenuButtonClicked);

class UMahjongGameInstance;

class FMahjongMessageMenu : public TSharedFromThis<FMahjongMessageMenu>
{
public:
    /** build menu */
    void Construct(TWeakObjectPtr<UMahjongGameInstance> InGameInstance, TWeakObjectPtr<ULocalPlayer> InPlayerOwner, const FText& Message, const FText& OKButtonText, const FText& CancelButtonText, const FName& InPendingNextState);

    /** Remove from the gameviewport. */
    void RemoveFromGameViewport();

    /**
    * The delegate function for external login UI closure when a user has signed in.
    *
    * @param UniqueId The unique Id of the user who just signed in.
    * @param ControllerIndex The controller index of the player who just signed in.
    */
    void HandleLoginUIClosed(TSharedPtr<const FUniqueNetId> UniqueId, const int ControllerIndex);

    /** Remove dialog, and go to the next state */
    void HideDialogAndGotoNextState();

    void SetOKClickedDelegate(FMessageMenuButtonClicked	InButtonDelegate);
    void SetCancelClickedDelegate(FMessageMenuButtonClicked	InButtonDelegate);


private:

    /** Owning game instance */
    TWeakObjectPtr<UMahjongGameInstance> GameInstance;

    /** Local player that will have focus of the dialog box (can be NULL) */
    TWeakObjectPtr<ULocalPlayer> PlayerOwner;

    /** Cache the desired next state so we can advance to that after the confirmation dialog */
    FName PendingNextState;

    /** Handler for ok confirmation. */
    FReply OnClickedOK();
    FMessageMenuButtonClicked	OKButtonDelegate;

    FReply OnClickedCancel();
    FMessageMenuButtonClicked	CancelButtonDelegate;
};
