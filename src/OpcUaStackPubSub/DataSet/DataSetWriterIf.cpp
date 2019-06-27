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

#include "OpcUaStackPubSub/DataSet/DataSetWriterIf.h"

namespace OpcUaStackPubSub
{

	DataSetWriterIf::DataSetWriterIf(void)
	: writerId_(0)
	, keyFrameCount_(0)
	, keepAliveTime_(0)
	{
	}

	DataSetWriterIf::~DataSetWriterIf(void)
	{
	}

	void
	DataSetWriterIf::writerId(uint32_t writerId)
	{
		writerId_ = writerId;
	}

	uint32_t
	DataSetWriterIf::writerId(void) const
	{
		return writerId_;
	}

	void
	DataSetWriterIf::keyFrameCount(uint32_t keyFrameCount)
	{
		keyFrameCount_ = keyFrameCount;
	}

	uint32_t
	DataSetWriterIf::keyFrameCount(void) const
	{
		return keyFrameCount_;
	}

	void
	DataSetWriterIf::keepAliveTime(uint32_t keepAliveTime)
	{
		keepAliveTime_ = keepAliveTime;
	}

	uint32_t
	DataSetWriterIf::keepAliveTime(void) const
	{
		return keepAliveTime_;
	}

}
