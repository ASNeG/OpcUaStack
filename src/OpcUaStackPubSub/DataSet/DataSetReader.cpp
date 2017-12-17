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

#include "OpcUaStackPubSub/DataSet/DataSetReader.h"

namespace OpcUaStackPubSub
{

	DataSetReader::DataSetReader(void)
	: receiveTimeoutCount_(0)
	{
	}

	DataSetReader::~DataSetReader(void)
	{
	}

	bool
	DataSetReader::receiveDataSetMessage(const DataSetMessage::SPtr& dataSetMessage)
	{
		receiveTimeoutCount_ = 0;
		return false;
	}

	bool
	DataSetReader::checkTimeout(uint32_t timeoutInterval)
	{
		receiveTimeoutCount_ += timeoutInterval;
		if (receiveTimeoutCount_ > messageReceiveTimeout()) {
			// TODO: We should change DataSetReader State to Error_3.

			receiveTimeoutCount_ = 0;
			return false;
		}

		return true;
	}

}
