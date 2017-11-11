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
	: fieldEncoding_(Variant)
	, dataSetMessageSequenceNumberEnabled_(true)
	, timestampEnabled_(true)
	, statusEnabled_(true)
	, configurationVersionMajorVersionEnabled_(true)
	, configurationVersionMinorVersionEnabled_(true)
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
