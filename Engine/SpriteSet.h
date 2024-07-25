#pragma once
#include "globalheader.h"

class SpriteSet
{
	using SpriteIdSet = std::vector<std::wstring>;

public:
	SpriteSet() {}
	~SpriteSet() {}

	const SpriteIdSet& GetSpriteIdSet() const { return _spriteIdSet; }
	void AddSpriteId(std::wstring spriteId) { _spriteIdSet.push_back(spriteId); }

private:
	SpriteIdSet _spriteIdSet;
};
