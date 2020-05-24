/*
   Copyright 20 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ServerInfoServiceTransaction_h__
#define __OpcUaStackCore_ServerInfoServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSetServerInfo/AddSessionRequest.h"
#include "OpcUaStackCore/ServiceSetServerInfo/AddSessionResponse.h"
#include "OpcUaStackCore/ServiceSetServerInfo/DelSessionRequest.h"
#include "OpcUaStackCore/ServiceSetServerInfo/DelSessionResponse.h"
#include "OpcUaStackCore/ServiceSetServerInfo/UpdSessionRequest.h"
#include "OpcUaStackCore/ServiceSetServerInfo/UpdSessionResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		AddSessionRequest,
		AddSessionResponse,
		OpcUaId_AddSessionRequest_Encoding_DefaultBinary,
		OpcUaId_AddSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionAddSession;

	typedef ServiceTransactionTemplate<
		DelSessionRequest,
		DelSessionResponse,
		OpcUaId_DelSessionRequest_Encoding_DefaultBinary,
		OpcUaId_DelSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionDelSession;

	typedef ServiceTransactionTemplate<
		UpdSessionRequest,
		UpdSessionResponse,
		OpcUaId_UpdSessionRequest_Encoding_DefaultBinary,
		OpcUaId_UpdSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionUpdSession;

}

#endif
