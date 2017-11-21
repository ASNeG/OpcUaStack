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

#include "OpcUaStackPubSub/DataSetMessage/DataSetMessage.h"

namespace OpcUaStackPubSub
{

	DataSetMessage::DataSetMessage(void)
	: dataSetMessageHeader_(constructSPtr<DataSetMessageHeader>())
	{
		dataSetMessageHeader_->messageType(KeepAlive);
	}

	DataSetMessage::~DataSetMessage(void)
	{
	}

	void
	DataSetMessage::messageType(DataSetMessageType messageType)
	{
		dataSetMessageHeader_->messageType(messageType);
	}

	DataSetMessageType
	DataSetMessage::messageType(void)
	{
		return dataSetMessageHeader_->messageType();
	}

	DataSetMessageHeader&
	DataSetMessage::dataSetMessageHeader(void)
	{
		return *dataSetMessageHeader_;
	}

	void
	DataSetMessage::dataSetMessageHeader(DataSetMessageHeader::SPtr& dataSetMessageHeader)
	{
		dataSetMessageHeader_ = dataSetMessageHeader;
	}

	void
	DataSetMessage::sequenceNumber(uint16_t sequenceNumber)
	{
		dataSetMessageHeader_->dataMessageSequenceNumber(sequenceNumber);
	}

	uint16_t
	DataSetMessage::sequenceNumber(void)
	{
		return dataSetMessageHeader_->dataMessageSequenceNumber();
	}

	bool
	DataSetMessage::operator==(const DataSetMessage& other) const
	{
		return *dataSetMessageHeader_ == *other.dataSetMessageHeader_;
	}

	bool
	DataSetMessage::operator!=(const DataSetMessage& other) const
	{
		return !(*this == other);
	}


}

