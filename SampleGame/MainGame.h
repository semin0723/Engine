#pragma once
#include "../Engine/GameEngine.h"
#include "../Engine/ECMain.h"

class MainGame : public GameEngine {
public:
	MainGame() = default;
	~MainGame() = default;

	virtual void Initialize(HINSTANCE hInstance, int width, int height) override;

	//virtual void FixedUpdate();
	//virtual void Update(float dt);
	virtual void Render();
	//virtual void Finalize();

private:

};