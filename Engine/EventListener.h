#pragma once
#include "EventDelegate.h"
#include "EventHandler.h"
#include "ECMain.h"

class EventListener
{
	using RegisteredCallbacks = std::list<IEventDelegate*>;
	RegisteredCallbacks _callbacks;

public:
	EventListener();
	virtual ~EventListener();

	template<class E, class C>
	void RegisterCallback(std::string sender, void(C::* Callback)(const E* const)) {
		IEventDelegate* newDelegate = new EventDelegate<C, E>(static_cast<C*>(this), Callback);

		_callbacks.push_back(newDelegate);
		Engine->SubscribeEvent<E>(sender, newDelegate);
	}

	template<class E, class C>
	void UnRegisterCallback(std::string sender, void(C::* Callback)(const E* const)) {
		EventDelegate<C, E> delegate(static_cast<C*>(this), Callback);

		for (auto callback : _callbacks) {
			if (callback->GetDelegateId() == delegate.GetDelegateId()) {
				_callbacks.remove_if([&](const IEventDelegate* other) {
					return other == callback;
					}
				);
				Engine->UnSubscribeEvent(sender, &delegate);
				break;
			}
		}
	}

	void UnRegisterAllCallbacks();

private:

};

