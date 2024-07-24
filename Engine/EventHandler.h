#pragma once
#include "IEvent.h"
#include "EventDispatcher.h"

class EventHandler
{
	// friend class main Engine
	using EventDispatcherMap = std::unordered_map<EventTypeId, IEventDispatcher*>;
	using EventContainer = std::vector<IEvent*>;

public:
	EventHandler();
	~EventHandler();

	void ClearEventBuffer() { _eventContainer.clear(); }
	void ClearEventDispatcher() { _eventMap.clear(); }

	template<class E, class...ARGS>
	void Send(ARGS&&... eventArgs) {
		_eventContainer.push_back(new E(std::forward<ARGS>(eventArgs)...));
	}

	void DispatchEvents() {
		size_t end = _eventContainer.size();
		size_t start = 0;

		while (start < end) {
			IEvent* event = _eventContainer[start++];
			if (event == nullptr) {
				continue;
			}

			auto iterator = _eventMap.find(event->GetEventTypeId());
			if (iterator == _eventMap.end()) {
				continue;
			}
			iterator->second->Dispatch(event);

			end = _eventContainer.size();
		}

		ClearEventBuffer();
	}

private:
	EventHandler(const EventHandler&);

	EventDispatcherMap _eventMap;
	EventContainer _eventContainer;

	template<class E>
	void AddEventCallback(IEventDelegate* const eventDelegate) {
		EventTypeId eventId = E::EVENT_TYPE_ID;
		EventDispatcherMap::const_iterator it = _eventMap.find(eventId);
		if (it == _eventMap.end()) {
			std::pair<EventTypeId, IEventDispatcher*> dispatcher(eventId, new EventDispatcher<E>());
			dispatcher.second->AddEventCallback(eventDelegate);
			_eventMap.insert(dispatcher);
		}
		else {
			_eventMap[eventId]->AddEventCallback(eventDelegate);
		}
	}

	inline void RemoveEventCallback(IEventDelegate* eventDelegate) {
		auto typeId = eventDelegate->GetStaticEventTypeId();
		EventDispatcherMap::const_iterator iterator = _eventMap.find(typeId);
		if (iterator != _eventMap.end()) {
			_eventMap[typeId]->RemoveEventCallback(eventDelegate);
		}
	}
	
	friend class ECBase;
};

