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

#ifndef __OpcUaStackCore_ForwardServiceTransaction_h__
#define __OpcUaStackCore_ForwardServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/Forward/ForwardTransactionTemplate.h"
#include "OpcUaStackServer/Forward/ReadForwardRequest.h"
#include "OpcUaStackServer/Forward/ReadForwardResponse.h"
#include "OpcUaStackServer/Forward/WriteForwardRequest.h"
#include "OpcUaStackServer/Forward/WriteForwardResponse.h"
#include "OpcUaStackServer/Forward/CallForwardRequest.h"
#include "OpcUaStackServer/Forward/CallForwardResponse.h"

namespace OpcUaStackServer
{
	
	typedef ForwardTransactionTemplate<
		ReadForwardRequest,
		ReadForwardResponse,
		OpcUaId_ForwardTransactionReadRequest_Encoding_DefaultBinary,
		OpcUaId_ForwardTransactionReadResponse_Encoding_DefaultBinary
	> ForwardTransactionRead;

	typedef ForwardTransactionTemplate<
		WriteForwardRequest,
		WriteForwardResponse,
		OpcUaId_ForwardTransactionWriteRequest_Encoding_DefaultBinary,
		OpcUaId_ForwardTransactionWriteResponse_Encoding_DefaultBinary
	> ForwardTransactionWrite;

	typedef ForwardTransactionTemplate<
		CallForwardRequest,
		CallForwardResponse,
		OpcUaId_ForwardTransactionMethodRequest_Encoding_DefaultBinary,
		OpcUaId_ForwardTransactionMethodResponse_Encoding_DefaultBinary
	> ForwardTransactionCall;

}

#endif
