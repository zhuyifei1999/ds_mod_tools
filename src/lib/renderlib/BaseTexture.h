#ifndef RENDERLIB_BASETEXTURE_H
#define RENDERLIB_BASETEXTURE_H

#include <cstdint>
#include <util/BinaryBufferIO.h>
#include <renderlib/texture_enums.h>
#include <systemlib/platform.h>

class BaseTexture
{
public:
	struct sMipDescription {
		uint16_t mWidth;
		uint16_t mHeight;
		uint16_t mPitch;
		uint32_t mDataSize;
		const void *mData;
	};

	struct sMetaData {
		ePlatform mPlatform : 4;
		PixelFormat::Type mPixelFormat : 5;
		TextureType::Type mTextureType : 4;
		uint32_t mNumMips : 5;
		bool mFlags : 2;
		uint32_t fill : 12;
	};

	union {
		sMetaData mMetaData;
		uint32_t mMetaData_Int;
	};

	sMipDescription *mMipDescriptions;

	BaseTexture()
	{
		mMetaData_Int = -1U;
	}

	PixelFormat::Type PixelFormat() const
	{
		return mMetaData.mPixelFormat;
	}
	ePlatform Platform() const
	{
		return mMetaData.mPlatform;
	}
	int NumMips() const
	{
		return mMetaData.mNumMips;
	}
	const sMipDescription& GetMipDescription( int mip_level ) const
	{
		return mMipDescriptions[mip_level];
	}

	void Serialize( StreamWriter& writer ) const;

	void DeserializeHeader( BinaryBufferReader& reader, int );
	virtual bool DeserializeData( BinaryBufferReader* reader ) = 0;
	virtual void InternalSerialize( StreamWriter& writer ) const = 0;
};

#endif
