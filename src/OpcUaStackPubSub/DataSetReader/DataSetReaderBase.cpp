/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/DataSetReader/DataSetReaderBase.h"

namespace OpcUaStackPubSub
{

	DataSetReaderBase::DataSetReaderBase(void)
	{
	}

	DataSetReaderBase::~DataSetReaderBase(void)
	{
	}

	void
	DataSetReaderBase::dataSetReaderId(uint32_t dataSetReaderId)
	{
		dataSetReaderId_ = dataSetReaderId;
	}

	uint32_t
	DataSetReaderBase::dataSetReaderId(void)
	{
		return dataSetReaderId_;
	}

	bool
	DataSetReaderBase::encodeDataSet(boost::asio::streambuf& dataSet, uint16_t& size)
	{
		// FIXME: todo
		return true;
	}

}
