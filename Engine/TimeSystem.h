#pragma once
#include <chrono>

class TimeSystem {
    using TimePoint = std::chrono::system_clock::time_point;

public:
    TimeSystem() {}
    ~TimeSystem() {}

    void Initialize();
    void Update();
    float GetDeltaTime();

    float GetFrameRate();

private:
    TimePoint _prevTime;
    TimePoint _curTime;

    float _deltaTime = 0;
};

