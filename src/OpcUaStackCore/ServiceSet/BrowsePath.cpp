/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/BrowsePath.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowsePath
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowsePath::BrowsePath(void)
	: Object()
	, startingNodeSPtr_()
	, relativePath_()
	{
		startingNodeSPtr_ = boost::make_shared<OpcUaNodeId>();
	}

	BrowsePath::~BrowsePath(void)
	{
	}

	void 
	BrowsePath::startingNode(const OpcUaNodeId::SPtr startingNode)
	{
		startingNodeSPtr_ = startingNode;
	}
	
	OpcUaNodeId::SPtr 
	BrowsePath::startingNode(void) const
	{
		return startingNodeSPtr_;
	}
	
	void 
	BrowsePath::relativePath(const RelativePath& relativePath)
	{
		relativePath_ = relativePath;
	}
	
	RelativePath& 
	BrowsePath::relativePath(void)
	{
		return relativePath_;
	}

	void
	BrowsePath::copyTo(BrowsePath& browsePath)
	{
		startingNodeSPtr_->copyTo(*browsePath.startingNode().get());
		relativePath_.copyTo(browsePath.relativePath());
	}

	bool
	BrowsePath::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= startingNodeSPtr_->opcUaBinaryEncode(os);
		rc &= relativePath_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	BrowsePath::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= startingNodeSPtr_->opcUaBinaryDecode(is);
		rc &= relativePath_.opcUaBinaryDecode(is);

		return rc;
	}

	bool
	BrowsePath::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode starting node
		if (!startingNodeSPtr_->jsonEncode(pt, "StartingNode")) {
			Log(Error, "BrowsePath json encode error")
		        .parameter("Element", "StartingNode");
			return false;
		}

		// encode relative paths
		if (!relativePath_.jsonEncode(pt, "RelativePath")) {
			Log(Error, "BrowsePath json encode error")
		        .parameter("Element", "RelativePaths");
			return false;
		}

		return true;
	}

	bool
	BrowsePath::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		// decode starting node
		if (!startingNodeSPtr_->jsonDecode(pt, "StartingNode")) {
			Log(Error, "BrowsePath json decode error")
		        .parameter("Element", "StartingNode");
			return false;
		}

		// decode relative paths
		if (!relativePath_.jsonDecode(pt, "RelativePath")) {
			Log(Error, "BrowsePath json decode error")
		        .parameter("Element", "RelativePaths");
			return false;
		}

		return true;
	}

}
