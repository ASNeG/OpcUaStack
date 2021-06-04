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

#include "OpcUaStackCore/ServiceSet/AddNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesRequest::AddNodesRequest(void)
	: addNodesItemArray_(boost::make_shared<AddNodesItemArray>())
	{
	}

	AddNodesRequest::~AddNodesRequest(void)
	{
	}
		
	void 
	AddNodesRequest::nodesToAdd(const AddNodesItemArray::SPtr addNodesItemArray)
	{
		addNodesItemArray_ = addNodesItemArray;
	}

	AddNodesItemArray::SPtr
	AddNodesRequest::nodesToAdd(void) const
	{
		return addNodesItemArray_;
	}

	void
	AddNodesRequest::copyTo(AddNodesRequest& addNodesRequest)
	{
		addNodesItemArray_->copyTo(*addNodesRequest.nodesToAdd().get());
	}

	bool
	AddNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return addNodesItemArray_->opcUaBinaryEncode(os);
	}
	
	bool
	AddNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		return addNodesItemArray_->opcUaBinaryDecode(is);
	}

	bool
	AddNodesRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;

		rc = rc & jsonArraySPtrEncode(pt, addNodesItemArray_, "NodesToAdd");

		return rc;
	}

	bool
	AddNodesRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;

		rc = rc & jsonArraySPtrDecode(pt, addNodesItemArray_, "NodesToAdd");

		return rc;
	}

}
