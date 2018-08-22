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

#include "OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h"

namespace OpcUaStackPubSub
{

	PubSubWriterGroupModel::PubSubWriterGroupModel(PubSubGroupModel::Type type)
	: PubSubGroupModel(type)
	, publishingInterval_(0)
	, keepAliveTime_(0)
	, priority_()
	, encodingMimeType_("")
	{
	}

	PubSubWriterGroupModel::~PubSubWriterGroupModel(void)
	{
	}

	void
	PubSubWriterGroupModel::publishingInterval(const Duration publishingInterval)
	{
		publishingInterval_ = publishingInterval;
	}

	Duration
	PubSubWriterGroupModel::publishingInterval(void)
	{
		return publishingInterval_;
	}

	void
	PubSubWriterGroupModel::keepAliveTime(const Duration keepAliveTime)
	{
		keepAliveTime_ = keepAliveTime;
	}

	Duration
	PubSubWriterGroupModel::keepAliveTime(void)
	{
		return keepAliveTime_;
	}

	void
	PubSubWriterGroupModel::priority(const OpcUaByte priority)
	{
		priority_ = priority;
	}

	OpcUaByte
	PubSubWriterGroupModel::priority(void)
	{
		return priority_;
	}

	void
	PubSubWriterGroupModel::encodingMimeType(const OpcUaString& encodingMimeType)
	{
		encodingMimeType_ = encodingMimeType;
	}

	OpcUaString&
	PubSubWriterGroupModel::encodingMimeType(void)
	{
		return encodingMimeType_;
	}

	OpcUaStatusCode
	PubSubWriterGroupModel::removeDataSetWriter(
		OpcUaNodeId& dataSetWriterId
	)
	{
		// FIXME: todo
		return Success;
	}

}
