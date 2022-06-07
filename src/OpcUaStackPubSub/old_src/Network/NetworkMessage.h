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

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackPubSub_NetworkMessage_h__
#define __OpcUaStackPubSub_NetworkMessage_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/Network/NetworkMessageHeader.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayloadHeader.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayload.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT NetworkMessage
	{
	  public:
		NetworkMessage(void);
		virtual ~NetworkMessage(void);

		void networkMessageHeader(NetworkMessageHeader::SPtr networkMessageHeader);
		NetworkMessageHeader::SPtr networkMessageHeader() const;

		void dataSetPayloadHeader(DataSetPayloadHeader::SPtr dataSetPayloadHeader);
		DataSetPayloadHeader::SPtr dataSetPayloadHeader() const;

		void dataSetPayload(DataSetPayload::SPtr dataSetPayload);
		DataSetPayload::SPtr dataSetPayload() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		bool operator==(const NetworkMessage& other) const;

	  private:
		NetworkMessageHeader::SPtr networkMessageHeader_;
		DataSetPayloadHeader::SPtr dataSetPayloadHeader_;
		DataSetPayload::SPtr dataSetPayload_;
	};

}

#endif
