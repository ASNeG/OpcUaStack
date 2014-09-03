#include "OpcUaStackCore/ServiceSet/UpdateStructureDataDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UpdateStructureDataDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UpdateStructureDataDetails::UpdateStructureDataDetails(void)
	: ObjectPool<UpdateStructureDataDetails>()
	, nodeId_()
	, performInsertReplace_()
	, updateValueArraySPtr_(OpcUaDataValueArray::construct())
	{
	}

	UpdateStructureDataDetails::~UpdateStructureDataDetails(void)
	{
	}

	void 
	UpdateStructureDataDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	UpdateStructureDataDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	UpdateStructureDataDetails::performInsertReplace(const PerformUpdateEnumeration performInsertReplace)
	{
		performInsertReplace_ = performInsertReplace;
	}

	PerformUpdateEnumeration 
	UpdateStructureDataDetails::performInsertReplace(void)
	{
		return performInsertReplace_;
	}
	
	void 
	UpdateStructureDataDetails::updateValue(const OpcUaDataValueArray::SPtr updateValue)
	{
		updateValueArraySPtr_ = updateValue;
	}
	
	OpcUaDataValueArray::SPtr 
	UpdateStructureDataDetails::updateValue(void) const
	{
		return updateValueArraySPtr_;
	}


	ExtensibleParameterBase::BSPtr 
	UpdateStructureDataDetails::factory(void)
	{
		return UpdateStructureDataDetails::construct();
	}

	void 
	UpdateStructureDataDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)performInsertReplace_);
		updateValueArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	UpdateStructureDataDetails::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		nodeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		performInsertReplace_ = (PerformUpdateEnumeration)tmp;
		updateValueArraySPtr_->opcUaBinaryDecode(is);
	}
}