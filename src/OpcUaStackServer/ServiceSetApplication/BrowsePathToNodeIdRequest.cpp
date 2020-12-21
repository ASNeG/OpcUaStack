/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/BrowsePathToNodeIdRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{


	BrowsePathToNodeIdRequest::BrowsePathToNodeIdRequest(void)
	: Object()
	, browseNameArray_(boost::make_shared<BrowseNameArray>())
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
		const BrowseName::SPtr& browseName
	)
	{
		browseNameArray_->push_back(browseName);
	}

	void
	BrowsePathToNodeIdRequest::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	{
		BrowseName::SPtr browseName = boost::make_shared<BrowseName>();
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
		BrowseName::SPtr browseName = boost::make_shared<BrowseName>();
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
		BrowseName::SPtr browseName = boost::make_shared<BrowseName>();
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
		BrowseName::SPtr browseName = boost::make_shared<BrowseName>();
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
		BrowseName::SPtr browseName = boost::make_shared<BrowseName>();
		browseName->set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4, pathElement5);
		browseNameArray_->push_back(browseName);
	}

	bool
	BrowsePathToNodeIdRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return false;
	}

	bool
	BrowsePathToNodeIdRequest::opcUaBinaryDecode(std::istream& is)
	{
		return false;
	}

}
