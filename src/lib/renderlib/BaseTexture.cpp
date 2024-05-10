#include "BaseTexture.h"

const char magic[4] = {'K', 'T', 'E', 'X'};

void BaseTexture::Serialize( StreamWriter& writer ) const
{
	for (int i = 0; i < 4; i++)
		writer.WriteByte( magic[i] );

	writer.WriteInt( mMetaData_Int );

	for (int i = 0; i < mMetaData.mNumMips; i++) {
		sMipDescription *desc = &mMipDescriptions[i];

		writer.WriteShort( desc->mWidth );
	    writer.WriteShort( desc->mHeight );
	    writer.WriteShort( desc->mPitch );
	    writer.WriteInt( desc->mDataSize );
	}

	InternalSerialize( writer );
}
