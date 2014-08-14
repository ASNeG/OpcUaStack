#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{
	
	bool ExtensibleParameter::init_ = false;
	ExtensibleParameter::ExtensibleParameterMap ExtensibleParameter::extensibleParameterMap_;

	bool 
	ExtensibleParameter::insertElement(OpcUaNodeId& opcUaNodeId, ExtensibleParameterBase::SPtr epSPtr)
	{
		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(opcUaNodeId);
		if (it != extensibleParameterMap_.end()) {
			return false;
		}
		extensibleParameterMap_.insert(std::make_pair(opcUaNodeId, epSPtr));
		return true;
	}

	bool 
	ExtensibleParameter::deleteElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(opcUaNodeId);
		if (it == extensibleParameterMap_.end()) {
			return false;
		}
		extensibleParameterMap_.erase(it);
		return true;
	}

	ExtensibleParameterBase::SPtr 
	ExtensibleParameter::findElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensibleParameterBase::SPtr epSPtr;
		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(opcUaNodeId);
		if (it != extensibleParameterMap_.end()) {
			epSPtr = it->second;
		}
		return epSPtr;
	}

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