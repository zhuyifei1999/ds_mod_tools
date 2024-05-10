#ifndef UTIL_BINARYBUFFERIO_H
#define UTIL_BINARYBUFFERIO_H

#include <cstdint>
#include <vector>

class BinaryBufferReader
{
public:
	BinaryBufferReader( uint32_t file_size, const char* file_data );
	uint32_t ReadBytes( uint32_t size, void *data );

private:
	uint32_t offset;
	const char* data;
	uint32_t size;
};

class StreamWriter
{
public:
	virtual void WriteBytes( uint32_t size, const void *data ) = 0;
	virtual void WriteByte( uint8_t byte ) = 0;
	virtual void WriteInt( uint32_t val ) = 0;
	virtual void WriteShort( uint16_t val ) = 0;
};

class BinaryBufferWriter : public StreamWriter
{
public:
	BinaryBufferWriter( std::vector< char >& buffer );
	void WriteBytes( uint32_t size, const void *data );
	void WriteByte( uint8_t byte );
protected:
	std::vector< char >& buffer;
};

class GrowableBinaryBufferWriter : public BinaryBufferWriter
{
public:
	GrowableBinaryBufferWriter( std::vector< char >& buffer );
	void WriteInt( uint32_t val );
	void WriteShort( uint16_t val );
};

class GrowableEndianSwappedBinaryBufferWriter : public BinaryBufferWriter
{
public:
	GrowableEndianSwappedBinaryBufferWriter( std::vector< char >& buffer );
	void WriteInt( uint32_t val );
	void WriteShort( uint16_t val );
};


#endif
