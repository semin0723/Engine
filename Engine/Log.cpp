#include "pch.h"
#include "Log.h"
#include "TimeSystem.h"

Log::Log() : _done(false)
{
	_logThread = std::thread(&Log::WriteLog, this);
}

Log::~Log()
{
	// TODO: Log 클래스가 지워 질 때 logQueue에 남아 있는 로그를 모두 저장하고 삭제 돼야 합니다.

	_done = true;
	_cv.notify_all();

	if (_logThread.joinable()) {
		_logThread.join();
	}
}

void Log::RecordLog(std::string message, std::source_location sourceLocation = std::source_location::current())
{
	// log message template \
	2024-09-05 10:49:30 | <class : Log, function : RecordLog> | Message : write record log template.

	std::string functionName = sourceLocation.function_name();
	std::stringstream ss(functionName);
	while (std::getline(ss, functionName, ' ')) {}

	std::string logMessage =
		std::format(
			"{} | <function : {}> | Message : {}", 
			TimeSystem::GetTimeStamp(), functionName, message
		);

	std::unique_lock<std::mutex> lock(_mutex);
	_logQueue.push(logMessage);

	_cv.notify_one();
}

void Log::WriteLog()
{
	std::ofstream logFile("log.txt", std::ios::out | std::ios::app);

	// 프로그램 종료시 또는 평상시.
	while (!_done || !_logQueue.empty()) {
		std::unique_lock<std::mutex> lock(_mutex);

		_cv.wait(lock, [this]() { return !_logQueue.empty() || _done; });

		while (!_logQueue.empty()) {
			std::string log = _logQueue.front();
			_logQueue.pop();

			logFile << log << "\n";
		}
	}
	logFile.close();
}
