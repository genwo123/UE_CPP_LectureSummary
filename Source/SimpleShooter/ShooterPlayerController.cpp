// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"


void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    HUD = CreateWidget(this, HUDClass);
    if(HUD != nullptr)
    {
        HUD->AddToViewport();
    }
   
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);

    HUD->RemoveFromViewport();
    if(bIsWinner)
    {
        UUserWidget* WinScreean = CreateWidget(this, WinScreeanClass);
        if(WinScreean != nullptr)
        {
            WinScreean->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreean = CreateWidget(this, LoseScreeanClass);
        if(LoseScreean != nullptr)
        {
            LoseScreean->AddToViewport();
        }
    }
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);

    

    
}


