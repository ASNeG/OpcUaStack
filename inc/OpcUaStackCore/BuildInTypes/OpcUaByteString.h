#ifndef __OpcUaStackCore_OpcUaByteString_h__
#define __OpcUaStackCore_OpcUaByteString_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaByteString : public ObjectPool<OpcUaByteString>
	{
	  public:
	    OpcUaByteString(void);
		~OpcUaByteString(void);

		void value(OpcUaByte** value, OpcUaInt32* lenth);
		void value(char** value, OpcUaInt32* lenth);
		void value(const OpcUaByte* value, OpcUaInt32 length);
		void value(const char* value, OpcUaInt32 length);
		void value(const std::string& value);
		uint32_t size(void) const;
		void reset(void);
		bool exist(void) const;

		OpcUaByteString& operator=(const std::string& string); 
		operator std::string const (void); 

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaInt32 length_;
		OpcUaByte* value_; 
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaByteString& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaByteString& value);
}

#endif