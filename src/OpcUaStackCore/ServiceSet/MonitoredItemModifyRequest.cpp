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

#include "OpcUaStackCore/ServiceSet/MonitoredItemModifyRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemModifyRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemModifyRequest::MonitoredItemModifyRequest(void)
	: Object()
	, monitoredItemId_()
	, requestedParameters_()
	{
	}

	MonitoredItemModifyRequest::~MonitoredItemModifyRequest(void)
	{
	}

	void 
	MonitoredItemModifyRequest::monitoredItemId(const OpcUaUInt32& monitoredItemId)
	{
		monitoredItemId_ = monitoredItemId;
	}
	
	OpcUaUInt32 
	MonitoredItemModifyRequest::monitoredItemId(void) const
	{
		return monitoredItemId_;
	}
	
	void
	MonitoredItemModifyRequest::requestedParameters(const MonitoringParameters& requestedParameters)
	{
		requestedParameters_ = requestedParameters;
	}
	
	MonitoringParameters& 
	MonitoredItemModifyRequest::requestedParameters(void)
	{
		return requestedParameters_;
	}

	void 
	MonitoredItemModifyRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, monitoredItemId_);
		requestedParameters_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemModifyRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, monitoredItemId_);
		requestedParameters_.opcUaBinaryDecode(is);
	}
}
