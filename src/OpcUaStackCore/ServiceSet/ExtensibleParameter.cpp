#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{
	
	bool ExtensibleParameter::init_ = false;
	ExtensibleParameter::ExtensibleParameterMap ExtensibleParameter::extensibleParameterMap_;

	ExtensibleParameter::ExtensibleParameter(void)
	{
	}

	ExtensibleParameter::~ExtensibleParameter(void)
	{
	}

	bool 
	ExtensibleParameter::exist(void)
	{
		if (epSPtr_.get() == NULL) {
			return false;
		}
		return true;
	}

	void 
	ExtensibleParameter::opcUaBinaryEncode(std::ostream& os) const
	{
		parameterTypeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);
		epSPtr_->opcUaBinaryEncode(os);
	}

	void 
	ExtensibleParameter::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		parameterTypeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(parameterTypeId_);
		if (it == extensibleParameterMap_.end()) {
			return;
		}

		epSPtr_ = it->second->factory();
		epSPtr_->opcUaBinaryDecode(is);
	}
}