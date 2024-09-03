#include "pch.h"
#include "Sprite.h"
#include "Transform.h"
#include "ResourceSystem.h"
#include "d2d1_1helper.h"

const bool Sprite::IsAnimationEnd() const
{
	return _curAnimationIdx == ResourceSystem::GetInstance()->GetSpriteSet(_spriteId)->GetSpriteIdSet().size();
}
