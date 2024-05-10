#pragma once

#include "ToolTexture.h"

class TexturePS4 : public ToolTexture
{
public:
	TexturePS4();
	TexturePS4( uint32_t num_mips );
	virtual ~TexturePS4();

public:
	static TexturePS4* Convert( TextureType::Type type, PixelFormat::Type pixel_format, uint32_t conversion_flags, InputImages& input_images );

	virtual void* ToARGB( uint32_t mip_level ) const;

	virtual bool DeserializeData( BinaryBufferReader* reader );

private:
	virtual void InternalSerialize( StreamWriter& writer ) const;
};
