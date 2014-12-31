#ifndef __OpcUaStackCore_HistoryUpdateRequest_h__
#define __OpcUaStackCore_HistoryUpdateRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadValueId.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryUpdateRequest : public  ObjectPool<HistoryUpdateRequest>
	{
	  public:
		typedef boost::shared_ptr<HistoryUpdateRequest> SPtr;

		HistoryUpdateRequest(void);
		virtual ~HistoryUpdateRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void historyUpdateDetails(const ExtensibleParameter::SPtr historyUpdateDetails);
		ExtensibleParameter::SPtr historyUpdateDetails(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		ExtensibleParameter::SPtr historyUpdateDetailsSPtr_;
	};

}

#endif