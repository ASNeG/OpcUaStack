/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/BrowsePathToNodeIdRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// BrowseNameArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	BrowseName::BrowseName(void)
	: nodeId_()
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
	{
	}

	BrowseName::BrowseName(const BrowseName& browseName)
	: nodeId_()
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
	{
		nodeId_ = browseName.nodeId_;

		if (browseName.pathNames_.get() == nullptr) return;
		pathNames_->resize(browseName.pathNames_->size());
		for (uint32_t idx=0; idx < browseName.pathNames_->size(); idx++) {
			OpcUaQualifiedName::SPtr pathElement;
			browseName.pathNames_->get(idx, pathElement);
			pathNames_->push_back(pathElement);
		}
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	: nodeId_()
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement);
	}

	BrowseName::BrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	: nodeId_()
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
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
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
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
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
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
	, pathNames_(constructSPtr<OpcUaQualifiedNameArray>())
	{
		set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4, pathElement5);
	}

	BrowseName::~BrowseName(void)
	{
	}

	void
	BrowseName::nodeId(OpcUaNodeId& nodeId)
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowsePathToNodeIdRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	BrowsePathToNodeIdRequest::BrowsePathToNodeIdRequest(void)
	: Object()
	, browseNameArray_(constructSPtr<BrowseNameArray>())
	{
	}

	BrowsePathToNodeIdRequest::~BrowsePathToNodeIdRequest(void)
	{
	}

	void
	BrowsePathToNodeIdRequest::browseNameArray(BrowseNameArray::SPtr& browseNameArray)
	{
		browseNameArray_ = browseNameArray;
	}

	BrowseNameArray::SPtr
	BrowsePathToNodeIdRequest::browseNameArray(void)
	{
		return browseNameArray_;
	}

	void
	BrowsePathToNodeIdRequest::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	{
		BrowseName::SPtr browseName = constructSPtr<BrowseName>();
		browseName->set(nodeId, pathElement);
		browseNameArray_->push_back(browseName);
	}

	void
	BrowsePathToNodeIdRequest::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	{
		BrowseName::SPtr browseName = constructSPtr<BrowseName>();
		browseName->set(nodeId, pathElement1, pathElement2);
		browseNameArray_->push_back(browseName);
	}

	void
	BrowsePathToNodeIdRequest::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3
	)
	{
		BrowseName::SPtr browseName = constructSPtr<BrowseName>();
		browseName->set(nodeId, pathElement1, pathElement2, pathElement3);
		browseNameArray_->push_back(browseName);
	}

	void
	BrowsePathToNodeIdRequest::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4
	)
	{
		BrowseName::SPtr browseName = constructSPtr<BrowseName>();
		browseName->set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4);
		browseNameArray_->push_back(browseName);
	}

	void
	BrowsePathToNodeIdRequest::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4,
		const OpcUaQualifiedName& pathElement5
	)
	{
		BrowseName::SPtr browseName = constructSPtr<BrowseName>();
		browseName->set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4, pathElement5);
		browseNameArray_->push_back(browseName);
	}

	void
	BrowsePathToNodeIdRequest::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	BrowsePathToNodeIdRequest::opcUaBinaryDecode(std::istream& is)
	{
	}

}
