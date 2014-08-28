#include "OpcUaStackCore/ServiceSet/UpdateDataDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UpdateDataDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UpdateDataDetails::UpdateDataDetails(void)
	: ObjectPool<UpdateDataDetails>()
	, nodeId_()
	, performInsertReplace_()
	, updateValueArraySPtr_(OpcUaDataValueArray::construct())
	{
	}

	UpdateDataDetails::~UpdateDataDetails(void)
	{
	}

	void 
	UpdateDataDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	UpdateDataDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	UpdateDataDetails::performInsertReplace(const PerformUpdateEnumeration performInsertReplace)
	{
		performInsertReplace_ = performInsertReplace;
	}

	PerformUpdateEnumeration 
	UpdateDataDetails::performInsertReplace(void)
	{
		return performInsertReplace_;
	}
	
	void 
	UpdateDataDetails::updateValue(const OpcUaDataValueArray::SPtr updateValue)
	{
		updateValueArraySPtr_ = updateValue;
	}
	
	OpcUaDataValueArray::SPtr 
	UpdateDataDetails::updateValue(void) const
	{
		return updateValueArraySPtr_;
	}


	ExtensibleParameterBase::BSPtr 
	UpdateDataDetails::factory(void)
	{
		return UpdateDataDetails::construct();
	}

	void 
	UpdateDataDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)performInsertReplace_);
		updateValueArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	UpdateDataDetails::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		nodeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		performInsertReplace_ = (PerformUpdateEnumeration)tmp;
		updateValueArraySPtr_->opcUaBinaryDecode(is);
	}
}