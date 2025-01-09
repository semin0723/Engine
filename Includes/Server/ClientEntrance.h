#pragma once
#include "DLLSetting.h"
#include "GlobalDef.h"
#include "IPacketDispatcher.h"
#include <string>

class ClientNetwork;
class PacketDispatcher;


extern ClientNetwork* _mainEntrance;

namespace Client {
	extern PacketDispatcher* _packetDispatcherInstance;

	bool SERVER_API Initialize();
	bool SERVER_API ConnectToServer();

	bool SERVER_API SwapPacketContainer();
	SERVER_API PacketQueue* GetPacketContainer();
	void SERVER_API SavePacketData(std::string msg, short packetId);

	//void SERVER_API RecvUpdate();
	void SERVER_API SendUpdate();
	void SERVER_API Finalize();
}

