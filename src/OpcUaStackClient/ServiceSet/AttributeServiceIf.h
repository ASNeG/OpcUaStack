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

#ifndef __OpcUaStackClient_AttributeServiceIf_h__
#define __OpcUaStackClient_AttributeServiceIf_h__

#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeServiceIf
	{
	  public:
		AttributeServiceIf(void) {}
		virtual ~AttributeServiceIf(void) {}

        virtual void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead) {};
		virtual void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite) {};
		virtual void attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead) {};
		virtual void attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate) {};

	};

	class DLLEXPORT AttributeServiceIfTestHandler
	: public AttributeServiceIf
	{
	  public:
		AttributeServiceIfTestHandler(void);
		virtual ~AttributeServiceIfTestHandler(void);

		Condition attributeServiceReadResponse_;
        void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead);

		Condition attributeServiceWriteResponse_;
		void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite);

		Condition attributeServiceHistoryReadResponse_;
		void attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);

		Condition attributeServiceHistoryUpdateResponse_;
		void attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);

	};

}

#endif
