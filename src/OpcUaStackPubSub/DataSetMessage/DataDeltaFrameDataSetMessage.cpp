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

#include "OpcUaStackPubSub/DataSetMessage/DataDeltaFrameDataSetMessage.h"

namespace OpcUaStackPubSub
{

	DataDeltaFrameDataSetMessage::DataDeltaFrameDataSetMessage(void)
	: deltaFrameFields_(constructSPtr<DeltaFrameFieldArray>())
	{
		DataSetMessageHeader::SPtr dataSetMessageHeader = constructSPtr<DataSetMessageHeader>();
		dataSetMessageHeader->fieldEncoding(VariantEncoding);
		dataSetMessageHeader->dataSetMessageSequenceNumberEnabled(true);
		dataSetMessageHeader->dataSetFlag2Enabled(true);
		this->dataSetMessageHeader(dataSetMessageHeader);
		messageType(DataDeltaFrame);
	}

	DataDeltaFrameDataSetMessage::~DataDeltaFrameDataSetMessage(void)
	{
	}

	DeltaFrameFieldArray::SPtr&
	DataDeltaFrameDataSetMessage::deltaFrameFields(void)
	{
		return deltaFrameFields_;
	}

	void
	DataDeltaFrameDataSetMessage::setFieldEncoding(void)
	{
		if (deltaFrameFields_->size() == 0) {
			dataSetMessageHeader().fieldEncoding(VariantEncoding);
		}

		DeltaFrameField::SPtr deltaframeField;
		deltaFrameFields_->get(0, deltaframeField);
		dataSetMessageHeader().fieldEncoding(deltaframeField->dataType());
	}

	void
	DataDeltaFrameDataSetMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		uint16_t fieldCount = deltaFrameFields_->size();
		if (fieldCount == 0) return;

		OpcUaNumber::opcUaBinaryEncode(os, fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DeltaFrameField::SPtr deltaframeField;
			deltaFrameFields_->get(idx, deltaframeField);

			deltaframeField->opcUaBinaryEncode(os);
		}
	}

	void
	DataDeltaFrameDataSetMessage::opcUaBinaryDecode(std::istream& is)
	{
		uint16_t fieldCount;
		OpcUaNumber::opcUaBinaryDecode(is, fieldCount);
		if (fieldCount == 0) return;

		deltaFrameFields_->resize(fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DeltaFrameField::SPtr deltaFrameField = constructSPtr<DeltaFrameField>();

			deltaFrameField->createObject(dataSetMessageHeader().fieldEncoding());
			deltaFrameField->opcUaBinaryDecode(is);
			deltaFrameFields_->push_back(deltaFrameField);
		}
	}

}
