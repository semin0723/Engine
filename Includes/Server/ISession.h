///////////////////////////////////////////////////////////
/*
	Ŭ���̾�Ʈ�� ������ �����ϱ� ���� ��ü �Դϴ�.
	Ŭ���̾�Ʈ�� ���ῡ �����ϸ� ������ ������ �ν��Ͻ�ȭ �մϴ�.
	������ ������ ���� Ŭ���̾�Ʈ�� �����͸� �����մϴ�.

	
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

	// ������ ���� �� �� ����ϴ� ������ ��ȯ�մϴ�.
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