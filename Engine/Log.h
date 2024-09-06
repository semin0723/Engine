#pragma once
#include "STL.h"
#include <fstream>

class Log
{
public:
	Log();
	~Log();

	void RecordLog(std::string message, std::source_location sourceLocation);

private:
	std::queue<std::string> _logQueue;

	// thread area
	std::mutex _mutex;
	std::condition_variable _cv;
	std::atomic<bool> _done;
	std::thread _logThread;

	void WriteLog() {
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
};

