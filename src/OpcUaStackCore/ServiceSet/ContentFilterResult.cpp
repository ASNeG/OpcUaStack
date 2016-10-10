/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/ContentFilterResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ContentFilterResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ContentFilterResult::ContentFilterResult(void)
	: Object()
	, elementResultArraySPtr_(constructSPtr<ContentFilterElementResultArray>())
	{
	}

	ContentFilterResult::~ContentFilterResult(void)
	{
	}

	void 
	ContentFilterResult::elementResults(const ContentFilterElementResultArray::SPtr elementResultArraySPtr)
	{
		elementResultArraySPtr_ = elementResultArraySPtr;
	}

	ContentFilterElementResultArray::SPtr 
	ContentFilterResult::elementResults(void)
	{
		return elementResultArraySPtr_;
	}

	void 
	ContentFilterResult::opcUaBinaryEncode(std::ostream& os) const
	{
		elementResultArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ContentFilterResult::opcUaBinaryDecode(std::istream& is)
	{
		elementResultArraySPtr_->opcUaBinaryDecode(is);
	}
}
