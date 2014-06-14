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
		OpcUaStackCore::opcUaBinaryEncode(os, error_);
		OpcUaStackCore::opcUaBinaryEncode(os, reason_);
	}

	void 
	ErrorMessage::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, error_);
		OpcUaStackCore::opcUaBinaryDecode(is, reason_);
	}

}