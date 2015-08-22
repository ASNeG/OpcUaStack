#ifndef __OpcUaStackCore_OpcUaGuid_h__
#define __OpcUaStackCore_OpcUaGuid_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

#include <stdint.h>

namespace OpcUaStackCore 
{

	class DLLEXPORT OpcUaGuid : public ObjectPool<OpcUaGuid>
	{
	  public:
		typedef boost::shared_ptr<OpcUaGuid> SPtr;

	    OpcUaGuid(void);
		~OpcUaGuid(void);

		void data1(OpcUaUInt32 value);
		OpcUaUInt32 data1(void) const;
		void data2(OpcUaUInt16 value);
		OpcUaUInt16 data2(void) const;
		void data3(OpcUaUInt16 value);
		OpcUaUInt16 data3(void) const;
		void data4(OpcUaByte value[8]);
		OpcUaByte* data4(void) const;

		OpcUaGuid& operator=(const std::string& string); 
		operator std::string const (void); 

		void copyTo(OpcUaGuid& opcUaGuid);
		bool operator<(const OpcUaGuid& opcUaGuid) const;

		bool operator!=(const OpcUaGuid& opcUaGuid) const;
		bool operator==(const OpcUaGuid& opcUaGuid) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaGuid& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);

	  private:
		OpcUaUInt32 data1_;
		OpcUaUInt16 data2_;
		OpcUaUInt16 data3_;
		OpcUaByte data4_[8];
	};

	class OpcUaGuidArray : public OpcUaArray<OpcUaGuid::SPtr, SPtrTypeCoder<OpcUaGuid> >, public ObjectPool<OpcUaGuidArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaGuidArray> SPtr;
	};

}

#endif
