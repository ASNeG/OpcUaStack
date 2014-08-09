#ifndef __OpcUaStackCore_OpcUaGuid_h__
#define __OpcUaStackCore_OpcUaGuid_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

#include <stdint.h>

namespace OpcUaStackCore 
{

	class DLLEXPORT OpcUaGuid : public ObjectPool<OpcUaGuid>
	{
	  public:
	    OpcUaGuid(void);
		~OpcUaGuid(void);

		void data1(OpcUaUInt32 value);
		OpcUaUInt32 data1(void);
		void data2(OpcUaUInt16 value);
		OpcUaUInt16 data2(void);
		void data3(OpcUaUInt16 value);
		OpcUaUInt16 data3(void);
		void data4(OpcUaByte value[8]);
		OpcUaByte* data4(void);

		OpcUaGuid& operator=(const std::string& string); 
		operator std::string const (void); 

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 data1_;
		OpcUaUInt16 data2_;
		OpcUaUInt16 data3_;
		OpcUaByte data4_[8];
	};

	class OpcUaGuidArray : public OpcUaArray<OpcUaGuid::SPtr, SPtrTypeCoder<OpcUaGuid> >, public ObjectPool<OpcUaGuidArray> {};

}

#endif