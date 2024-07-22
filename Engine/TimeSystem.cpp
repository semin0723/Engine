#include "TimeSystem.h"

void TimeSystem::Initialize()
{
    _prevTime = _curTime = std::chrono::system_clock::now();
}

void TimeSystem::Update()
{
    _prevTime = _curTime;
    _curTime = std::chrono::system_clock::now();
    _deltaTime = std::chrono::duration<float>(_curTime - _prevTime).count();
}

float TimeSystem::GetDeltaTime()
{
    return _deltaTime;
}

float TimeSystem::GetFrameRate()
{
    if (_deltaTime == 0) return 0;
    return ceil((1.0f / _deltaTime));
}
