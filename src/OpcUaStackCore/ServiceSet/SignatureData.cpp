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
		OpcUaStackCore::opcUaBinaryEncode(os, signature_);
		OpcUaStackCore::opcUaBinaryEncode(os, algorithm_);
	}

	void 
	SignatureData::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, signature_);
		OpcUaStackCore::opcUaBinaryDecode(is, algorithm_);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const SignatureData& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, SignatureData& value)
	{
		value.opcUaBinaryDecode(is);
	}

}