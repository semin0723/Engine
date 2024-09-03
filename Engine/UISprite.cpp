#include "pch.h"
#include "UISprite.h"
#include "ResourceSystem.h"

const bool UISprite::IsAnimationEnd() const
{
	return _curAnimationIdx == ResourceSystem::GetInstance()->GetSpriteSet(_spriteId)->GetSpriteIdSet().size();
}
