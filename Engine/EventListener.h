#pragma once
#include "EventDelegate.h"
#include "EventHandler.h"

class EventListener
{
	using RegisteredCallbacks = std::list<IEventDelegate*>;
	RegisteredCallbacks _callbacks;

public:
	EventListener();
	virtual ~EventListener();

	template<class E, class C>
	void RegisterCallback(std::string sender, void(C::* Callback)(const E* const));

	template<class E, class C>
	void UnRegisterCallback(std::string sender, void(C::* Callback)(const E* const));

	void UnRegisterAllCallbacks();

private:

};

