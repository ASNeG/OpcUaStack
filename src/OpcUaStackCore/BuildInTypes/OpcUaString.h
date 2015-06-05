#ifndef __OpcUaStackCore_OpcUaString_h__
#define __OpcUaStackCore_OpcUaString_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include <string>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaString : public ObjectPool<OpcUaString>
	{
	  public:
		typedef boost::shared_ptr<OpcUaString> SPtr;

	    OpcUaString(void);
	    OpcUaString(const std::string& value);
		~OpcUaString(void);

		std::string value(void) const;
		void value(const std::string& value);
		uint32_t size(void) const;
		void reset(void);
		bool exist(void) const;

		OpcUaString& operator=(const std::string& string); 
		operator std::string const (void); 

		void copyTo(OpcUaString& opcUaString);
		bool operator<(const OpcUaString& opcUaString) const;
		bool operator!=(const OpcUaString& opcUaString) const;
		bool operator==(const OpcUaString& opcUaString) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaString& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		bool exist_;
		std::string value_; 
	};

	class OpcUaStringArray : public OpcUaArray<OpcUaString::SPtr, SPtrTypeCoder<OpcUaString> >, public ObjectPool<OpcUaStringArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaStringArray> SPtr;
	};

}

#endif
