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
	, fieldEncoding_(VariantEncoding)
	{
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
	DataDeltaFrameDataSetMessage::fieldEncoding(FieldEncoding fieldEncoding)
	{
		fieldEncoding_ = fieldEncoding;
	}

	void
	DataDeltaFrameDataSetMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		uint16_t fieldCount = deltaFrameFields_->size();
		if (fieldCount == 0) return;

		DeltaFrameField::SPtr deltaframeField;
		deltaFrameFields_->get(0, deltaframeField);
		if (deltaframeField->dataType() == None) return;

		DataSetMessageHeader& hdr = const_cast<DataDeltaFrameDataSetMessage*>(this)->dataSetMessageHeader();
		hdr.fieldEncoding(deltaframeField->dataType());
		hdr.dataSetMessageSequenceNumberEnabled(true);
		hdr.dataSetFlag2Enabled(true);
		hdr.opcUaBinaryEncode(os);

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
		DataSetMessageHeader& hdr = const_cast<DataDeltaFrameDataSetMessage*>(this)->dataSetMessageHeader();
		hdr.opcUaBinaryDecode(is);
		fieldEncoding_ = hdr.fieldEncoding();
		if (fieldEncoding_ == None) return;

		uint16_t fieldCount;
		OpcUaNumber::opcUaBinaryDecode(is, fieldCount);
		if (fieldCount == 0) return;

		deltaFrameFields_->resize(fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DeltaFrameField::SPtr deltaFrameField = constructSPtr<DeltaFrameField>();

			deltaFrameField->createObject(fieldEncoding_);
			deltaFrameField->opcUaBinaryDecode(is);
			deltaFrameFields_->push_back(deltaFrameField);
		}
	}

}
