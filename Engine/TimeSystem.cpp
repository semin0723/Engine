#include "pch.h"
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

std::string TimeSystem::GetTimeStamp()
{
    const TimePoint now = std::chrono::system_clock::now();
    time_t nowTime = std::chrono::system_clock::to_time_t(now);
    struct tm timeStruct;
    localtime_s(&timeStruct, &nowTime);

    std::string timeStamp =
        std::format(
            "{:0>4}-{:0>2}-{:0>2} {:0>2}:{:0>2}:{:0>2}",
            timeStruct.tm_year + 1900, timeStruct.tm_mon + 1, timeStruct.tm_mday,
            timeStruct.tm_hour, timeStruct.tm_min, timeStruct.tm_sec
        );
    //char temp[128];
    //snprintf(temp, sizeof(temp), "%04d-%02d-%02d %02d:%02d:%02d",
    //    timeStruct.tm_year + 1900, timeStruct.tm_mon + 1, timeStruct.tm_mday,
    //    timeStruct.tm_hour, timeStruct.tm_min, timeStruct.tm_sec);

    //return std::string(temp);
    return timeStamp;
}
