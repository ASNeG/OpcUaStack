#ifndef __OpcUaStackCore_OpcUaDateTime_h__
#define __OpcUaStackCore_OpcUaDateTime_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/os.h"
#include "boost/date_time/posix_time/posix_time.hpp"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaDateTime
	{
	  public:
		OpcUaDateTime(void);
		~OpcUaDateTime(void);

		void dateTime(const boost::posix_time::ptime& dateTime);
		boost::posix_time::ptime dateTime(void) const;
		bool exist(void) const;

		OpcUaDateTime& operator=(const OpcUaUInt64& dateTime); 
		operator OpcUaUInt64 const (void); 
		bool fromISOString(const std::string& dateTimeString);
		std::string toISOString(void);

		void copyTo(OpcUaDateTime& opcUaDataTime);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDateTime& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		static boost::posix_time::ptime nullTime_;
		OpcUaUInt64 dateTime_;
	};

	class OpcUaDateTimeArray : public OpcUaArray<OpcUaDateTime>, public ObjectPool<OpcUaDateTimeArray> {};
	
};

#endif
