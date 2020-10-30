/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/Forward/ReadForwardRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadForwardRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadForwardRequest::ReadForwardRequest(void)
	{
	}

	ReadForwardRequest::~ReadForwardRequest(void)
	{
	}

	void 
	ReadForwardRequest::maxAge(const OpcUaDouble& maxAge)
	{
		maxAge_ = maxAge;
	}
	
	OpcUaDouble 
	ReadForwardRequest::maxAge(void) const
	{
		return maxAge_;
	}
	
	void 
	ReadForwardRequest::timestampsToReturn(const OpcUaInt32& timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	OpcUaInt32 
	ReadForwardRequest::timestampsToReturn(void) const
	{
		return timestampsToReturn_;
	}
	
	void 
	ReadForwardRequest::readValueId(const ReadValueId::SPtr readValueId)
	{
		readValueId_ = readValueId;
	}
	
	ReadValueId::SPtr
	ReadForwardRequest::readValueId(void) const
	{
		return readValueId_;
	}

}
