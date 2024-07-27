#pragma once
#include "globalheader.h"

using SpriteIdSet = std::vector<std::wstring>;

class SpriteSet
{
public:
	SpriteSet() {}
	~SpriteSet() {}

	const SpriteIdSet& GetSpriteIdSet() const { return _spriteIdSet; }
	void AddSpriteId(std::wstring spriteId) { _spriteIdSet.push_back(spriteId); }

private:
	SpriteIdSet _spriteIdSet;
};
