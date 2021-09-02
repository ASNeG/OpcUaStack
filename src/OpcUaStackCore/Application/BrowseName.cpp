/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Application/BrowseName.h"

namespace OpcUaStackCore
{

	BrowseName::BrowseName(void)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
	}

	BrowseName::BrowseName(const BrowseName& browseName)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		nodeId_ = browseName.nodeId_;

		if (browseName.pathNames_.get() == nullptr) return;
		pathNames_->resize(browseName.pathNames_->size());
		for (auto pathElement : *browseName.pathNames_) {
			pathNames_->push_back(pathElement);
		}
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		std::initializer_list<const OpcUaQualifiedName> pathElementList
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElementList);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement1, pathElement2);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement1, pathElement2, pathElement3);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4,
		const OpcUaQualifiedName& pathElement5
	)
	: nodeId_()
	, pathNames_(boost::make_shared<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4, pathElement5);
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

	bool
	BrowseName::pushBack(const OpcUaQualifiedName& pathElement)
	{
		return pathNames_->push_back(boost::make_shared<OpcUaQualifiedName>(pathElement));
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId
	)
	{
		nodeId_ = nodeId;
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		std::initializer_list<const OpcUaQualifiedName> list
	)
	{
		pathNames_->resize(list.size());
		nodeId_ = nodeId;

		for (auto pathElement : list) {
			auto newPathElement = boost::make_shared<OpcUaQualifiedName>();
			const_cast<OpcUaQualifiedName*>(&pathElement)->copyTo(*newPathElement);
			pathNames_->push_back(newPathElement);
		}
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	{
		set(nodeId, {pathElement});
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	{
		set(nodeId, {pathElement1, pathElement2});
	}

	void
	BrowseName::set(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3
	)
	{
		set(nodeId, {pathElement1, pathElement2, pathElement3});
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
		set(nodeId, {pathElement1, pathElement2, pathElement3, pathElement4});
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
		set(nodeId, {pathElement1, pathElement2, pathElement3, pathElement4, pathElement5});
	}

	void
	BrowseName::copyTo(BrowseName& browseName)
	{
		nodeId_.copyTo(browseName.nodeId());
		pathNames_->copyTo(*browseName.pathNames().get());
	}

	void
	BrowseName::out(std::ostream& os) const
	{
		os << "NodeId=" << nodeId_;
		if (pathNames_ != nullptr) {
			os << ", Path=" << *pathNames_;
		}
	}

	std::string
	BrowseName::stringId(const std::string& suffix)
	{
		std::string id("");
		for (auto browseName : *pathNames()) {
			if (!id.empty()) id += "_";
			id += browseName->name().toStdString();
		}
		if (suffix.empty()) return id;
		if (!id.empty()) id += "_";
		id += suffix;
		return id;
	}

}
