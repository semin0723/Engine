/////////////////////////////////////////////////
/*
	패킷의 공용 구조를 정의한 곳입니다.

	패킷의 본체에는 직렬화된 데이터가 들어가게 됩니다.

*/

#ifndef _PACKET_
#define _PACKET_

#pragma pack(push, 1)
struct PacketHeader {
	static char _packetSeqNum;
	short sessionId;
	short _packetId;
	short _packetSize;
	char _packetSeq = ++_packetSeqNum;
};

struct Packet : public PacketHeader {
	static const short BufferSize = 256;
	char _data[BufferSize]{};
};

#pragma pack(pop)

#endif

