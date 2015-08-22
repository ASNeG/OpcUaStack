#ifndef __OpcUaStackCore_OpcUaByteString_h__
#define __OpcUaStackCore_OpcUaByteString_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaByteString : public ObjectPool<OpcUaByteString>
	{
	  public:
		typedef boost::shared_ptr<OpcUaByteString> SPtr;

	    OpcUaByteString(void);
		~OpcUaByteString(void);

		void value(OpcUaByte** value, OpcUaInt32* lenth) const;
		void value(char** value, OpcUaInt32* lenth) const;
		void value(const OpcUaByte* value, OpcUaInt32 length);
		void value(const char* value, OpcUaInt32 length);
		void value(const std::string& value);
		OpcUaInt32 size(void) const;
		void reset(void);
		bool exist(void) const;

		std::string toHexString(void) const;
		OpcUaByteString& operator=(const std::string& string); 
		operator std::string const (void); 

		void copyTo(OpcUaByteString& opcUaByteString);
		bool operator<(const OpcUaByteString& opcUaByteString) const;
		bool operator!=(const OpcUaByteString& opcUaByteString) const;
		bool operator==(const OpcUaByteString& opcUaByteString) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaByteString& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);

	  private:
		OpcUaInt32 length_;
		OpcUaByte* value_; 
	};

	class OpcUaByteStringArray : public ObjectPool<OpcUaByteStringArray>, public OpcUaArray<OpcUaByteString::SPtr, SPtrTypeCoder<OpcUaByteString> > 
	{
	  public:
		typedef boost::shared_ptr<OpcUaByteStringArray> SPtr;
	};

}

#endif
