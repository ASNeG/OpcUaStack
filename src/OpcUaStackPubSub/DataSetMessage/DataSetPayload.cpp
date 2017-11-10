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

#include "OpcUaStackPubSub/DataSetMessage/DataSetPayload.h"

namespace OpcUaStackPubSub
{

	DataSetPayload::DataSetPayload(void)
	: dataSetMessages_(constructSPtr<DataSetMessageArray>())
	{
	}

	DataSetPayload::~DataSetPayload(void)
	{
	}

	void
	DataSetPayload::dataSetMessages(const DataSetMessageArray::SPtr& dataSetMessages)
	{
		dataSetMessages_ = dataSetMessages;
	}

	DataSetMessageArray::SPtr&
	DataSetPayload::dataSetMessages(void)
	{
		return dataSetMessages_;
	}

	void
	DataSetPayload::opcUaBinaryEncode(std::ostream& os)
	{
		// FIXME: todo
	}

	void
	DataSetPayload::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
	}

}
