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

	// Set
	void SetSpriteId(std::wstring spriteId) { _spriteId = spriteId; }
	void SetSize(Vector3 size) { _size = size; }
	void SetFlipX(bool state) { _flipX = state; }
	void SetFlipY(bool state) { _flipY = state; }
	void SetFlipZ(bool state) { _flipZ = state; }
	void SetOrderLayer(ULL layerOrder) { _orderLayer = layerOrder; }

	// Get
	const Vector3 GetSize() const { return _size; }
	const bool GetFlipX() const { return _flipX; }
	const bool GetFlipY() const { return _flipY; }
	const bool GetFlipZ() const { return _flipZ; }
	const int GetOrderLayer() const { return _orderLayer; }

	const bool IsAnimationEnd() const;

private:
	ULL _orderLayer = 0;

	// Sprite Area
	Vector3 _size;
	std::wstring _spriteId;
	bool _flipX = false;
	bool _flipY = false;
	bool _flipZ = false;

	// Animation Area
	float _playRate = 0;
	bool _loop = true;
	int _curAnimationIdx = 0;
	int _startAnimationIdx = 0;
	int _endAnimationIdx = (std::numeric_limits<int>::max)();


	friend class RenderSystem;
};

