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

#include "OpcUaStackCore/ServiceSetApplication/BrowseName.h"

namespace OpcUaStackCore
{

	BrowseName::BrowseName(void)
	: nodeId_()
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
	{
	}

	BrowseName::~BrowseName(void)
	{
	}

	void
	BrowseName::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId&
	BrowseName::nodeId(void)
	{
		return nodeId_;
	}

	void
	BrowseName::pathNames(OpcUaQualifiedNameArray::SPtr& pathNames)
	{
		pathNames_ = pathNames;
	}

	OpcUaQualifiedNameArray::SPtr
	BrowseName::pathNames(void)
	{
		return pathNames_;
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	{
		pathNames_->resize(1);
		nodeId_ = nodeId;

		OpcUaQualifiedName::SPtr element;
		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement)->copyTo(*element);
		pathNames_->push_back(element);
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	{
		pathNames_->resize(2);
		nodeId_ = nodeId;

		OpcUaQualifiedName::SPtr element;

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement1)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement2)->copyTo(*element);
		pathNames_->push_back(element);
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3
	)
	{
		pathNames_->resize(3);
		nodeId_ = nodeId;

		OpcUaQualifiedName::SPtr element;

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement1)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement2)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement3)->copyTo(*element);
		pathNames_->push_back(element);
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4
	)
	{
		pathNames_->resize(4);
		nodeId_ = nodeId;

		OpcUaQualifiedName::SPtr element;

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement1)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement2)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement3)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement4)->copyTo(*element);
		pathNames_->push_back(element);
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4,
		const OpcUaQualifiedName& pathElement5
	)
	{
		pathNames_->resize(5);
		nodeId_ = nodeId;

		OpcUaQualifiedName::SPtr element;

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement1)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement2)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement3)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement4)->copyTo(*element);
		pathNames_->push_back(element);

		element = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&pathElement5)->copyTo(*element);
		pathNames_->push_back(element);
	}

}
