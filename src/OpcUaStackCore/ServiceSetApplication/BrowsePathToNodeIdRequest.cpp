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
	, pathNames_()
	{
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
	BrowsePathToNodeIdRequest::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	BrowsePathToNodeIdRequest::opcUaBinaryDecode(std::istream& is)
	{
	}

}
