///////////////////////////////////////////////////////////
/*
	클라이언트와 연결을 유지하기 위한 객체 입니다.
	클라이언트와 연결에 성공하면 서버는 세션을 인스턴스화 합니다.
	서버는 세션을 통해 클라이언트에 데이터를 전송합니다.

	
*/

#ifndef _ISESSION_
#define _ISESSION_
#include "GlobalDef.h"
#include "Overlapped.h"

class Socket;
class StreamBuffer;
class PacketDispatcher;

class ISession {
public:
	ISession() : _sessionId(++_sid) {}
	virtual ~ISession() = default;
	virtual void Initialize(Socket* socket) = 0;
	virtual bool SendUpdate() = 0;
	virtual bool RecvUpdate() = 0;

	// 세션을 제거 할 때 사용하던 소켓을 반환합니다.
	virtual Socket* Release() = 0;

	virtual const SessionID GetSessionID() const = 0;
protected:
	static SessionID _sid;

	Socket* _socket = nullptr;
	SessionID _sessionId = -1;
	StreamBuffer* _saveRecvData = nullptr;
	PacketDispatcher* _packetDispatcherInstance = nullptr;

	SendOverlapped _sendOl{};
	RecvOverlapped _recvOl{};
};

#endif