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
#include "OpcUaStackPubSub/DataSetMessage/EventDataSetMessage.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	EventDataSetMessage::EventDataSetMessage(void)
	: dataSetFields_(boost::make_shared<DataSetFieldArray>())
	, fieldEncoding_(VariantEncoding)
	{
		DataSetMessageHeader::SPtr dataSetMessageHeader = boost::make_shared<DataSetMessageHeader>();
		dataSetMessageHeader->fieldEncoding(VariantEncoding);
		dataSetMessageHeader->dataSetMessageSequenceNumberEnabled(true);
		dataSetMessageHeader->dataSetFlag2Enabled(true);
		this->dataSetMessageHeader(dataSetMessageHeader);

		messageType(EventData);
	}

	EventDataSetMessage::~EventDataSetMessage(void)
	{
	}

	DataSetFieldArray::SPtr&
	EventDataSetMessage::dataSetFields(void)
	{
		return dataSetFields_;
	}

	bool
	EventDataSetMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		uint16_t fieldCount = dataSetFields_->size();
		if (fieldCount == 0) return rc;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DataSetField::SPtr dataSetField;
			dataSetFields_->get(idx, dataSetField);

			rc &= dataSetField->opcUaBinaryEncode(os);
		}

		return rc;
	}

	bool
	EventDataSetMessage::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		uint16_t fieldCount;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, fieldCount);
		if (fieldCount == 0) return rc;

		dataSetFields_->resize(fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DataSetField::SPtr dataSetField = boost::make_shared<DataSetField>();

			dataSetField->createObject(VariantEncoding);
			rc &= dataSetField->opcUaBinaryDecode(is);
			if (rc) dataSetFields_->push_back(dataSetField);
		}

		return rc;
	}

}
