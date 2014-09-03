#ifndef __OpcUaStackClient_ServiceTransactionRead_h__
#define __OpcUaStackClient_ServiceTransactionRead_h__

#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ReadRequest.h"
#include "OpcUaStackCore/ServiceSet/ReadResponse.h"
#include "OpcUaStackClient/ServiceSet/ServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT ServiceTransactionRead : public ObjectPool<ServiceTransactionRead>, public ServiceTransaction
	{
	  public:
		ServiceTransactionRead(void);
		~ServiceTransactionRead(void);

		RequestHeader::SPtr getRequestHeader(void);
		ResponseHeader::SPtr getResponseHeader(void);

		ReadRequest::SPtr request(void);
		ReadResponse::SPtr response(void);

		void opcUaBinaryEncodeRequest(std::ostream& os) const;
		void opcUaBinaryEncodeResponse(std::ostream& os) const;
		void opcUaBinaryDecodeRequest(std::istream& is);
		void opcUaBinaryDecodeResponse(std::istream& is);

	  private:
		ReadRequest::SPtr readRequest_;
		ReadResponse::SPtr readResponse_;
		
	};

}

#endif