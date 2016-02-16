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

#include "OpcUaStackCore/ServiceSet/DeleteEventDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteEventDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteEventDetails::DeleteEventDetails(void)
	: Object()
	, nodeId_()
	, eventIdArraySPtr_(constructSPtr<OpcUaByteStringArray>())
	{
	}

	DeleteEventDetails::~DeleteEventDetails(void)
	{
	}

	void 
	DeleteEventDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	DeleteEventDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	DeleteEventDetails::eventId(const OpcUaByteStringArray::SPtr eventId)
	{
		eventIdArraySPtr_ = eventId;
	}
	
	OpcUaByteStringArray::SPtr 
	DeleteEventDetails::eventId(void) const
	{
		return eventIdArraySPtr_;
	}

	ExtensibleParameterBase::SPtr
	DeleteEventDetails::factory(void)
	{
		return constructSPtr<DeleteEventDetails>();
	}

	void 
	DeleteEventDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		eventIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteEventDetails::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		eventIdArraySPtr_->opcUaBinaryDecode(is);
	}
}
