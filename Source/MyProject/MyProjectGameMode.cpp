#include "MyProjectGameMode.h"
#include "MyProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyProjectGameMode::AMyProjectGameMode()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("PlayerPawnBPClass not found!"));
    }


	ListaDeCubos.Empty();

    FVector Location = FVector(1210.0f, -80.0f, 300.0f);
    FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
    float dz = 200;
    float dy = 100;

    for (int i = 0; i < 5; i++) {
        if (GetWorld()) {
            SpawnStaticMeshCube(GetWorld(), Location, Rotation);
        } else {
            UE_LOG(LogTemp, Error, TEXT("World is NULL!"));
        }
        Location.Z += dz;
        Location.Y += dy;
    }
}



void AMyProjectGameMode::SpawnStaticMeshCube(UWorld* World, FVector Location, FRotator Rotation)
{
    if (World)
    {
        FActorSpawnParameters SpawnParams;
        AStaticMeshActor* NewCube = World->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), Location, Rotation, SpawnParams);

        if (NewCube)
        {
            UStaticMeshComponent* MeshComponent = NewCube->GetStaticMeshComponent();
            if (MeshComponent)
            {
                UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
                if (CubeMesh)
                {
                    MeshComponent->SetStaticMesh(CubeMesh);
                }
                else
                {
                    UE_LOG(LogTemp, Error, TEXT("Cube mesh not found!"));
                }
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("MeshComponent not found!"));
			}
            FVector NewScale = FVector(1.0f, 5.0f, 1.0f);
            NewCube->SetActorScale3D(NewScale);
            ListaDeCubos.Add(NewCube);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn cube actor"));
        }
    }
}

