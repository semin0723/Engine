/////////////////////////////////////////////////
/*
	��Ŷ�� ���� ������ ������ ���Դϴ�.

	��Ŷ�� ��ü���� ����ȭ�� �����Ͱ� ���� �˴ϴ�.

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

