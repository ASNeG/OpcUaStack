#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

#define BIG_ENDIAN ((*(char*)&number) != 1)
#define LITTLE_ENDIAN ((*(char*)&number) == 1)

namespace OpcUaStackCore
{

	static uint32_t number = 1;

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value)
	{
		os.write((char*)&value, 1);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value)
	{	
		is.read((char*)&value, 1);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value)
	{	
		os.write((char*)&value, 1);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaSByte& value)
	{	
		is.read((char*)&value, 1);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value)
	{	
		os.write((char*)&value, 1);
	}

	void
	opcUaBinaryDecode(std::istream& is, OpcUaByte& value)
	{	
		is.read((char*)&value, 1);
	}

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

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt16& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt32& value)
	{
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt64& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaFloat& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}


	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDouble& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

}
