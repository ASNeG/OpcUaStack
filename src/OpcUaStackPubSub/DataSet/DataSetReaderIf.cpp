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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackPubSub/DataSet/DataSetReaderIf.h"

namespace OpcUaStackPubSub
{

	DataSetReaderIf::DataSetReaderIf(void)
	: readerId_(0)
	{
	}

	DataSetReaderIf::~DataSetReaderIf(void)
	{
	}

	void
	DataSetReaderIf::readerId(uint32_t readerId)
	{
		readerId_ = readerId;
	}

	uint32_t
	DataSetReaderIf::readerId(void)
	{
		return readerId_;
	}

}
