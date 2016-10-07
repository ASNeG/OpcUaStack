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

#include "OpcUaStackCore/ServiceSet/ViewAttributes.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ViewAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ViewAttributes::ViewAttributes(void)
	: Object()
	, ExtensibleParameterBase()
	, specifiedAttributes_()
	, displayName_(constructSPtr<OpcUaLocalizedText>())
	, description_(constructSPtr<OpcUaLocalizedText>())
	, containsNoLoops_(false)
	, eventNotifier_()
	, writeMask_()
	, userWriteMask_()
	{
		specifiedAttributes_ |= SpecifiedAttributes_Description;
		specifiedAttributes_ |= SpecifiedAttributes_DisplayName;
		specifiedAttributes_ |= SpecifiedAttributes_ContainsNoLoops;
		specifiedAttributes_ |= SpecifiedAttributes_EventNotifier;
		specifiedAttributes_ |= SpecifiedAttributes_WriteMask;
		specifiedAttributes_ |= SpecifiedAttributes_UserWriteMask;
	}

	ViewAttributes::~ViewAttributes(void)
	{
	}

	 OpcUaUInt32
     ViewAttributes::specifiedAttributes(void) const
	 {
		 return specifiedAttributes_;
	 }

	void
	ViewAttributes::displayName(
		const OpcUaLocalizedText::SPtr displayNameSPtr)
	{
		displayName_ = displayNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	ViewAttributes::displayName(void) const
	{
		return displayName_;
	}

	void
	ViewAttributes::description(
		const OpcUaLocalizedText::SPtr descriptionSPtr)
	{
		description_ = descriptionSPtr;
	}

    OpcUaLocalizedText::SPtr
	ViewAttributes::description(void) const
	{
		return description_;
	}

	void
	ViewAttributes::containsNoLoops(
		const OpcUaBoolean containsNoLoops)
	{
		containsNoLoops_ = containsNoLoops;
	}

    OpcUaBoolean
	ViewAttributes::containsNoLoops(void) const
	{
		return containsNoLoops_;
	}

	void ViewAttributes::eventNotifier(
		const EventNotifierAttribute eventNotifier)
	{
		eventNotifier_ |= eventNotifier;
	}

    OpcUaByte
	ViewAttributes::eventNotifier(void) const
	{
		return eventNotifier_;
	}

	void ViewAttributes::writeMask(
		const WriteableAttribute writeMask)
	{
		writeMask_ |= writeMask;
	}

    OpcUaUInt32
	ViewAttributes::writeMask(void) const
	{
		return writeMask_;
	}

	
	void ViewAttributes::userWriteMask(
		const WriteableAttribute userWriteMask)
	{
		userWriteMask_ |= userWriteMask;
	}

    OpcUaUInt32
	ViewAttributes::userWriteMask(void) const
	{
		return userWriteMask_;
	}

	ExtensibleParameterBase::SPtr
	ViewAttributes::factory(void)
	{
		return constructSPtr<ViewAttributes>();
	}
			
	void 
	ViewAttributes::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, specifiedAttributes_);
		displayName_->opcUaBinaryEncode(os);
		description_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, containsNoLoops_);
		OpcUaNumber::opcUaBinaryEncode(os, eventNotifier_);
		OpcUaNumber::opcUaBinaryEncode(os, writeMask_);
		OpcUaNumber::opcUaBinaryEncode(os, userWriteMask_);
	}
	
	void 
	ViewAttributes::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, specifiedAttributes_);
		displayName_->opcUaBinaryDecode(is);
		description_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, containsNoLoops_);
		OpcUaNumber::opcUaBinaryDecode(is, eventNotifier_);
		OpcUaNumber::opcUaBinaryDecode(is, writeMask_);
		OpcUaNumber::opcUaBinaryDecode(is, userWriteMask_);
	}

}
