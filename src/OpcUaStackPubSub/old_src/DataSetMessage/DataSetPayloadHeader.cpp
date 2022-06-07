/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayloadHeader.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	DataSetPayloadHeader::DataSetPayloadHeader(void)
	: dataSetWriterIds_(boost::make_shared<OpcUaUInt16Array>())
	, dataSetArrayEnabled_(false)
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

	bool
	DataSetPayloadHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		OpcUaByte count = dataSetWriterIds_->size();
		OpcUaUInt16 dataSetWriterId;

		if (dataSetArrayEnabled_) {
			rc &= OpcUaNumber::opcUaBinaryEncode(os, count);


			for (uint32_t idx=0; idx<count; idx++) {
				dataSetWriterIds_->get(idx, dataSetWriterId);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, dataSetWriterId);
			}
		} else {
			dataSetWriterIds_->get(0, dataSetWriterId);
			rc &= OpcUaNumber::opcUaBinaryEncode(os, dataSetWriterId);
		}

		return rc;
	}

	bool
	DataSetPayloadHeader::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaByte count;
		OpcUaUInt16 dataSetWriterId;

		if (dataSetArrayEnabled_) {
			rc &= OpcUaNumber::opcUaBinaryDecode(is, count);
			dataSetWriterIds_->resize(count);

			for (uint32_t idx=0; idx<count; idx++) {
				rc &= OpcUaNumber::opcUaBinaryDecode(is, dataSetWriterId);
				if (rc) dataSetWriterIds_->push_back(dataSetWriterId);
			}
		} else {
			dataSetWriterIds_->resize(1);
			rc &= OpcUaNumber::opcUaBinaryDecode(is, dataSetWriterId);
			if (rc) dataSetWriterIds_->push_back(dataSetWriterId);
		}

		return rc;
	}

	bool
	DataSetPayloadHeader::operator==(const DataSetPayloadHeader& other) const
	{
		return *dataSetWriterIds_ == *other.dataSetWriterIds_
				&& dataSetArrayEnabled_ == other.dataSetArrayEnabled_;
	}


	void
	DataSetPayloadHeader::dataSetArrayEnabled(bool dataSetArrayEnabled)
	{
		dataSetArrayEnabled_ = dataSetArrayEnabled;
	}

	bool
	DataSetPayloadHeader::dataSetArrayEnabled() const
	{
		return dataSetArrayEnabled_;
	}

}
