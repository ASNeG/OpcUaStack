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

#include "OpcUaStackPubSub/DataSetMessage/DeltaFrameField.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	DeltaFrameField::DeltaFrameField(void)
	: DataSetField()
	, fieldIndex_(0)
	{
	}

	DeltaFrameField::DeltaFrameField(FieldEncoding dataType)
	: DataSetField(dataType)
	, fieldIndex_(0)
	{
	}

	DeltaFrameField::~DeltaFrameField(void)
	{
	}

	void
	DeltaFrameField::fieldIndex(uint16_t fieldIndex)
	{
		fieldIndex_ = fieldIndex;
	}

	uint32_t
	DeltaFrameField::fieldIndex(void)
	{
		return fieldIndex_;
	}

	void
	DeltaFrameField::copyTo(DeltaFrameField& deltaFrameField)
	{
		deltaFrameField.fieldIndex(fieldIndex_);
	}

	bool
	DeltaFrameField::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, fieldIndex_);
		rc &= DataSetField::opcUaBinaryEncode(os);

		return rc;
	}

	bool
	DeltaFrameField::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, fieldIndex_);
		rc &= DataSetField::opcUaBinaryDecode(is);

		return rc;
	}

}
