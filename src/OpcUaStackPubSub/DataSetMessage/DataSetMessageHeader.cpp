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
	, dataSetMessageSequenceNumberEnabled_(false)
	, timestampEnabled_(false)
	, statusEnabled_(false)
	, configurationVersionMajorVersionEnabled_(false)
	, configurationVersionMinorVersionEnabled_(false)
	, dataSetFlag2Enabled_(false)
	, messageType_(DataKeyFrame)
	, picoSecondsEnabled_(false)
	, dataMessageSequenceNumber_(0)
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
	DataSetMessageHeader::dataSetFlag2Enabled(bool dataSetFlag2Enabled)
	{
		dataSetFlag2Enabled_ = dataSetFlag2Enabled;
	}

	bool
	DataSetMessageHeader::dataSetFlag2Enabled(void)
	{
		return dataSetFlag2Enabled_;
	}

	void
	DataSetMessageHeader::messageType(DataSetMessageType messageType)
	{
		messageType_ = messageType;
		dataSetFlag2Enabled_ = true;
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
		dataSetFlag2Enabled_ = true;
	}

	bool
	DataSetMessageHeader::picoSecondsEnabled(void)
	{
		return picoSecondsEnabled_;
	}

	void
	DataSetMessageHeader::dataMessageSequenceNumber(OpcUaUInt16 dataMessageSequenceNumber)
	{
		dataMessageSequenceNumber_ = dataMessageSequenceNumber;
	}

	OpcUaUInt16
	DataSetMessageHeader::dataMessageSequenceNumber(void)
	{
		return dataMessageSequenceNumber_;
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
		// DataSetFlag 1
		OpcUaByte dataSetFlag1 = 0;
		dataSetFlag1 = (OpcUaByte)fieldEncoding_;
		if (dataSetMessageSequenceNumberEnabled_) dataSetFlag1 += 4;
		if (timestampEnabled_) dataSetFlag1 += 8;
		if (statusEnabled_) dataSetFlag1 += 16;
		if (configurationVersionMajorVersionEnabled_) dataSetFlag1 += 32;
		if (configurationVersionMinorVersionEnabled_) dataSetFlag1 += 64;
		if (dataSetFlag2Enabled_) dataSetFlag1 += 128;
		OpcUaNumber::opcUaBinaryEncode(os, dataSetFlag1);

		// DataSetFlag2
		if (dataSetFlag2Enabled_) {
			OpcUaByte dataSetFlag2 = 0;
			dataSetFlag2 = (OpcUaByte)messageType_;
			if (picoSecondsEnabled_) dataSetFlag2 += 16;
			OpcUaNumber::opcUaBinaryEncode(os, dataSetFlag2);
		}

		// sequence number
		if (dataSetMessageSequenceNumberEnabled_) {
			OpcUaNumber::opcUaBinaryEncode(os, dataMessageSequenceNumber_);
		}

		// timestamp
		if (timestampEnabled_) {
			timestamp_.opcUaBinaryEncode(os);
		}

		// picoseconds
		if (picoSecondsEnabled_) {
			OpcUaNumber::opcUaBinaryEncode(os, picoSeconds_);
		}

		// status
		if (statusEnabled_) {
			OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		}

		// major version
		if (configurationVersionMajorVersionEnabled_) {
			OpcUaNumber::opcUaBinaryEncode(os, configurationVersionMajorVersion_);
		}

		// minior version
		if (configurationVersionMinorVersionEnabled_) {
			OpcUaNumber::opcUaBinaryEncode(os, configurationVersionMinorVersion_);
		}
	}

	void
	DataSetMessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		// DataSetFlag 1
		OpcUaByte dataSetFlag1 = 0;
		OpcUaNumber::opcUaBinaryDecode(is, dataSetFlag1);
		if (dataSetFlag1 >= 128) {
			dataSetFlag2Enabled_ = true;
			dataSetFlag1 -= 128;
		}
		if (dataSetFlag1 >= 64) {
			configurationVersionMinorVersionEnabled_ = true;
			dataSetFlag1 -= 64;
		}
		if (dataSetFlag1 >= 32) {
			configurationVersionMajorVersionEnabled_ = true;
			dataSetFlag1 -= 32;
		}
		if (dataSetFlag1 >= 16) {
			statusEnabled_ = true;
			dataSetFlag1 -= 16;
		}
		if (dataSetFlag1 >= 8) {
			timestampEnabled_ = true;
			dataSetFlag1 -= 8;
		}
		fieldEncoding_ = (FieldEncoding)dataSetFlag1;

		// DataSetFlag2
		if (dataSetFlag2Enabled_) {
			OpcUaByte dataSetFlag2 = 0;
			OpcUaNumber::opcUaBinaryDecode(is, dataSetFlag2);

			if (dataSetFlag2 >= 16) {
				timestampEnabled_ = true;
				dataSetFlag2 -= 16;
			}

			messageType_ = (DataSetMessageType)dataSetFlag2;
		}

		// sequence number
		if (dataSetMessageSequenceNumberEnabled_) {
			OpcUaNumber::opcUaBinaryDecode(is, dataMessageSequenceNumber_);
		}

		// timestamp
		if (timestampEnabled_) {
			timestamp_.opcUaBinaryDecode(is);
		}

		// picoseconds
		if (picoSecondsEnabled_) {
			OpcUaNumber::opcUaBinaryDecode(is, picoSeconds_);
		}

		// status
		if (statusEnabled_) {
			OpcUaNumber::opcUaBinaryDecode(is, statusCode_);
		}

		// major version
		if (configurationVersionMajorVersionEnabled_) {
			OpcUaNumber::opcUaBinaryDecode(is, configurationVersionMajorVersion_);
		}

		// minior version
		if (configurationVersionMinorVersionEnabled_) {
			OpcUaNumber::opcUaBinaryDecode(is, configurationVersionMinorVersion_);
		}
	}

}
