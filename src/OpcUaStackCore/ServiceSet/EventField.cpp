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

#include "OpcUaStackCore/ServiceSet/EventField.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventField
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventField::EventField(void)
	: Object()
	, variantSPtr_(constructSPtr<OpcUaVariant>())
	{
	}

	EventField::~EventField(void)
	{
	}

	void 
	EventField::variant(const OpcUaVariant::SPtr variant)
	{
		variantSPtr_ = variant;
	}
	
	OpcUaVariant::SPtr 
	EventField::variant(void) const
	{
		return variantSPtr_;
	}

	void 
	EventField::opcUaBinaryEncode(std::ostream& os) const
	{
		variantSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	EventField::opcUaBinaryDecode(std::istream& is)
	{
		variantSPtr_->opcUaBinaryDecode(is);	
	}
}
