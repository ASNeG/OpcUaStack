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

#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	const OpcUaUInt32 MessageDefaults::protocolVersionDefault_ = 0;
	const OpcUaUInt32 MessageDefaults::receivedBufferSizeDefault_ = 65536;
	//const OpcUaUInt32 MessageDefaults::receivedBufferSizeDefault_ = 1000000;
	const OpcUaUInt32 MessageDefaults::sendBufferSizeDefault_ = 65536;
	//const OpcUaUInt32 MessageDefaults::sendBufferSizeDefault_ = 1000000;
	const OpcUaUInt32 MessageDefaults::maxMessageSizeDefault_ = 16777216;
	const OpcUaUInt32 MessageDefaults::maxChunkCountDefault_ = 5000;

}
