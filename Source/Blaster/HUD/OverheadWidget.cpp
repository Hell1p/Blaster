// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole_Name(APawn* InPawn, APlayerState* PlayerState)
{
	/*ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	default:
		return;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote role: %s "), *Role);*/
	if(PlayerState)
	{
		FString PlayerNameString = FString::Printf(TEXT("%s"), *PlayerState->GetPlayerName());
		SetDisplayText(/*RemoteRoleString + */PlayerNameString);
	}
	/*else
	{
		SetDisplayText(RemoteRoleString);
	}*/
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}


