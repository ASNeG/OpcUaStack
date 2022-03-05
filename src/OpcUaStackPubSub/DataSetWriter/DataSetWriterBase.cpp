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

#include "OpcUaStackPubSub/DataSetWriter/DataSetWriterBase.h"

namespace OpcUaStackPubSub
{

	DataSetWriterBase::DataSetWriterBase(void)
	{
	}

	DataSetWriterBase::~DataSetWriterBase(void)
	{
	}

	void
	DataSetWriterBase::dataSetWriterId(uint32_t dataSetWriterId)
	{
		dataSetWriterId_ = dataSetWriterId;
	}

	uint32_t
	DataSetWriterBase::dataSetWriterId(void)
	{
		return dataSetWriterId_;
	}

	bool
	DataSetWriterBase::encodeDataSet(boost::asio::streambuf& dataSet, uint16_t& size)
	{
		// FIXME: todo
		return true;
	}

}
