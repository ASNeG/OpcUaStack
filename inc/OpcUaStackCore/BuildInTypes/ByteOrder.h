#ifndef __OpcUaStackCore_ByteOrder_h__
#define __OpcUaStackCore_ByteOrder_h__

#include <stdint.h>
#include <iostream>

#ifdef WIN32

	static uint32_t number;
	#define BIG_ENDIAN ((*(char*)&number) != 1)
	#define LITTLE_ENDIAN ((*(char*)&number) == 1)

#endif

namespace OpcUaStackCore
{

	template <typename T>
		void 
		opcUaBinaryEncodeNumber(std::ostream& os, const T& value)
		{
			if (LITTLE_ENDIAN) {
				os.write((char*)&value, sizeof(T));
			}
			else {
				for (uint32_t size=sizeof(T); size>0; size++) {
					os.write(((char*)&value)+size-1,1);
				}
			}
		}

	template <typename T>
		void 
		opcUaBinaryDecodeNumber(std::istream& is, const T& value)
		{
			if (LITTLE_ENDIAN) {
				is.read((char*)&value, sizeof(T));
			}
			else {
				for (uint32_t size=sizeof(T); size>0; size++) {
					is.read(((char*)&value)+size-1,1);
				}
			}
		}

}

#endif