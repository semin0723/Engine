//////////////////////////////////////////////////////////
/*
	PacketDispatcher �Դϴ�.
	�� Ŭ������ session���κ��� ���� ��Ŷ�� �����ϰų�,
	���� ���̵忡�� ������ ��Ŷ�� �����ϴ� ���Դϴ�.



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
	// logic server���� ���� �޽��� �����̳ʸ� ������ �� ����մϴ�.
	PacketQueue* GetMessageContainer() override;
	// session���� ���� �޽��� �����̳ʸ� ������ �� ����մϴ�.
	SendQueue* GetSendMessageContainer(SessionID sid) override;
	void SessionCreated(SessionID sid) override;

	void SaveBroadCastPacket(std::string& data, short packetId) override;

	void MakePacket(Packet& packet, std::string& data, SessionID sid, short packetId) override;
private:
	std::mutex _recvMtx;
	std::mutex _sendMtx;
};

