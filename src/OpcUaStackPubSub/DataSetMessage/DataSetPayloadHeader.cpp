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

#include "OpcUaStackPubSub/DataSetMessage/DataSetPayloadHeader.h"

namespace OpcUaStackPubSub
{

	DataSetPayloadHeader::DataSetPayloadHeader(void)
	: dataSetWriterIds_(constructSPtr<OpcUaUInt16Array>())
	{
	}

	DataSetPayloadHeader::~DataSetPayloadHeader(void)
	{
	}

	void
	DataSetPayloadHeader::dataSetWriterIds(const OpcUaUInt16Array::SPtr& dataSetWriterIds)
	{
		dataSetWriterIds_ = dataSetWriterIds;
	}

	OpcUaUInt16Array::SPtr&
	DataSetPayloadHeader::dataSetWriterIds(void)
	{
		return dataSetWriterIds_;
	}

	void
	DataSetPayloadHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte count = dataSetWriterIds_->size();
		OpcUaNumber::opcUaBinaryEncode(os, count);

		for (uint32_t idx=0; idx<count; idx++) {
			OpcUaUInt16 dataSetWriterId;
			dataSetWriterIds_->get(idx, dataSetWriterId);
			OpcUaNumber::opcUaBinaryEncode(os, dataSetWriterId);
		}
	}

	void
	DataSetPayloadHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte count;
		OpcUaNumber::opcUaBinaryDecode(is, count);
		dataSetWriterIds_->resize(count);

		for (uint32_t idx=0; idx<count; idx++) {
			OpcUaUInt16 dataSetWriterId;
			OpcUaNumber::opcUaBinaryDecode(is, dataSetWriterId);
			dataSetWriterIds_->push_back(dataSetWriterId);
		}
	}

	bool
	DataSetPayloadHeader::operator==(const DataSetPayloadHeader& other) const
	{
		return dataSetWriterIds_ == other.dataSetWriterIds_;
	}
}


