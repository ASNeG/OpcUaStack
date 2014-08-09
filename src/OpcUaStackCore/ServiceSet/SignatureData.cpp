#include "OpcUaStackCore/ServiceSet/SignatureData.h"

namespace OpcUaStackCore
{

	SignatureData::SignatureData(void)
	: signature_()
	, algorithm_()
	{
	}

	SignatureData::~SignatureData(void)
	{
	}

	void 
	SignatureData::signature(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		signature_.value(buf, bufLen);
	}

	void 
	SignatureData::signature(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		signature_.value(buf, bufLen);
	}

	void 
	SignatureData::algorithm(const std::string& algorithm)
	{
		algorithm_ = algorithm;
	}

	std::string 
	SignatureData::algorithm(void) const
	{
		return algorithm_.value();
	}

	void 
	SignatureData::opcUaBinaryEncode(std::ostream& os) const
	{
		signature_.opcUaBinaryEncode(os);
		algorithm_.opcUaBinaryEncode(os);
	}

	void 
	SignatureData::opcUaBinaryDecode(std::istream& is)
	{
		signature_.opcUaBinaryDecode(is);
		algorithm_.opcUaBinaryDecode(is);
	}

}