#pragma once
#include "../Engine/GameEngine.h"
#include "../Engine/ECMain.h"

class MainGame : public GameEngine {
public:
	MainGame() = default;
	~MainGame() = default;

	virtual void Initialize(HINSTANCE hInstance, int width, int height) override;
};