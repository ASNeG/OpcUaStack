#include "OpcUaStackCore/ServiceSetApplication/NamespaceInfoResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NamespaceInfoResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NamespaceInfoResponse::NamespaceInfoResponse(void)
	: ObjectPool<NamespaceInfoResponse>()
	, index2NamespaceMap_()
	, namespace2IndexMap_()
	{
	}

	NamespaceInfoResponse::~NamespaceInfoResponse(void)
	{
	}

	NamespaceInfoResponse::Index2NamespaceMap&
	NamespaceInfoResponse::index2NamespaceMap(void)
	{
		return index2NamespaceMap_;
	}

	NamespaceInfoResponse::Namespace2IndexMap&
	NamespaceInfoResponse::namespace2IndexMap(void)
	{
		return namespace2IndexMap_;
	}

	void
	NamespaceInfoResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		//nodeReferenceArray_->opcUaBinaryEncode(os);
	}

	void
	NamespaceInfoResponse::opcUaBinaryDecode(std::istream& is)
	{
		//nodeReferenceArray_->opcUaBinaryDecode(is);
	}
}



