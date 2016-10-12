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

#include "OpcUaStackCore/ServiceSet/ContentFilter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ContentFilter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ContentFilter::ContentFilter(void)
	: Object()
	, elementsArraySPtr_(constructSPtr<ContentFilterElementArray>())
	{
	}

	ContentFilter::~ContentFilter(void)
	{
	}

	void 
	ContentFilter::elements(const ContentFilterElementArray::SPtr elements)
	{
		elementsArraySPtr_ = elements;
	}

	ContentFilterElementArray::SPtr 
	ContentFilter::elements(void) const
	{
		return elementsArraySPtr_;
	}

	void 
	ContentFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		elementsArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ContentFilter::opcUaBinaryDecode(std::istream& is)
	{
		elementsArraySPtr_->opcUaBinaryDecode(is);
	}
}
