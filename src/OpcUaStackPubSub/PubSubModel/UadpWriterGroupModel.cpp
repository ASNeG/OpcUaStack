/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/PubSubModel/UadpWriterGroupModel.h"

namespace OpcUaStackPubSub
{

	UadpWriterGroupModel::UadpWriterGroupModel(void)
	: PubSubWriterGroupModel(PubSubGroupModel::UadpWriterGroupType)
	, maxNetworkMessageSize_(0)
	, publishingOffset_(0)
	, samplingOffset_(0)
	{
	}

	UadpWriterGroupModel::~UadpWriterGroupModel(void)
	{
	}

	void
	UadpWriterGroupModel::startup(void)
	{
		// FIXME: todo
	}

	void
	UadpWriterGroupModel::shutdown(void)
	{
		// FIXME: todo
	}

	void
	UadpWriterGroupModel::maxNetworkMessageSize(OpcUaInt16 maxNetworkMessageSize)
	{
		maxNetworkMessageSize_ = maxNetworkMessageSize;
	}

	OpcUaInt16
	UadpWriterGroupModel::maxNetworkMessageSize(void)
	{
		return maxNetworkMessageSize_;
	}

	void
	UadpWriterGroupModel::publishingOffset(Duration publishingOffset)
	{
		publishingOffset_ = publishingOffset;
	}

	Duration
	UadpWriterGroupModel::publishingOffset(void)
	{
		return publishingOffset_;
	}

	void
	UadpWriterGroupModel::samplingOffset(Duration samplingOffset)
	{
		samplingOffset_ = samplingOffset;
	}

	Duration
	UadpWriterGroupModel::samplingOffset(void)
	{
		return samplingOffset_;
	}

}
