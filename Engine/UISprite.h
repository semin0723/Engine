#pragma once
#include "Component.h"
#include "globalheader.h"


class UISprite : public Component<UISprite>
{
public:
	UISprite() {}
	UISprite(std::wstring spriteId) : _spriteId(spriteId) {}
	~UISprite() {}

	void Initialize() {}
	void Begin() {}
	void FixedUpdate() {}
	void Update(float dt);
	void End() {}
	void Destroy() {}

	void Render(ID2D1HwndRenderTarget* target);

	std::wstring _spriteId;
	Vector3 _size;

	float _playRate = 0;
	int _startAnimationIdx = 0;
	int _endAnimationIdx = (std::numeric_limits<int>::max)();

	bool _flipX = false;
	bool _flipY = false;
};

