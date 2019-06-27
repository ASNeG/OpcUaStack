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


#include "OpcUaStackClient/ServiceSet/AttributeServiceIf.h"

namespace OpcUaStackClient
{
	AttributeServiceIfTestHandler::AttributeServiceIfTestHandler(void)
	: attributeServiceReadResponse_()
	, attributeServiceWriteResponse_()
	, attributeServiceHistoryReadResponse_()
	, attributeServiceHistoryUpdateResponse_()
	{
	}

	AttributeServiceIfTestHandler::~AttributeServiceIfTestHandler(void)
	{
	}

    void
    AttributeServiceIfTestHandler::attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead)
    {
    	attributeServiceReadResponse_.conditionValueDec();
    }

	void
	AttributeServiceIfTestHandler::attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		attributeServiceWriteResponse_.conditionValueDec();
	}

	void
	AttributeServiceIfTestHandler::attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
		attributeServiceHistoryReadResponse_.conditionValueDec();
	}

	void
	AttributeServiceIfTestHandler::attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
		attributeServiceHistoryUpdateResponse_.conditionValueDec();
	}

}
