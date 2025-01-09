#pragma once
#include "ISession.h"

class StreamBuffer;

class Session : public ISession
{
public:
	Session() = default;
	~Session() = default;

	void Initialize(Socket* socket) override;
	bool SendUpdate() override;
	bool RecvUpdate() override;
	Socket* Release() override;

	const SessionID GetSessionID() const override;
private:
	friend class NetworkMain;
};
