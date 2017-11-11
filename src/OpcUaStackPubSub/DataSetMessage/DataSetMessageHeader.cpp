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

#include "OpcUaStackPubSub/DataSetMessage/DataSetMessageHeader.h"

namespace OpcUaStackPubSub
{

	DataSetMessageHeader::DataSetMessageHeader(void)
	: fieldEncoding_(VariantEncoding)
	, dataSetMessageSequenceNumberEnabled_(true)
	, timestampEnabled_(true)
	, statusEnabled_(true)
	, configurationVersionMajorVersionEnabled_(true)
	, configurationVersionMinorVersionEnabled_(true)
	, messageType_(KeepAlive)
	, picoSecondsEnabled_(true)
	, timestamp_()
	, picoSeconds_(0)
	, statusCode_(Success)
	, configurationVersionMajorVersion_(0)
	, configurationVersionMinorVersion_(0)
	{
	}

	DataSetMessageHeader::~DataSetMessageHeader(void)
	{
	}

	void
	DataSetMessageHeader::fieldEncoding(FieldEncoding fieldEncoding)
	{
		fieldEncoding_ = fieldEncoding;
	}

	DataSetMessageHeader::FieldEncoding
	DataSetMessageHeader::fieldEncoding(void)
	{
		return fieldEncoding_;
	}

	void
	DataSetMessageHeader::dataSetMessageSequenceNumberEnabled(bool enabled)
	{
		dataSetMessageSequenceNumberEnabled_ = enabled;
	}

	bool
	DataSetMessageHeader::dataSetMessageSequenceNumberEnabled(void)
	{
		return dataSetMessageSequenceNumberEnabled_;
	}

	void
	DataSetMessageHeader::timestampEnabled(bool enabled)
	{
		timestampEnabled_ = enabled;
	}

	bool
	DataSetMessageHeader::timestampEnabled(void)
	{
		return timestampEnabled_;
	}

	void
	DataSetMessageHeader::statusEnabled(bool enabled)
	{
		statusEnabled_ = enabled;
	}

	bool
	DataSetMessageHeader::statusEnabled(void)
	{
		return statusEnabled_;
	}

	void
	DataSetMessageHeader::configurationVersionMajorVersionEnabled(bool enabled)
	{
		configurationVersionMajorVersionEnabled_ = enabled;
	}

	bool
	DataSetMessageHeader::configurationVersionMajorVersionEnabled(void)
	{
		return configurationVersionMajorVersionEnabled_;
	}

	void
	DataSetMessageHeader::configurationVersionMinorVersionEnabled(bool enabled)
	{
		configurationVersionMinorVersionEnabled_ = enabled;
	}

	bool
	DataSetMessageHeader::configurationVersionMinorVersionEnabled(void)
	{
		return configurationVersionMinorVersionEnabled_;
	}

	void
	DataSetMessageHeader::messageType(DataSetMessageType messageType)
	{
		messageType_ = messageType;
	}

	DataSetMessageType
	DataSetMessageHeader::messageType(void)
	{
		return messageType_;
	}

	void
	DataSetMessageHeader::picoSecondsEnabled(bool enabled)
	{
		picoSecondsEnabled_ = enabled;
	}

	bool
	DataSetMessageHeader::picoSecondsEnabled(void)
	{
		return picoSecondsEnabled_;
	}

	void
	DataSetMessageHeader::timestamp(OpcUaDateTime timestamp)
	{
		timestamp_ = timestamp;
	}

	OpcUaDateTime
	DataSetMessageHeader::timestamp(void)
	{
		return timestamp_;
	}

	void
	DataSetMessageHeader::picoSeconds(OpcUaUInt16 picoSeconds)
	{
		picoSeconds_ = picoSeconds;
	}

	OpcUaUInt16
	DataSetMessageHeader::picoSeconds(void)
	{
		return picoSeconds_;
	}

	void
	DataSetMessageHeader::statusCode(OpcUaUInt16 statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaUInt16
	DataSetMessageHeader::statusCode(void)
	{
		return statusCode_;
	}

	void
	DataSetMessageHeader::configurationVersionMajorVersion(OpcUaUInt32 configurationVersionMajorVersion)
	{
		configurationVersionMajorVersion_ = configurationVersionMajorVersion;
	}

	OpcUaUInt32
	DataSetMessageHeader::configurationVersionMajorVersion(void)
	{
		return configurationVersionMajorVersion_;
	}

	void
	DataSetMessageHeader::configurationVersionMinorVersion(OpcUaUInt32 configurationVersionMinorVersion)
	{
		configurationVersionMinorVersion_ = configurationVersionMinorVersion;
	}

	OpcUaUInt32
	DataSetMessageHeader::configurationVersionMinorVersion(void)
	{
		return configurationVersionMinorVersion_;
	}

	void
	DataSetMessageHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		// FIXME: todo
	}

	void
	DataSetMessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
	}

}
