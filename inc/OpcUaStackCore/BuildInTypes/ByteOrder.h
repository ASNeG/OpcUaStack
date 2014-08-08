#ifndef __OpcUaStackCore_ByteOrder_h__
#define __OpcUaStackCore_ByteOrder_h__

#include <stdint.h>
#include <iostream>

#ifdef WIN32

	#define BIG_ENDIAN false
	#define LITTLE_ENDIAN true

#endif

namespace OpcUaStackCore
{

	template<typename T>
      class ByteOrder 
      {
	    public:

		  static void 
		  ByteOrder::opcUaBinaryEncodeNumber(std::ostream& os, const T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  os.write((char*)&value, sizeof(T));
			  }
			  else {
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  os.write(((char*)&value)+size-1,1);
				  }
			  }
		  }

		  static void 
		  ByteOrder::opcUaBinaryDecodeNumber(std::istream& is, const T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  is.read((char*)&value, sizeof(T));
			  }
			  else {
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  is.read(((char*)&value)+size-1,1);
				  }
			  }
		  }
    };
}

#endif