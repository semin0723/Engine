/////////////////////////////////////////////////
/* 
	OVERLAPPED를 상속받은 구조체를 정의해둔 곳 입니다.
*/

#ifndef _OVERLAPPED_
#define _OVERLAPPED_
#include <WinSock2.h>

class Socket;
class Session;

constexpr DWORD AddressLength = sizeof(SOCKADDR_IN) + 16;

enum class OlType {
	Accept = 1,
	Recv = 2,
	Send = 3,
};

struct OverlappedType : public OVERLAPPED {
	OlType _overlappedType;
};

struct AcceptOverlapped : public OverlappedType {
	static const UINT acceptBufferSize = 256;
	SOCKET _listen;
	Socket* _client;
	Session* _session;
	char _buffer[acceptBufferSize + AddressLength * 2]{};
	DWORD _recvByte;
};

struct SendOverlapped : public OverlappedType {
	DWORD _byteSend;
	ULL _dataSize;
	char _buffer[BufferSize];
};

struct RecvOverlapped : public OverlappedType {
	SOCKET _listen;
	DWORD _byteRecv;
	ULL _bufferSize = BufferSize;
	char _buffer[BufferSize];
};

#endif