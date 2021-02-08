// Copyright RADiCAL Solutions, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RadicalLiveLinkRemapAssetBase.h"

#include "RadToEpicRemapAsset.generated.h"

/**
 * 
 */
UCLASS()
class UNREALLIVELINKREMAPPLUGIN_API URadToEpicRemapAsset : public URadicalLiveLinkRemapAssetBase
{
	GENERATED_BODY()

protected:
	virtual FVector ConvertRootPosition(FVector LLPosition) const override;

	virtual FQuat ConvertRootRotation(FQuat LLRotation) const override;

	virtual FQuat ConvertBoneRotation(FQuat LLRotation) const override;

	virtual FName GetTargetRootName() const override { return "pelvis"; }
};
