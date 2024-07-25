#pragma once
#include "pch.h"

class GameEngine
{
public:
	GameEngine() = default;
	~GameEngine() = default;

	virtual void Initialize(HINSTANCE hInstance, int width, int height);
	void Run();
	//virtual void FixedUpdate() {}
	//virtual void Update(float dt) {}
	virtual void Render() {}
	virtual void Finalize();

	void SetWindowSize(int width, int height);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	HWND _hWnd = { 0 };
	HINSTANCE _hInstance = { 0 };

	TimeSystem _time;
	float _timer = 0;

	D2DRender _d2dRender;
};

