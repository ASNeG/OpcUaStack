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

#ifndef __OpcUaStackCore_AttributeServiceTransaction_h__
#define __OpcUaStackCore_AttributeServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/ReadRequest.h"
#include "OpcUaStackCore/ServiceSet/ReadResponse.h"
#include "OpcUaStackCore/ServiceSet/WriteRequest.h"
#include "OpcUaStackCore/ServiceSet/WriteResponse.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadRequest.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadResponse.h"
#include "OpcUaStackCore/ServiceSet/HistoryUpdateRequest.h"
#include "OpcUaStackCore/ServiceSet/HistoryUpdateResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		ReadRequest, 
		ReadResponse, 
		OpcUaId_ReadRequest_Encoding_DefaultBinary, 
		OpcUaId_ReadResponse_Encoding_DefaultBinary
	> ServiceTransactionRead;

	typedef ServiceTransactionTemplate<
		WriteRequest, 
		WriteResponse, 
		OpcUaId_WriteRequest_Encoding_DefaultBinary, 
		OpcUaId_WriteResponse_Encoding_DefaultBinary
	> ServiceTransactionWrite;

	typedef ServiceTransactionTemplate<
		HistoryReadRequest, 
		HistoryReadResponse, 
		OpcUaId_HistoryReadRequest_Encoding_DefaultBinary, 
		OpcUaId_HistoryReadResponse_Encoding_DefaultBinary
	> ServiceTransactionHistoryRead;

	typedef ServiceTransactionTemplate<
		HistoryUpdateRequest, 
		HistoryUpdateResponse, 
		OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary, 
		OpcUaId_HistoryUpdateResponse_Encoding_DefaultBinary
	> ServiceTransactionHistoryUpdate;

}

#endif
