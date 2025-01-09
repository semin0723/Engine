#pragma once
#include "ISocket.h"

class Socket : public ISocket
{
public:
	Socket() = default;
	virtual ~Socket() override = default;
	bool Open(int protocol) override;
	bool Bind(SOCKADDR_IN& addr) override;
	bool Connect(SOCKADDR_IN& addr) override;
	bool Listen() override;
	void Close() override;
	SOCKET Accept() override;
	bool AcceptExtend(AcceptOverlapped& overlapped) override;
	bool Recv(RecvOverlapped& overlapped) override;
	bool Send(SendOverlapped& overlapped) override;
	int Recv(char* buffer) override;
	int Send(char* buffer, int len) override;

	const SOCKET GetSocket() const { return _socket; }
private:
	Socket(Socket&) = delete;
	Socket& operator=(Socket&) = delete;
};

