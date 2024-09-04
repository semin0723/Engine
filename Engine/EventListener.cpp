#include "pch.h"
#include "EventListener.h"
#include "ECMain.h"

EventListener::EventListener()
{
}

EventListener::~EventListener()
{
	UnRegisterAllCallbacks();
}

template<class E, class C>
void EventListener::RegisterCallback(std::string sender, void(C::* Callback)(const E* const)) {
	IEventDelegate* newDelegate = new EventDelegate<C, E>(static_cast<C*>(this), Callback);

	_callbacks.push_back(newDelegate);
	Engine->SubscribeEvent<E>(sender, newDelegate);
}

template<class E, class C>
void EventListener::UnRegisterCallback(std::string sender, void(C::* Callback)(const E* const)) {
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

void EventListener::UnRegisterAllCallbacks()
{
	//for (auto& delegate : _callbacks) {
	//	Engine->UnSubscribeEvent(delegate);
	//}
	_callbacks.clear();
}
