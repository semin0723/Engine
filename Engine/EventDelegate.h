#pragma once

class IEvent;
typedef size_t EventDelegateId;

class IEventDelegate {
public:
	virtual inline void invoke(const IEvent* const e) = 0;
	virtual EventDelegateId GetDelegateId() const = 0;
	virtual unsigned long long GetStaticEventTypeId() const = 0;
	virtual bool operator==(const IEventDelegate* other) const = 0;
	virtual IEventDelegate* clone() = 0;
};

template<class Class, class EventType>
class EventDelegate : public IEventDelegate
{
	typedef void(Class::* Callback)(const EventType* const);

	Class* _receiver;
	Callback _callback;

public:
	EventDelegate(Class* receiver, Callback& callbackFunction) : _receiver(receiver), _callback(callbackFunction) {}

	virtual IEventDelegate* clone() override {
		return new EventDelegate(_receiver, _callback);
	}

	// 수신자의 클래스에서 콜백함수를 호출한다. 매개변수는 이벤트 타입의 클래스.
	virtual void invoke(const IEvent* const e) override {
		(_receiver->*_callback)(reinterpret_cast<const EventType* const>(e));
	}

	virtual EventDelegateId GetDelegateId() const override {
		static const EventDelegateId DELEGATE_ID	{ typeid(Class).hash_code() ^ typeid(Callback).hash_code() };
		return DELEGATE_ID;
	}

	virtual unsigned long long GetStaticEventTypeId() const override {
		static const unsigned long long eventTypeId	{ EventType::EVENT_TYPE_ID };
		return eventTypeId;
	}

	virtual bool operator==(const IEventDelegate* other) const override {
		if (GetDelegateId() != other->GetDelegateId()) return false;
		EventDelegate* delegate = (EventDelegate*)other;
		if (other == nullptr) return false;

		return ((_callback == delegate->_callback) && (_receiver == delegate->_receiver));
	}
};

