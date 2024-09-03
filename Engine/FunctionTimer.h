#pragma once
#include "globalheader.h"

class FunctionTimer
{
public:
	FunctionTimer() { ExpandSize(); }
	~FunctionTimer() {}

	static FunctionTimer* GetInstance();
	static void DestroyInstance();

	template<class F, class... ARGS>
	ULL SetTimer(F&& function, ARGS&&... args, float waitInterval, bool repeat, float delay = 0) {
		auto timerfunction = std::make_shared<std::function<void(ARGS...)>>(std::bind(std::forward<F>(function), std::forward<ARGS>(args)...));
		
		ULL idx = 0;
		for (; idx < _timerFunctionTable.size(); idx++) {
			if (!std::get<3>(_timerFunctionTable[idx])) {
				_timerFunctionTable[idx] = { delay, waitInterval, repeat, [timerfunction]() { (*timerfunction)(); } };
				return idx;
			}
		}

		ExpandSize();

		_timerFunctionTable[idx] = { delay, waitInterval, repeat, [timerfunction]() { (*timerfunction)(); } };
		return idx;
	}

	template<class F, class... ARGS>
	ULL SetTimerOnce(F&& function, ARGS&&... args, float delay) {
		auto timerfunction = std::make_shared<std::function<void(ARGS...)>>(std::bind(std::forward<F>(function), std::forward<ARGS>(args)...));

		ULL idx = 0;
		for (; idx < _timerFunctionTable.size(); idx++) {
			if (!std::get<3>(_timerFunctionTable[idx])) {
				_timerFunctionTable[idx] = { delay, 0, false, [timerfunction]() { (*timerfunction)(); } };
				return idx;
			}
		}

		ExpandSize();

		_timerFunctionTable[idx] = { delay, 0, false, [timerfunction]() { (*timerfunction)(); } };
		return idx;
	}

	template<class F, class... ARGS>
	ULL SetTimerRepeat(F&& function, ARGS&&... args, float waitInterval, float delay = 0) {
		auto timerfunction = std::make_shared<std::function<void(ARGS...)>>(std::bind(std::forward<F>(function), std::forward<ARGS>(args)...));

		ULL idx = 0;
		for (; idx < _timerFunctionTable.size(); idx++) {
			if (!std::get<3>(_timerFunctionTable[idx])) {
				_timerFunctionTable[idx] = { delay, waitInterval, true, [timerfunction]() { (*timerfunction)(); } };
				return idx;
			}
		}

		ExpandSize();

		_timerFunctionTable[idx] = { delay, waitInterval, true, [timerfunction]() { (*timerfunction)(); } };
		return idx;
	}

	void Update(float dt);
	void ClearTimer(ULL timerId);

private:
	static FunctionTimer* _instance;

	ULL _expandSize = 16;
	std::vector<std::tuple<float, float, bool, std::function<void()>>> _timerFunctionTable;
	
	void ExpandSize() {
		ULL oldSize = _timerFunctionTable.size();
		ULL newSize = oldSize + _expandSize;
		_timerFunctionTable.resize(newSize);

		for (ULL i = oldSize; i < newSize; i++) {
			_timerFunctionTable[i] = { 0.f, 0.f, false, std::function<void()>() };
		}
	}

};

