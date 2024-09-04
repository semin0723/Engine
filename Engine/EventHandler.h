#pragma once
#include "IEvent.h"
#include "EventDispatcher.h"

class EventHandler
{
	// friend class main Engine
	using DispatcherKey = std::pair<std::string, EventTypeId>;
	using EventDispatcherMap = std::map<DispatcherKey, IEventDispatcher*>;

	using EventPackage = std::pair<std::string, IEvent*>;
	using EventContainer = std::vector<EventPackage>;

public:
	EventHandler();
	~EventHandler();

	void ClearEventBuffer() { _eventContainer.clear(); }
	void ClearEventDispatcher() { _eventMap.clear(); }

	template<class E, class...ARGS>
	void Send(std::string sender, ARGS&&... eventArgs) {
		_eventContainer.push_back({ std::forward<std::string>(sender), new E(std::forward<ARGS>(eventArgs)...) });
	}

	void DispatchEvents() {
		size_t end = _eventContainer.size();
		size_t start = 0;

		while (start < end) {
			EventPackage& package = _eventContainer[start++];
			if (package.second == nullptr) {
				continue;
			}

			auto iterator = _eventMap.find({ package.first, package.second->GetEventTypeId() });
			if (iterator == _eventMap.end()) {
				continue;
			}
			iterator->second->Dispatch(package.second);

			end = _eventContainer.size();
		}

		ClearEventBuffer();
	}

private:
	EventHandler(const EventHandler&);

	EventDispatcherMap _eventMap;
	EventContainer _eventContainer;

	template<class E>
	void AddEventCallback(std::string sender, IEventDelegate* const eventDelegate) {
		EventTypeId eventId = E::EVENT_TYPE_ID;
		EventDispatcherMap::const_iterator it = _eventMap.find(eventId);
		if (it == _eventMap.end()) {
			std::pair<DispatcherKey, IEventDispatcher*> dispatcher({ sender, eventId }, new EventDispatcher<E>());
			dispatcher.second->AddEventCallback(eventDelegate);
			_eventMap.insert(dispatcher);
		}
		else {
			_eventMap[{ sender, eventId }]->AddEventCallback(eventDelegate);
		}
	}

	inline void RemoveEventCallback(std::string sender, IEventDelegate* eventDelegate) {
		auto typeId = eventDelegate->GetStaticEventTypeId();
		EventDispatcherMap::const_iterator iterator = _eventMap.find({ sender, typeId });
		if (iterator != _eventMap.end()) {
			_eventMap[{ sender, typeId }]->RemoveEventCallback(eventDelegate);
		}
	}
	
	friend class ECBase;
};

