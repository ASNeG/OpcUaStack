#include "OpcUaStackCore/ServiceSetApplication/NamespaceInfoRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NamespaceInfoRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	NamespaceInfoRequest::NamespaceInfoRequest(void)
	: ObjectPool<NamespaceInfoRequest>()
	{
	}

	NamespaceInfoRequest::~NamespaceInfoRequest(void)
	{
	}


	void
	NamespaceInfoRequest::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	NamespaceInfoRequest::opcUaBinaryDecode(std::istream& is)
	{
	}

}
