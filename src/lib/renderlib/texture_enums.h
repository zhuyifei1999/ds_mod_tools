#ifndef RENDERLIB_TEXTURE_ENUMS_H
#define RENDERLIB_TEXTURE_ENUMS_H

namespace PixelFormat
{
	enum Type
	{
		BC1 = 0,
		BC2 = 1,
		BC3 = 2,
		X8R8G8B8 = 3,
		A8R8G8B8 = 4,
		R8G8B8 = 5,
		L16 = 6,
		A8 = 7,
		ATITC_RGB = 8,
		ATITC_RGBA_EXP = 9,
		ATITC_RGBA_INT = 10,
		PVRTC_RGB_4 = 11,
		PVRTC_RGB_2 = 12,
		PVRTC_RGBA_4 = 13,
		PVRTC_RGBA_2 = 14,
		// missing = 15,
		UNKNOWN = 16,
	};
}

namespace TextureType
{
	enum Type
	{
		D1 = 0,
		D2 = 1,
		D3 = 2,
		CubeMap = 3,
	};
}

#endif
