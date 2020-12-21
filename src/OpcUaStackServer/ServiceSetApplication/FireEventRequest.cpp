/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/FireEventRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa FireEventRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	FireEventRequest::FireEventRequest(void)
	: Object()
	, eventBase_()
	, nodeId_()
	{
	}

	FireEventRequest::~FireEventRequest(void)
	{
	}

	void
	FireEventRequest::eventBase(EventBase::SPtr& eventBase)
	{
		eventBase_ = eventBase;
	}

	EventBase::SPtr&
	FireEventRequest::eventBase(void)
	{
		return eventBase_;
	}

	void
	FireEventRequest::nodeId(OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId&
	FireEventRequest::nodeId(void)
	{
		return nodeId_;
	}

	bool
	FireEventRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return false;
	}

	bool
	FireEventRequest::opcUaBinaryDecode(std::istream& is)
	{
		return false;
	}

}
