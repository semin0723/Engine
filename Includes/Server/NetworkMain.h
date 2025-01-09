#pragma once
#include "GlobalDef.h"
#include "Overlapped.h"


class Socket;
class Session;
class PacketDispatcher;

using CompletionPortContainer = std::vector<HANDLE>;
using SessionMap = std::unordered_map<SessionID, Session*>;
using AcceptOverlappedContainer = std::vector<AcceptOverlapped>;

#define SEND DWMAX - 1

class NetworkMain
{
public:
	NetworkMain() = default;
	~NetworkMain() = default;

	bool Initialize();
	void SendUpdate();
	void Finalize();

private:
	CompletionPortContainer _cpContainer;
	SessionMap _sessionMap;
	SOCKADDR_IN _serverAddr;
	Socket* _listen = nullptr;
	Socket* _client1 = nullptr;
	Socket* _client2 = nullptr;
	
	AcceptOverlapped _acceptOverlapped1;
	AcceptOverlapped _acceptOverlapped2;
	std::queue<AcceptOverlapped*> _acceptOlContainer;

	std::mutex _sessionMtx;

	void IOWork(HANDLE completionPort);
	bool CreateWaitingSession();
};

