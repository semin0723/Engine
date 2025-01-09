//////////////////////////////////////////////////////////
/*
	PacketDispatcher 입니다.
	이 클래스는 session으로부터 받은 패킷을 저장하거나,
	로직 사이드에서 생성된 패킷을 저장하는 곳입니다.



*/

#pragma once
#include "IPacketDispatcher.h"
#include "Singleton.h"

class PacketDispatcher : public IPacketDispatcher
{
	DeclSingleton(PacketDispatcher)

public:
	PacketDispatcher() = default;
	~PacketDispatcher() = default;

	void SaveRecvPacket(StreamBuffer* recvData, SessionID sid) override;
	bool SwapRecvPacketContainer() override;
	void SaveSendPacket(std::string& data, SessionID sid, short packetId) override;
	bool SwapSendPacketContainer(SessionID sid) override;
	// logic server에서 보낼 메시지 컨테이너를 가져갈 때 사용합니다.
	PacketQueue* GetMessageContainer() override;
	// session에서 보낼 메시지 컨테이너를 가져갈 때 사용합니다.
	SendQueue* GetSendMessageContainer(SessionID sid) override;
	void SessionCreated(SessionID sid) override;

	void SaveBroadCastPacket(std::string& data, short packetId) override;

	void MakePacket(Packet& packet, std::string& data, SessionID sid, short packetId) override;
private:
	std::mutex _recvMtx;
	std::mutex _sendMtx;
};

