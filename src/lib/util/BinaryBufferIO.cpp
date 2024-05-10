#include "BinaryBufferIO.h"
#include <algorithm>
#include <cstring>

BinaryBufferReader::BinaryBufferReader( uint32_t file_size, const char* file_data )
{
	offset = 0;
	data = file_data;
	size = file_size;
};

uint32_t BinaryBufferReader::ReadBytes( uint32_t size, void *data )
{
	uint32_t len = std::min( size, this->size - offset );

	memcpy( data, this->data + offset, len );
	offset += len;
	return len;
}

BinaryBufferWriter::BinaryBufferWriter( std::vector<char>& buffer )
: buffer(buffer)
{
}

void BinaryBufferWriter::WriteBytes( uint32_t size, const void *data )
{
	buffer.reserve( buffer.size() + size );
	buffer.insert( buffer.end(), (char *)data, &((char *)data)[size] );
}

void BinaryBufferWriter::WriteByte( uint8_t byte )
{
	WriteBytes( 1, (void *)&byte );
}

GrowableBinaryBufferWriter::GrowableBinaryBufferWriter( std::vector<char>& buffer )
: BinaryBufferWriter(buffer)
{
}

void GrowableBinaryBufferWriter::WriteInt( uint32_t val )
{
	WriteBytes( 4, (void *)&val );
}

void GrowableBinaryBufferWriter::WriteShort( uint16_t val )
{
	WriteBytes( 2, (void *)&val );
}

GrowableEndianSwappedBinaryBufferWriter::GrowableEndianSwappedBinaryBufferWriter( std::vector<char>& buffer )
: BinaryBufferWriter(buffer)
{
}

void GrowableEndianSwappedBinaryBufferWriter::WriteInt( uint32_t val )
{
	val = __builtin_bswap32( val );
	WriteBytes( 4, (void *)&val );
}

void GrowableEndianSwappedBinaryBufferWriter::WriteShort( uint16_t val )
{
	val = __builtin_bswap16( val );
	WriteBytes( 2, (void *)&val );
}
