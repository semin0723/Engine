#pragma once
class StreamBuffer
{
public:
	StreamBuffer();
	~StreamBuffer();

	bool Peek(char* buffer, int len) const;
	int Read(char* buffer, int len);
	int Write(const char* data, int len);

	int Size() const;
	int Space() const;
	bool Empty();
	bool Full();
	void BufferClear();

private:
	int _bufferSize;
	// 버퍼내 존재하는 데이터의 크기를 나타냅니다.
	int _dataSize{ 0 };
	// 버퍼를 읽을 때 시작지점입니다.
	int _readIdx{ 0 };
	// 버퍼에 쓸 때 시작지점입니다.
	int _writeIdx{ 0 };
	char* _buffer = nullptr;
};