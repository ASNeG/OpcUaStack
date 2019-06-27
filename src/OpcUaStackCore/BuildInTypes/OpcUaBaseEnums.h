/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaBaseEnums_h__
#define __OpcUaStackCore_OpcUaBaseEnums_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// secure channel enums
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	typedef enum
	{
		RT_ISSUE = 0,
		RT_RENEW = 1
	} RequestType;


	typedef enum {
		SN_Unknown,
		SM_None,
		SM_Sign,
		SM_SignAndEncrypt
	} SecurityMode;

	typedef enum
	{
		SP_None,
		SP_Basic128Rsa15,
		SP_Basic256,
		SP_Basic256Sha256
	} SecurityPolicy;

}

#endif
