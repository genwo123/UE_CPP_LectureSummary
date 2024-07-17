// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    //UE_LOG(LogTemp, Warning, TEXT("폰이 죽었어!!"));

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

    if (PlayerController != nullptr)
    {
        EndGame(false);
    }
    
    for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!Controller->IsDead())
        {
            return;
        }
    }

    EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for(AController * Controller : TActorRange<AController>(GetWorld()))//월드에 있는 모든걸 한번씩 for문에서 검증
    {   
        // 방법2 bool에서 bIsPlayerWinner가 플레이어 컨트롤러고, 그 플레이어가 승자면
        // 우리가 승자임으로 둘다 참으로이다. 쉽게 말해 현재 조작 중인 A와 승리한 개체와 비교해서 참참,거짓거짓이면
        // 컨트롤러의 승리이고, 컨트롤러와 승자가 다르면 거짓이므로 패배인것
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
    
}



// void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
// {
//     for(AController * Controller : TActorRange<AController>(GetWorld()))//월드에 있는 모든걸 한번씩 for문에서 검증
//     {   

//     //방법 1 for문 내부 내용
//         bool bIsPlayerController = Controller->IsPlayerController();
//         if(bIsPlayerWinner)
//         {
//             Controller->GameHasEnded(nullptr, bIsPlayerController);
//         }
//         else
//         {
//             Controller->GameHasEnded(nullptr, !bIsPlayerController);
//         }
        
//     }
    
// }
