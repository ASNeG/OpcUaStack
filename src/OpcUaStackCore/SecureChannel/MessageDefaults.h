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

#ifndef __OpcUaStackCore_MessageDefaults_h__
#define __OpcUaStackCore_MessageDefaults_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class MessageDefaults
	{
	  public:
		static const OpcUaUInt32 protocolVersionDefault_;
		static const OpcUaUInt32 receivedBufferSizeDefault_;
		static const OpcUaUInt32 sendBufferSizeDefault_;
		static const OpcUaUInt32 maxMessageSizeDefault_;
		static const OpcUaUInt32 maxChunkCountDefault_;
	};

}

#endif
