#include "OpcUaStackClient/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackClient
{

	ServiceTransactionRead::ServiceTransactionRead(void)
	: ServiceTransaction(OpcUaId_ReadRequest_Encoding_DefaultBinary, OpcUaId_ReadResponse_Encoding_DefaultBinary)
	{
	}

	ServiceTransactionRead::~ServiceTransactionRead(void)
	{
	}

	RequestHeader::SPtr 
	ServiceTransactionRead::getRequestHeader(void)
	{
		return readRequest_->requestHeader();
	}

	ResponseHeader::SPtr 
	ServiceTransactionRead::getResponseHeader(void)
	{
		return readResponse_->responseHeader();
	}

	void 
	ServiceTransactionRead::opcUaBinaryEncodeRequest(std::ostream& os) const
	{
		readRequest_->opcUaBinaryEncode(os);
	}

	void 
	ServiceTransactionRead::opcUaBinaryEncodeResponse(std::ostream& os) const
	{
		readResponse_->opcUaBinaryEncode(os);
	}

	void 
	ServiceTransactionRead::opcUaBinaryDecodeRequest(std::istream& is)
	{
		readRequest_->opcUaBinaryDecode(is);
	}

	void 
	ServiceTransactionRead::opcUaBinaryDecodeResponse(std::istream& is)
	{
		readResponse_->opcUaBinaryDecode(is);
	}

}