/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ObjectTypeAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ObjectTypeAttributes::ObjectTypeAttributes(void)
	: Object()
	, ExtensionObjectBase()
	, specifiedAttributes_()
	, displayName_(constructSPtr<OpcUaLocalizedText>())
	, description_(constructSPtr<OpcUaLocalizedText>())
	, isAbstract_(false)
	, writeMask_()
	, userWriteMask_()
	{
		specifiedAttributes_ |= SpecifiedAttributes_Description;
		specifiedAttributes_ |= SpecifiedAttributes_DisplayName;
		specifiedAttributes_ |= SpecifiedAttributes_IsAbstract;
		specifiedAttributes_ |= SpecifiedAttributes_WriteMask;
		specifiedAttributes_ |= SpecifiedAttributes_UserWriteMask;
	}

	ObjectTypeAttributes::~ObjectTypeAttributes(void)
	{
	}

	 OpcUaUInt32
     ObjectTypeAttributes::specifiedAttributes(void) const
	 {
		 return specifiedAttributes_;
	 }

	void
	ObjectTypeAttributes::displayName(
		const OpcUaLocalizedText::SPtr displayNameSPtr)
	{
		displayName_ = displayNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	ObjectTypeAttributes::displayName(void) const
	{
		return displayName_;
	}

	void
	ObjectTypeAttributes::description(
		const OpcUaLocalizedText::SPtr descriptionSPtr)
	{
		description_ = descriptionSPtr;
	}

    OpcUaLocalizedText::SPtr
	ObjectTypeAttributes::description(void) const
	{
		return description_;
	}

	void ObjectTypeAttributes::isAbstract(
		const OpcUaBoolean isAbstract)
	{
		isAbstract_ = isAbstract;
	}

    OpcUaBoolean
	ObjectTypeAttributes::isAbstract(void) const
	{
		return isAbstract_;
	}

	void ObjectTypeAttributes::writeMask(
		const WriteableAttribute writeMask)
	{
		writeMask_ |= writeMask;
	}

    OpcUaUInt32
	ObjectTypeAttributes::writeMask(void) const
	{
		return writeMask_;
	}

	
	void ObjectTypeAttributes::userWriteMask(
		const WriteableAttribute userWriteMask)
	{
		userWriteMask_ |= userWriteMask;
	}

    OpcUaUInt32
	ObjectTypeAttributes::userWriteMask(void) const
	{
		return userWriteMask_;
	}

	void
	ObjectTypeAttributes::copyTo(ObjectTypeAttributes& objectTypeAttributes)
	{
		specifiedAttributes_ = objectTypeAttributes.specifiedAttributes_;
		displayName_->copyTo(*objectTypeAttributes.displayName_);
		description_->copyTo(*objectTypeAttributes.description_);
		isAbstract_ = objectTypeAttributes.isAbstract_;
		writeMask_ = objectTypeAttributes.writeMask_;
		userWriteMask_ = objectTypeAttributes.userWriteMask_;
	}

	bool
	ObjectTypeAttributes::operator==(const ObjectTypeAttributes& objectTypeAttributes) const
	{
		return specifiedAttributes_ == objectTypeAttributes.specifiedAttributes_ &&
			*displayName_ == *objectTypeAttributes.displayName_ &&
			*description_ == *objectTypeAttributes.description_ &&
			isAbstract_ == objectTypeAttributes.isAbstract_ &&
			writeMask_ == objectTypeAttributes.writeMask_ &&
			userWriteMask_ == objectTypeAttributes.userWriteMask_;
	}

	ExtensionObjectBase::SPtr
	ObjectTypeAttributes::factory(void)
	{
		return constructSPtr<ObjectTypeAttributes>();
	}
			
	void 
	ObjectTypeAttributes::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, specifiedAttributes_);
		displayName_->opcUaBinaryEncode(os);
		description_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isAbstract_);
		OpcUaNumber::opcUaBinaryEncode(os, writeMask_);
		OpcUaNumber::opcUaBinaryEncode(os, userWriteMask_);
	}
	
	void 
	ObjectTypeAttributes::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, specifiedAttributes_);
		displayName_->opcUaBinaryDecode(is);
		description_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isAbstract_);
		OpcUaNumber::opcUaBinaryDecode(is, writeMask_);
		OpcUaNumber::opcUaBinaryDecode(is, userWriteMask_);
	}

	void
	ObjectTypeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ObjectTypeAttributes* dst = dynamic_cast<ObjectTypeAttributes*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ObjectTypeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ObjectTypeAttributes* dst = dynamic_cast<ObjectTypeAttributes*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ObjectTypeAttributes::out(std::ostream& os)
	{
		os << "SpecificAttributes=" << specifiedAttributes_;
		os << ", DisplayName="; displayName_->out(os);
		os << ", Description="; description_->out(os);
		os << ", IsAbstract=" <<  isAbstract_;
		os << ", WriteMask=" << writeMask_;
		os << ", UserWriteMask=" << userWriteMask_;
	}

}
