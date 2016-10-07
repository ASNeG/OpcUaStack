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

#ifndef __OpcUaStackCore_SessionServiceTransaction_h__
#define __OpcUaStackCore_SessionServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		CreateSessionRequest, 
		CreateSessionResponse, 
		OpcUaId_CreateSessionRequest_Encoding_DefaultBinary, 
		OpcUaId_CreateSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateSession;

	typedef ServiceTransactionTemplate<
		ActivateSessionRequest, 
		ActivateSessionResponse, 
		OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary, 
		OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionActivateSession;

	typedef ServiceTransactionTemplate<
		CloseSessionRequest, 
		CloseSessionResponse, 
		OpcUaId_CloseSessionRequest_Encoding_DefaultBinary, 
		OpcUaId_CloseSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionCloseSession;

	typedef ServiceTransactionTemplate<
		CancelRequest, 
		CancelResponse, 
		OpcUaId_CancelRequest_Encoding_DefaultBinary, 
		OpcUaId_CancelResponse_Encoding_DefaultBinary
	> ServiceTransactionCancel;

}

#endif
