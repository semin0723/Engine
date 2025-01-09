/////////////////////////////////////////
// PacketDispatcher�� �������̽� �Դϴ�.
//

/////////////////////////////////////////
/*
	packet�� �̵� ���.
	session -> packetDispatcher -> logic server -> packetDispatcher -> session

	packet�� ������� ���� ���� ������� ������ �����Ҵ��� �ϱ⿣ �ӵ��� ���̰� �� ������ ����.
	�̰��� �׽�Ʈ�� �غ��� �� �� ���ٴ� ������ ���.
	�ϴ��� packet pool�� �������� ���� ���·� �����غ��� �Ұ� ����.

	send�� ������ ���� packet��ü�� �ʿ����� �ʽ��ϴ�.
	char*�� �迭�� ������ ����� Ŀ�� ����.

	������ �淮ȭ�� ���� PacketDispatcher���� ������, ������ �����̳ʸ� �Ѵ� ����մϴ�.
*/


#ifndef _IPACKETDISPATCHER_
#define _IPACKETDISPATCHER_
#include "GlobalDef.h"
#include "Packet.h"

struct Packet;
class StreamBuffer;

using PacketQueue = std::queue<Packet>;
using SendQueue = std::queue<Packet>;
using SendQueueContainer = std::unordered_map<SessionID, SendQueue>;

class IPacketDispatcher {
public:
	virtual ~IPacketDispatcher() = default;

	// �� Ŭ���̾�Ʈ�κ��� ���� ��Ŷ�� �����ϴ� �Լ� �Դϴ�.
	// �����ϴ� ����� ������� ���������� ���� ������Դϴ�.
	virtual void SaveRecvPacket(StreamBuffer* recvData, SessionID sid) = 0;
	virtual bool SwapRecvPacketContainer() = 0;
	virtual void SaveSendPacket(std::string& data, SessionID sid, short packetId) = 0;
	virtual bool SwapSendPacketContainer(SessionID sid) = 0;
	virtual PacketQueue* GetMessageContainer() = 0;
	virtual SendQueue* GetSendMessageContainer(SessionID sid) = 0;
	virtual void SaveBroadCastPacket(std::string& data, short packetId) = 0;

	virtual void SessionCreated(SessionID sid) = 0;

	virtual void MakePacket(Packet& packet, std::string& data, SessionID sid, short packetId) = 0;
protected:
	// session���� �޾ƿ� �����͸� ������ �� ����մϴ�.
	PacketQueue _saveRecvContainer;
	// Logic �������� �����͸� ������ �� ����մϴ�.
	PacketQueue _dispatchMessageContainer;
	// session���� �����͸� ���� �� ����մϴ�.
	SendQueueContainer _sessionSendContainer;
	// Logic �������� �����͸� ������ �� ����մϴ�.
	SendQueueContainer _saveSendContainer;
};

#endif