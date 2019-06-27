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

#include "OpcUaStackCore/ServiceSet/RelativePathElement.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RelativePathElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RelativePathElement::RelativePathElement(void)
	: Object()
	, referenceTypeIdSPtr_(constructSPtr<OpcUaNodeId>())
	, isInverse_()
	, includeSubtypes_()
	, targetName_()
	{
	}

	RelativePathElement::~RelativePathElement(void)
	{
	}

	void 
	RelativePathElement::referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId)
	{
		referenceTypeIdSPtr_ = referenceTypeId;
	}
	
	OpcUaNodeId::SPtr 
	RelativePathElement::referenceTypeId(void) const
	{
		return referenceTypeIdSPtr_;
	}
	
	void 
	RelativePathElement::isInverse(const OpcUaBoolean& isInverse)
	{
		isInverse_ = isInverse;
	}
	
	OpcUaBoolean 
	RelativePathElement::isInverse(void) const
	{
		return isInverse_;
	}
	
	void 
	RelativePathElement::includeSubtypes(const OpcUaBoolean& includeSubtypes)
	{
		includeSubtypes_ = includeSubtypes;
	}

	OpcUaBoolean 
	RelativePathElement::includeSubtypes(void) const
	{
		return includeSubtypes_;
	}
	
	void 
	RelativePathElement::targetName(const OpcUaQualifiedName& targetName)
	{
		targetName_ = targetName;
	}
		
	OpcUaQualifiedName& 
	RelativePathElement::targetName(void)
	{
		return targetName_;
	}

	void 
	RelativePathElement::opcUaBinaryEncode(std::ostream& os) const
	{
		referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isInverse_);
		OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		targetName_.opcUaBinaryEncode(os);
	}
	
	void 
	RelativePathElement::opcUaBinaryDecode(std::istream& is)
	{
		referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isInverse_);
		OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		targetName_.opcUaBinaryDecode(is);
	}
}
