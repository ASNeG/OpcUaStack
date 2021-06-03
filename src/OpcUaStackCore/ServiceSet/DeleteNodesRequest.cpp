/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/DeleteNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteNodesRequest::DeleteNodesRequest(void)
	: deleteNodesItemArraySPtr_(boost::make_shared<DeleteNodesItemArray>())
	{
	}

	DeleteNodesRequest::~DeleteNodesRequest(void)
	{
	}
		
	void 
	DeleteNodesRequest::nodesToDelete(const DeleteNodesItemArray::SPtr addReferencesItemArray)
	{
		deleteNodesItemArraySPtr_ = addReferencesItemArray;
	}

	DeleteNodesItemArray::SPtr
	DeleteNodesRequest::nodesToDelete(void) const
	{
		return deleteNodesItemArraySPtr_;
	}


	bool
	DeleteNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return deleteNodesItemArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	DeleteNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		return deleteNodesItemArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	DeleteNodesRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;

		rc = rc & jsonArraySPtrEncode(pt, deleteNodesItemArraySPtr_, "NodesToDelte");

		return rc;
	}

	bool
	DeleteNodesRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;

		rc = rc & jsonArraySPtrDecode(pt, deleteNodesItemArraySPtr_, "NodesToDelete");

		return rc;
	}

}
