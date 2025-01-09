#pragma once
#include "GlobalDef.h"
#include "Overlapped.h"

class Socket;
class StreamBuffer;
class PacketDispatcher;

class ClientNetwork
{
public:
	ClientNetwork() = default;
	~ClientNetwork() = default;

	bool Initialize();
	bool ConnectToServer();
	int RecvUpdate();
	int SendUpdate();

	// 서버에게서 종료 패킷이 날아오면 호출 해야 합니다.
	void Finalize();


private:
	Socket* _server = nullptr;
	SOCKADDR_IN _serverAddr{};

	char* _recvData = nullptr;
	int _sendDataSize = 0;
	char* _sendData = nullptr;
	StreamBuffer* _saveRecvData = nullptr;
	PacketDispatcher* _packetDispatcherInstance = nullptr;

	std::thread _recvThread;
};

