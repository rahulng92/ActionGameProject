#pragma once

namespace Debug
{
	static void Print(const FString& Msg, const FColor& Color = FColor::Cyan, int32 InKey = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, 7.f, Color, Msg);

			UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		}
	}
	//ex use case FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *WeaponToRegister->GetName(), *WeaponTagToRegister.ToString());
}