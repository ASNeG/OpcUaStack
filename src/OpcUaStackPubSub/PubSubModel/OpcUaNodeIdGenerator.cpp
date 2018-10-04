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

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/OpcUaNodeIdGenerator.h>

namespace OpcUaStackPubSub
{

	OpcUaNodeIdGenerator* OpcUaNodeIdGenerator::instance_ = nullptr;

	OpcUaNodeIdGenerator::OpcUaNodeIdGenerator(void)
	{
		nodeId_.set((uint32_t)1,(uint16_t)1);
	}

	OpcUaNodeIdGenerator::~OpcUaNodeIdGenerator(void)
	{
	}

	OpcUaNodeIdGenerator*
	OpcUaNodeIdGenerator::instance(void)
	{
		if (instance_ == nullptr) {
			instance_ = new OpcUaNodeIdGenerator();
		}
		return instance_;
	}

	void
	OpcUaNodeIdGenerator::createNodeNodeId(
		OpcUaNodeId& nodeId
	)
	{
		uint32_t identifier;
		uint16_t namespaceIndex;

		nodeId_.get(identifier, namespaceIndex);
		identifier++;
		nodeId_.set(identifier, namespaceIndex);

		nodeId = nodeId_;
	}

}
