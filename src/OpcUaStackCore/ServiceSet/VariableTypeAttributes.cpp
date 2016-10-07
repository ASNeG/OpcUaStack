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

#include "OpcUaStackCore/ServiceSet/VariableTypeAttributes.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// VariableTypeAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VariableTypeAttributes::VariableTypeAttributes(void)
	: Object()
	, ExtensibleParameterBase()
	, specifiedAttributes_()
	, displayName_(constructSPtr<OpcUaLocalizedText>())
	, description_(constructSPtr<OpcUaLocalizedText>())
	, value_(constructSPtr<OpcUaDataValue>())
	, dataType_()
	, valueRank_(-1)
	, arrayDimensions_(constructSPtr<OpcUaUInt32Array>())
	, isAbstract_(false)
	, writeMask_()
	, userWriteMask_()
	{
		dataType_ = constructSPtr<OpcUaNodeId>();

		specifiedAttributes_ |= SpecifiedAttributes_Description;
		specifiedAttributes_ |= SpecifiedAttributes_DisplayName;
		specifiedAttributes_ |= SpecifiedAttributes_Value;
		specifiedAttributes_ |= SpecifiedAttributes_DataType;
		specifiedAttributes_ |= SpecifiedAttributes_ValueRank;
		specifiedAttributes_ |= SpecifiedAttributes_ArrayDimensions;
		specifiedAttributes_ |= SpecifiedAttributes_IsAbstract;
		specifiedAttributes_ |= SpecifiedAttributes_WriteMask;
		specifiedAttributes_ |= SpecifiedAttributes_UserWriteMask;
	}

	VariableTypeAttributes::~VariableTypeAttributes(void)
	{
	}

	 OpcUaUInt32
     VariableTypeAttributes::specifiedAttributes(void) const
	 {
		 return specifiedAttributes_;
	 }

	void
	VariableTypeAttributes::displayName(
		const OpcUaLocalizedText::SPtr displayNameSPtr)
	{
		displayName_ = displayNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	VariableTypeAttributes::displayName(void) const
	{
		return displayName_;
	}

	void
	VariableTypeAttributes::description(
		const OpcUaLocalizedText::SPtr descriptionSPtr)
	{
		description_ = descriptionSPtr;
	}

    OpcUaLocalizedText::SPtr
	VariableTypeAttributes::description(void) const
	{
		return description_;
	}

	void
	VariableTypeAttributes::value(
		const OpcUaDataValue::SPtr valueSPtr)
	{
		value_ = valueSPtr;
	}

    OpcUaDataValue::SPtr
	VariableTypeAttributes::value(void) const
	{
		return value_;
	}
		
	void
	VariableTypeAttributes::dataType(
		const OpcUaNodeId::SPtr dataTypeSPtr)
	{
		dataType_ = dataTypeSPtr;
	}

    OpcUaNodeId::SPtr
	VariableTypeAttributes::dataType(void) const
	{
		return dataType_;
	}

		
	void
	VariableTypeAttributes::valueRank(
		const OpcUaInt32 valueRank)
	{
		valueRank_ = valueRank;
	}

    OpcUaInt32
	VariableTypeAttributes::valueRank(void) const
	{
		return valueRank_;
	}
			
	void
	VariableTypeAttributes::arrayDimensions(
		const OpcUaUInt32Array::SPtr arrayDimensionsSPtr)
	{
		arrayDimensions_ = arrayDimensionsSPtr;
	}

    OpcUaUInt32Array::SPtr
	VariableTypeAttributes::arrayDimensions(void) const
	{
		return arrayDimensions_;
	}

			
	void
	VariableTypeAttributes::isAbstract(
		const OpcUaBoolean isAbstract)
	{
		isAbstract_ = isAbstract;
	}

    OpcUaBoolean
	VariableTypeAttributes::isAbstract(void) const
	{
		return isAbstract_;
	}
		
	void VariableTypeAttributes::writeMask(
		const WriteableAttribute writeMask)
	{
		writeMask_ |= writeMask;
	}

    OpcUaUInt32
	VariableTypeAttributes::writeMask(void) const
	{
		return writeMask_;
	}

	
	void VariableTypeAttributes::userWriteMask(
		const WriteableAttribute userWriteMask)
	{
		userWriteMask_ |= userWriteMask;
	}

    OpcUaUInt32
	VariableTypeAttributes::userWriteMask(void) const
	{
		return userWriteMask_;
	}

	ExtensibleParameterBase::SPtr
	VariableTypeAttributes::factory(void)
	{
		return constructSPtr<VariableTypeAttributes>();
	}
			
	void 
	VariableTypeAttributes::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, specifiedAttributes_);
		displayName_->opcUaBinaryEncode(os);
		description_->opcUaBinaryEncode(os);
		value_->opcUaBinaryEncode(os);
		dataType_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, valueRank_);
		arrayDimensions_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isAbstract_);
		OpcUaNumber::opcUaBinaryEncode(os, writeMask_);
		OpcUaNumber::opcUaBinaryEncode(os, userWriteMask_);
	}
	
	void 
	VariableTypeAttributes::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, specifiedAttributes_);
		displayName_->opcUaBinaryDecode(is);
		description_->opcUaBinaryDecode(is);
		value_->opcUaBinaryDecode(is);
		dataType_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, valueRank_);
		arrayDimensions_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isAbstract_);
		OpcUaNumber::opcUaBinaryDecode(is, writeMask_);
		OpcUaNumber::opcUaBinaryDecode(is, userWriteMask_);
	}

}
