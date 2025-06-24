#pragma once

UENUM()
enum class EActionGameConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EActionGameValidType : uint8
{
	Valid,
	Invalid
};

UENUM()
enum class EActionGameSuccessType : uint8
{
	Successful,
	Failed
};