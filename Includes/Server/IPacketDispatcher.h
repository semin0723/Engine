/////////////////////////////////////////
// PacketDispatcher의 인터페이스 입니다.
//

/////////////////////////////////////////
/*
	packet의 이동 경로.
	session -> packetDispatcher -> logic server -> packetDispatcher -> session

	packet의 사이즈는 작지 않은 사이즈라서 일일히 동적할당을 하기엔 속도에 차이가 날 것으로 예상.
	이것은 테스트를 해봐야 알 것 같다는 생각이 든다.
	일단은 packet pool을 제작하지 않은 상태로 수행해봐야 할것 같다.

	send를 진행할 때는 packet객체가 필요하지 않습니다.
	char*의 배열만 있으면 충분히 커버 가능.

	세션의 경량화를 위해 PacketDispatcher에서 서버용, 로직용 컨테이너를 둘다 운용합니다.
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

	// 각 클라이언트로부터 받은 패킷을 저장하는 함수 입니다.
	// 저장하는 방식을 어떤식으로 진행할지는 아직 고민중입니다.
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
	// session에서 받아온 데이터를 저장할 때 사용합니다.
	PacketQueue _saveRecvContainer;
	// Logic 서버에서 데이터를 가져갈 때 사용합니다.
	PacketQueue _dispatchMessageContainer;
	// session에서 데이터를 보낼 때 사용합니다.
	SendQueueContainer _sessionSendContainer;
	// Logic 서버에서 데이터를 저장할 때 사용합니다.
	SendQueueContainer _saveSendContainer;
};

#endif