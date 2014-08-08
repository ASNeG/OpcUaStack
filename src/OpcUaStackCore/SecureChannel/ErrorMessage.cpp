#include "OpcUaStackCore/SecureChannel/ErrorMessage.h"

namespace OpcUaStackCore
{

	ErrorMessage::ErrorMessage(void)
	: error_(0)
	, reason_()
	{
	}
		
	ErrorMessage::~ErrorMessage(void)
	{
	}

	void 
	ErrorMessage::error(const OpcUaUInt32& error)
	{
		error_ = error;
	}
		
	OpcUaUInt32 
	ErrorMessage::error(void) const
	{
		return error_;
	}
		
	void 
	ErrorMessage::reason(const std::string& reason)
	{
		reason_ = reason;
	}

	std::string 
	ErrorMessage::reason(void)
	{
		std::string reason = reason_;
		return reason;
	}

	void 
	ErrorMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, error_);
		reason_.opcUaBinaryEncode(os);
	}

	void 
	ErrorMessage::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, error_);
		reason_.opcUaBinaryDecode(is);
	}

}