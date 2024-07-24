#pragma once
#include "resource.h"
#include "framework.h"

#include "../Engine/GameEngine.h"
#include "../Engine/ECMain.h"

class SampleGame : public GameEngine {	
public:
	SampleGame() = default;
	~SampleGame() = default;

	virtual void Initialize(HINSTANCE hInstance, int width, int height) override;

	virtual void FixedUpdate();
	virtual void Update(float dt);
	virtual void Render();
	virtual void Finalize();

private:

};