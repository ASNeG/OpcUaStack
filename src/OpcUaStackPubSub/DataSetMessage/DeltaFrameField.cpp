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

#include "OpcUaStackPubSub/DataSetMessage/DeltaFrameField.h"

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
	DeltaFrameField::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, fieldIndex_);
		DataSetField::opcUaBinaryEncode(os);
	}

	void
	DeltaFrameField::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, fieldIndex_);
		DataSetField::opcUaBinaryDecode(is);
	}

}
