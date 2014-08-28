#ifndef __OpcUaStackCore_HistoryReadRequest_h__
#define __OpcUaStackCore_HistoryReadRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadValueId.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	typedef enum {
		TimestampsToReturn_Source = 0,
		TimestampsToReturn_Server = 1,
		TimestampsToReturn_Both = 2,
		TimestampsToReturn_Neither = 3
	} TimestampsToReturn;

	class DLLEXPORT HistoryReadRequest : public  ObjectPool<HistoryReadRequest>
	{
	  public:
		HistoryReadRequest(void);
		virtual ~HistoryReadRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void historyReadDetails(const ExtensibleParameter::SPtr historyReadDetails);
		ExtensibleParameter::SPtr historyReadDetails(void) const;
		void timestampsToReturn(const TimestampsToReturn timestampsToReturn);
		TimestampsToReturn timestampsToReturn(void);
		void releaseContinuationPoints(const OpcUaBoolean& releaseContinuationPoints);
		OpcUaBoolean releaseContinuationPoints(void);
		void nodesToRead(const HistoryReadValueIdArray::SPtr nodesToRead);
		HistoryReadValueIdArray::SPtr nodesToRead(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		ExtensibleParameter::SPtr historyReadDetailsSPtr_;
		TimestampsToReturn timestampsToReturn_;
		OpcUaBoolean releaseContinuationPoints_;
		HistoryReadValueIdArray::SPtr nodesToReadArraySPtr_;
	};

}

#endif