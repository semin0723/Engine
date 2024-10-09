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

	void WriteLog();
};

