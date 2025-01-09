/////////////////////////////////////
// Socket 클래스의 인터페이스 입니다.				
// 

#ifndef ISOCKET
#define ISOCKET
#include "GlobalDef.h"
#include "Overlapped.h"

class ISocket {
public:
	ISocket() = default;
	virtual ~ISocket() = default;
	virtual bool Open(int protocol) = 0;
	virtual bool Bind(SOCKADDR_IN& addr) = 0;
	virtual bool Listen() = 0;
	virtual void Close() = 0;
	virtual bool Connect(SOCKADDR_IN& addr) = 0;
	virtual SOCKET Accept() = 0;
	virtual bool AcceptExtend(AcceptOverlapped& overlapped) = 0;
	virtual bool Recv(RecvOverlapped& overlapped) = 0;
	virtual bool Send(SendOverlapped& overlapped) = 0;
	virtual int Recv(char* buffer) = 0;
	virtual int Send(char* buffer, int len) = 0;
protected:
	SOCKET _socket = INVALID_SOCKET;

	WSABUF _recv;
	WSABUF _send;

private:
	ISocket(ISocket&) = delete;
	ISocket& operator=(ISocket&) = delete;
};

#endif