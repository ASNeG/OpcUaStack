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

#include "OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteReferencesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteReferencesRequest::DeleteReferencesRequest(void)
	: deleteReferencesItemArray_(boost::make_shared<DeleteReferencesItemArray>())
	{
	}

	DeleteReferencesRequest::~DeleteReferencesRequest(void)
	{
	}
		
	void 
	DeleteReferencesRequest::referencesToDelete(const DeleteReferencesItemArray::SPtr deleteReferencesItemArray)
	{
		deleteReferencesItemArray_ = deleteReferencesItemArray;
	}

	DeleteReferencesItemArray::SPtr
	DeleteReferencesRequest::referencesToDelete(void) const
	{
		return deleteReferencesItemArray_;
	}


	bool
	DeleteReferencesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return deleteReferencesItemArray_->opcUaBinaryEncode(os);
	}
	
	bool
	DeleteReferencesRequest::opcUaBinaryDecode(std::istream& is)
	{
		return deleteReferencesItemArray_->opcUaBinaryDecode(is);
	}

}
