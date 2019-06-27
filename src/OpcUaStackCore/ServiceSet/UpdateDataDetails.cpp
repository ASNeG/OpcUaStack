/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
	: Object()
	, ExtensibleParameterBase()
	, nodeId_()
	, performInsertReplace_()
	, updateValueArraySPtr_(constructSPtr<OpcUaDataValueArray>())
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


	ExtensibleParameterBase::SPtr
	UpdateDataDetails::factory(void)
	{
		return constructSPtr<UpdateDataDetails>();
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
