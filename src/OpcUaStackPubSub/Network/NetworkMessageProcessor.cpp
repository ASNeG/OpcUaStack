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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackPubSub/Network/NetworkMessageProcessor.h"

namespace OpcUaStackPubSub
{

	NetworkMessageProcessor::NetworkMessageProcessor(void)
	: dataSetReaderIfMap_()
	{
	}

	NetworkMessageProcessor::~NetworkMessageProcessor(void)
	{
	}

	bool
	NetworkMessageProcessor::deregisterDataSetReaderIf(uint32_t readerId)
	{
		DataSetReaderIf::Map::iterator it;
		it = dataSetReaderIfMap_.find(readerId);
		if (it == dataSetReaderIfMap_.end()) return false;
		dataSetReaderIfMap_.erase(it);
		return true;
	}

	bool NetworkMessageProcessor::registerDataSetReaderIf(const DataSetReaderIf::SPtr& reader)
	{
		DataSetReaderIf::Map::iterator it;
		it = dataSetReaderIfMap_.find(reader->readerId());
		if (it != dataSetReaderIfMap_.end()) return false;
		dataSetReaderIfMap_.insert(std::make_pair(reader->readerId(), reader));
		return false;
	}

	bool
	NetworkMessageProcessor::receive(const NetworkMessage& message)
	{
		return false;
	}

}
