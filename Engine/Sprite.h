#pragma once
#include "Component.h"
#include "globalheader.h"

class Sprite : public Component<Sprite>
{
public:
	Sprite() {}
	Sprite(std::wstring spriteId) : _spriteId(spriteId) {}
	~Sprite() {}

	void Initialize() {}
	void Begin() {}
	void FixedUpdate() {}
	void Update(float dt) {}
	void End() {}
	void Destroy() {}

	// Set
	void SetSpriteId(std::wstring spriteId) { _spriteId = spriteId; }
	void SetSize(Vector3 size) { _size = size; }
	void SetFlipX(bool state) { _flipX = state; }
	void SetFlipY(bool state) { _flipY = state; }
	void SetFlipZ(bool state) { _flipZ = state; }

	// Get
	const bool GetFlipX() const { return _flipX; }
	const bool GetFlipY() const { return _flipY; }
	const bool GetFlipZ() const { return _flipZ; }

	void Render(ID2D1HwndRenderTarget* target);

	std::wstring _spriteId;
	Vector3 _size;

	float _playRate = 0;
	int _startAnimationIdx = 0;
	int _endAnimationIdx = (std::numeric_limits<int>::max)();

	bool _flipX = false;
	bool _flipY = false;
	bool _flipZ = false;
private:

	friend class RenderSystem;
};

