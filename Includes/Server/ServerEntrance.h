#pragma once
#include "DLLSetting.h"
#include "GlobalDef.h"
#include "IPacketDispatcher.h"
#include <string>

class NetworkMain;
class PacketDispatcher;


extern NetworkMain* _mainEntrance;

namespace Server {
	extern PacketDispatcher* _packetDispatcherInstance;

	bool SERVER_API Initialize();
	void SERVER_API Finalize();
	void SERVER_API SavePacketData(std::string msg, SessionID sid, short packetId);
	SERVER_API PacketQueue* GetPacketContainer();
	bool SERVER_API SwapPacketContainer();
	void SERVER_API SendUpdate();
	void SERVER_API BroadCast(std::string msg, short packetId);

}