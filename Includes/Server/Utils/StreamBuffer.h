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
	// ���۳� �����ϴ� �������� ũ�⸦ ��Ÿ���ϴ�.
	int _dataSize{ 0 };
	// ���۸� ���� �� ���������Դϴ�.
	int _readIdx{ 0 };
	// ���ۿ� �� �� ���������Դϴ�.
	int _writeIdx{ 0 };
	char* _buffer = nullptr;
};