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

#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"

namespace OpcUaStackPubSub
{

	KeepAliveMessage::KeepAliveMessage(void)
	{
		DataSetMessageHeader::SPtr dataSetMessageHeader = constructSPtr<DataSetMessageHeader>();
		dataSetMessageHeader->dataSetMessageSequenceNumberEnabled(true);
		dataSetMessageHeader->dataSetFlag2Enabled(true);
		this->dataSetMessageHeader(dataSetMessageHeader);
		messageType(KeepAlive);
	}

	KeepAliveMessage::~KeepAliveMessage(void)
	{
	}

	void
	KeepAliveMessage::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	KeepAliveMessage::opcUaBinaryDecode(std::istream& is)
	{
	}

}
