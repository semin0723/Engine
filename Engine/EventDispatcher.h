#pragma once
#include <unordered_map>
#include <list>
#include "EventDelegate.h"

class IEvent;

class IEventDispatcher {
public:
	virtual ~IEventDispatcher() {}

	virtual void Dispatch(IEvent* event) = 0;
	virtual void AddEventCallback(IEventDelegate* const eventDelegate) = 0;
	virtual void RemoveEventCallback(IEventDelegate* eventDelegate) = 0;
	virtual size_t GetEventCallbackCount() const = 0;
};

template<class T>
class EventDispatcher : public IEventDispatcher
{
	using EventDelegateList = std::list<IEventDelegate*>;
	using RemoveDelegates = std::list<IEventDelegate*>;

public:
	EventDispatcher() : _locked(false) {}
	virtual ~EventDispatcher() {
		_eventCallbacks.clear();
		_pendingRemoveDelegates.clear();
	}

	void Dispatch(IEvent* event) override {
		_locked = true;

		// removeEventCallback 시점에서 삭제대기로 이동한 이벤트 들을 삭제한다.
		if (!_pendingRemoveDelegates.empty()) {
			for (auto eventCallback : _pendingRemoveDelegates) {

				// iterator 반환 하는듯.
				auto result = std::find_if(_eventCallbacks.begin(), _eventCallbacks.end(), [&](const IEventDelegate* other) {
					return other == eventCallback;
					});

				if (result != _eventCallbacks.end()) {
					IEventDelegate* data = (IEventDelegate*)(*result);
					_eventCallbacks.erase(result);

					delete data;
					data = nullptr;
				}
			}
			_pendingRemoveDelegates.clear();
		}

		for (auto eventCallback : _eventCallbacks) {
			eventCallback->invoke(event);
		}
		_locked = false;
	}

	virtual void AddEventCallback(IEventDelegate* const eventDelegate) override {
		auto result = std::find_if(_pendingRemoveDelegates.begin(), _pendingRemoveDelegates.end(), [&](const IEventDelegate* other) {
			return other == eventDelegate;
			});

		if (result != _pendingRemoveDelegates.end()) {
			_pendingRemoveDelegates.erase(result);
			return;
		}
		_eventCallbacks.push_back(eventDelegate);
	}

	virtual void RemoveEventCallback(IEventDelegate* eventDelegate) override {
		if (_locked == false) {
			auto result = std::find_if(_eventCallbacks.begin(), _eventCallbacks.end(), [&](const IEventDelegate* other) {
				return other == eventDelegate;
				});

			if (result != _eventCallbacks.end()) {
				IEventDelegate* data = (IEventDelegate*)(*result);
				_eventCallbacks.erase(result);

				delete data;
				data = nullptr;
			}
		}
		else {
			auto result = std::find_if(_eventCallbacks.begin(), _eventCallbacks.end(), [&](const IEventDelegate* other) {
				return other == eventDelegate;
				});

			_pendingRemoveDelegates.push_back((*result));
		}
	}

	virtual size_t GetEventCallbackCount() const override {
		return _eventCallbacks.size();
	}

private:
	EventDelegateList _eventCallbacks;
	RemoveDelegates _pendingRemoveDelegates;
	bool _locked;
};

