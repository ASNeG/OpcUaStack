/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_HelloMessage_h__
#define __OpcUaStackCore_HelloMessage_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HelloMessage
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<HelloMessage> SPtr;

		HelloMessage(void);
		virtual ~HelloMessage(void);

		void protocolVersion(const OpcUaUInt32& protocolVersion);
		OpcUaUInt32 protocolVersion(void) const;
		void receivedBufferSize(const OpcUaUInt32& receivedBufferSize);
		OpcUaUInt32 receivedBufferSize(void) const;
		void sendBufferSize(const OpcUaUInt32& sendBufferSize);
		OpcUaUInt32 sendBufferSize(void) const;
		void maxMessageSize(const OpcUaUInt32& maxMessageSize);
		OpcUaUInt32 maxMessageSize(void) const;
		void maxChunkCount(const OpcUaUInt32& maxChunkCount);
		OpcUaUInt32 maxChunkCount(void) const;
		void endpointUrl(const std::string& endpointUrl);
		std::string endpointUrl(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 protocolVersion_;
		OpcUaUInt32 receivedBufferSize_;
		OpcUaUInt32 sendBufferSize_;
		OpcUaUInt32 maxMessageSize_;
		OpcUaUInt32 maxChunkCount_;
		OpcUaString endpointUrl_;
	};

}

#endif
