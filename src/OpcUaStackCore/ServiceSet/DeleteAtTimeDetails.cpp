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

#include "OpcUaStackCore/ServiceSet/DeleteAtTimeDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteAtTimeDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteAtTimeDetails::DeleteAtTimeDetails(void)
	: Object()
	, ExtensibleParameterBase()
	, nodeId_()
	, reqTimeArraySPtr_(constructSPtr<UtcTimeArray>())
	{
	}

	DeleteAtTimeDetails::~DeleteAtTimeDetails(void)
	{
	}

	void 
	DeleteAtTimeDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	DeleteAtTimeDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	DeleteAtTimeDetails::reqTimes(const UtcTimeArray::SPtr reqTimes)
	{
		reqTimeArraySPtr_ = reqTimes;
	}
	
	UtcTimeArray::SPtr 
	DeleteAtTimeDetails::reqTimes(void) const
	{
		return reqTimeArraySPtr_;
	}

	ExtensibleParameterBase::SPtr
	DeleteAtTimeDetails::factory(void)
	{
		return constructSPtr<DeleteAtTimeDetails>();
	}

	void 
	DeleteAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		reqTimeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteAtTimeDetails::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		reqTimeArraySPtr_->opcUaBinaryDecode(is);
	}
}
