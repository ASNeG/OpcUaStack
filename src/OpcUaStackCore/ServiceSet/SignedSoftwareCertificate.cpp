#include "OpcUaStackCore/ServiceSet/SignedSoftwareCertificate.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SignedSoftwareCertificate
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SignedSoftwareCertificate::SignedSoftwareCertificate(void)
	{
	}

	SignedSoftwareCertificate::~SignedSoftwareCertificate(void)
	{
	}

	void 
	SignedSoftwareCertificate::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void 
	SignedSoftwareCertificate::opcUaBinaryDecode(std::istream& is)
	{
	}
	
	void 
	opcUaBinaryEncode(std::ostream& os, const SignedSoftwareCertificate& value)
	{
	}

	void 
	opcUaBinaryDecode(std::istream& is, SignedSoftwareCertificate& value)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SignedSoftwareCertificateArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const SignedSoftwareCertificateArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const SignedSoftwareCertificateArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, SignedSoftwareCertificateArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, SignedSoftwareCertificateArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

}