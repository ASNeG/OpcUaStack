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

#include <boost/algorithm/string/predicate.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/BuildInTypes/Json.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

namespace OpcUaStackCore
{

	class OpcUaVariantTypeVisitor : public boost::static_visitor<>
	{
	  public:
		void operator()(OpcUaVariantNullType) { opcUaBuildInType_ = OpcUaBuildInType_Unknown; }
		void operator()(OpcUaBoolean) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaBoolean; }
		void operator()(OpcUaSByte) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaSByte; }
		void operator()(OpcUaByte) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaByte; }
		void operator()(OpcUaInt16) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaInt16; }
		void operator()(OpcUaUInt16) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaUInt16; }
		void operator()(OpcUaInt32) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaInt32; }
		void operator()(OpcUaUInt32) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaUInt32; }
		void operator()(OpcUaInt64) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaInt64; }
		void operator()(OpcUaUInt64) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaUInt64; }
		void operator()(OpcUaFloat) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaFloat; }
		void operator()(OpcUaDouble) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaDouble; }
		void operator()(OpcUaDateTime) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaDateTime; }
		void operator()(OpcUaStatusCode) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaStatusCode; }
		void operator()(OpcUaVariantSPtr opcUaVariantSPtr) {  opcUaBuildInType_ = opcUaVariantSPtr.opcUaBuildInType_; }
		
		OpcUaBuildInType opcUaBuildInType_;
	};

	OpcUaVariantSPtr::OpcUaVariantSPtr(void)
	: opcUaBuildInType_()
	, objectSPtr_()
	{
	}
	
	OpcUaVariantSPtr::~OpcUaVariantSPtr(void)
	{
	}
		

	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	//
	// OpcUaVariantValue
	//
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	OpcUaVariantValue::OpcUaVariantValue(void)
	: variantValue_()
	{
	}
	
	OpcUaVariantValue::OpcUaVariantValue(const OpcUaVariantValue& value)
	: variantValue_()
	{
		const_cast<OpcUaVariantValue*>(&value)->copyTo(*this);
	}

	OpcUaVariantValue::~OpcUaVariantValue(void)
	{
	}

	OpcUaBuildInType 
	OpcUaVariantValue::variantType(void) const
	{
		OpcUaVariantTypeVisitor opcUaVariantTypeVisitor;
		boost::apply_visitor(opcUaVariantTypeVisitor, variantValue_);
		return opcUaVariantTypeVisitor.opcUaBuildInType_;
	}

	bool
	OpcUaVariantValue::isNull(void) const
	{
		return variantType() == OpcUaBuildInType_Unknown;
	}

	void 
	OpcUaVariantValue::variant(const OpcUaGuid::SPtr valSPtr) 
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaGuid;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void 
	OpcUaVariantValue::variant(const OpcUaByteString::SPtr valSPtr) 
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaByteString;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void 
	OpcUaVariantValue::variant(const OpcUaString::SPtr valSPtr) 
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaString;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaXmlElement::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaXmlElement;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaNodeId::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaNodeId;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaExpandedNodeId::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExpandedNodeId;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaQualifiedName::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaQualifiedName;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaLocalizedText::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaLocalizedText;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}	
	void  
	OpcUaVariantValue::variant(const OpcUaExtensionObject::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExtensionObject;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void
	OpcUaVariantValue::variant(const boost::shared_ptr<OpcUaDataValue> valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaDataValue;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void
	OpcUaVariantValue::variant(const OpcUaDiagnosticInfo::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaDiagnosticInfo;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	bool 
	OpcUaVariantValue::operator!=(OpcUaVariantValue& variantValue)
	{
		return !operator==(variantValue);
	}

	bool 
	OpcUaVariantValue::operator==(OpcUaVariantValue& variantValue)
	{
		if (variantValue.variantType() != variantType()) return false;
		switch (variantType()) 
		{
			case OpcUaBuildInType_Unknown:
			{
				return true;
			}
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean value1 = boost::get<OpcUaBoolean>(variantValue_);
				OpcUaBoolean value2 = variantValue.variant<OpcUaBoolean>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte value1 = boost::get<OpcUaSByte>(variantValue_);
				OpcUaSByte value2 = variantValue.variant<OpcUaSByte>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte value1 = boost::get<OpcUaByte>(variantValue_);
				OpcUaByte value2 = variantValue.variant<OpcUaByte>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 value1 = boost::get<OpcUaInt16>(variantValue_);
				OpcUaInt16 value2 = variantValue.variant<OpcUaInt16>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 value1 = boost::get<OpcUaUInt16>(variantValue_);
				OpcUaUInt16 value2 = variantValue.variant<OpcUaUInt16>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 value1 = boost::get<OpcUaInt32>(variantValue_);
				OpcUaInt32 value2 = variantValue.variant<OpcUaInt32>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value1 = boost::get<OpcUaUInt32>(variantValue_);
				OpcUaUInt32 value2 = variantValue.variant<OpcUaUInt32>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 value1 = boost::get<OpcUaInt64>(variantValue_);
				OpcUaInt64 value2 = variantValue.variant<OpcUaInt64>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 value1 = boost::get<OpcUaUInt64>(variantValue_);
				OpcUaUInt64 value2 = variantValue.variant<OpcUaUInt64>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat value1 = boost::get<OpcUaFloat>(variantValue_);
				OpcUaFloat value2 = variantValue.variant<OpcUaFloat>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble value1 = boost::get<OpcUaDouble>(variantValue_);
				OpcUaDouble value2 = variantValue.variant<OpcUaDouble>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime value1 = boost::get<OpcUaDateTime>(variantValue_);
				OpcUaDateTime value2 = variantValue.variant<OpcUaDateTime>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaInt32 value1 = boost::get<OpcUaStatusCode>(variantValue_);
				OpcUaInt32 value2 = variantValue.variant<OpcUaStatusCode>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaGuid::SPtr value1 = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaGuid::SPtr value2 = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaByteString::SPtr value1 = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaByteString::SPtr value2 = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaString::SPtr value1 = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaString::SPtr value2 = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				// FIXME: actualy not used
				return false;
			}
			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaNodeId::SPtr value1 = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaNodeId::SPtr value2 = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaExpandedNodeId::SPtr value1 = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaExpandedNodeId::SPtr value2 = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaQualifiedName::SPtr value1 = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaQualifiedName::SPtr value2 = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaLocalizedText::SPtr value1 = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaLocalizedText::SPtr value2 = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaExtensionObject::SPtr value1 = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaExtensionObject::SPtr value2 = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaDataValue::SPtr value1 = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaDataValue::SPtr value2 = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaDiagnosticInfo::SPtr value1 = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaDiagnosticInfo::SPtr value2 = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 == *value2;
			}
		}
		return false;
	}

	bool
	OpcUaVariantValue::operator<(OpcUaVariantValue& variantValue)
	{
		if (variantValue.variantType() != variantType()) return false;
		switch (variantType())
		{
			case OpcUaBuildInType_Unknown:
			{
				return false;
			}
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean value1 = boost::get<OpcUaBoolean>(variantValue_);
				OpcUaBoolean value2 = variantValue.variant<OpcUaBoolean>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte value1 = boost::get<OpcUaSByte>(variantValue_);
				OpcUaSByte value2 = variantValue.variant<OpcUaSByte>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte value1 = boost::get<OpcUaByte>(variantValue_);
				OpcUaByte value2 = variantValue.variant<OpcUaByte>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 value1 = boost::get<OpcUaInt16>(variantValue_);
				OpcUaInt16 value2 = variantValue.variant<OpcUaInt16>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 value1 = boost::get<OpcUaUInt16>(variantValue_);
				OpcUaUInt16 value2 = variantValue.variant<OpcUaUInt16>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 value1 = boost::get<OpcUaInt32>(variantValue_);
				OpcUaInt32 value2 = variantValue.variant<OpcUaInt32>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value1 = boost::get<OpcUaUInt32>(variantValue_);
				OpcUaUInt32 value2 = variantValue.variant<OpcUaUInt32>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 value1 = boost::get<OpcUaInt64>(variantValue_);
				OpcUaInt64 value2 = variantValue.variant<OpcUaInt64>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 value1 = boost::get<OpcUaUInt64>(variantValue_);
				OpcUaUInt64 value2 = variantValue.variant<OpcUaUInt64>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat value1 = boost::get<OpcUaFloat>(variantValue_);
				OpcUaFloat value2 = variantValue.variant<OpcUaFloat>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble value1 = boost::get<OpcUaDouble>(variantValue_);
				OpcUaDouble value2 = variantValue.variant<OpcUaDouble>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime value1 = boost::get<OpcUaDateTime>(variantValue_);
				OpcUaDateTime value2 = variantValue.variant<OpcUaDateTime>();
				return value1 < value2;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaInt32 value1 = boost::get<OpcUaStatusCode>(variantValue_);
				OpcUaInt32 value2 = variantValue.variant<OpcUaStatusCode>();
				return value1 == value2;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaGuid::SPtr value1 = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaGuid::SPtr value2 = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaByteString::SPtr value1 = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaByteString::SPtr value2 = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaString::SPtr value1 = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaString::SPtr value2 = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				// FIXME: actualy not used
				return false;
			}
			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaNodeId::SPtr value1 = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaNodeId::SPtr value2 = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaExpandedNodeId::SPtr value1 = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaExpandedNodeId::SPtr value2 = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaQualifiedName::SPtr value1 = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaQualifiedName::SPtr value2 = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				// FIXME: actualy not used
				return false;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				// FIXME: actualy not used
				return false;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaDataValue::SPtr value1 = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaDataValue::SPtr value2 = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr2.objectSPtr_);
				return *value1 < *value2;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				OpcUaVariantSPtr opcUaVariantSPtr1 = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaVariantSPtr opcUaVariantSPtr2 = variantValue.variant<OpcUaVariantSPtr>();
				OpcUaDiagnosticInfo::SPtr value1 = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr1.objectSPtr_);
				OpcUaDiagnosticInfo::SPtr value2 = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr2.objectSPtr_);
				// FIXME: todo
				return false;
				//return *value1 < *value2;
			}
		}
		return false;
	}

	bool
	OpcUaVariantValue::operator<=(OpcUaVariantValue& variantValue)
	{
		return operator==(variantValue) || operator<(variantValue);
	}

	bool
	OpcUaVariantValue::operator>(OpcUaVariantValue& variantValue)
	{
		return operator!=(variantValue) && !operator<(variantValue);
	}

	bool
	OpcUaVariantValue::operator>=(OpcUaVariantValue& variantValue)
	{
		return !operator<(variantValue);
	}

	bool
	OpcUaVariantValue::fromString(const std::string& string)
	{
		// get type and value
		size_t pos = string.find(":");
		if (pos == std::string::npos) return false;
		std::string typeString = string.substr(0, pos);
		std::string valueString = string.substr(pos+1,string.length()-pos-1);

		// get build in type
		OpcUaBuildInType type = OpcUaBuildInTypeMap::string2BuildInType(typeString);

		// create build in type
		return fromString(type, valueString);
	}

	bool
	OpcUaVariantValue::fromString(OpcUaBuildInType type, const std::string& string)
	{
		switch (type)
		{
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				std::string stringValue = string;
				boost::to_upper(stringValue);
				OpcUaBoolean value;
				if (stringValue == "TRUE") value = true;
				else value = false;
			    variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte value;
				try {
					value = (OpcUaSByte)boost::lexical_cast<OpcUaInt16>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte value;
				try {
					value = (OpcUaByte)boost::lexical_cast<OpcUaUInt16>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 value;
				try {
					value = boost::lexical_cast<OpcUaInt16>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 value;
				try {
					value = boost::lexical_cast<OpcUaUInt16>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 value;
				try {
					value = boost::lexical_cast<OpcUaInt32>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value;
				try {
					value = boost::lexical_cast<OpcUaUInt32>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 value;
				try {
					value = boost::lexical_cast<OpcUaInt64>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 value;
				try {
					value = boost::lexical_cast<OpcUaUInt64>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat value;
				try {
					value = boost::lexical_cast<OpcUaFloat>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble value;
				try {
					value = boost::lexical_cast<OpcUaDouble>(string);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast")
						.parameter("Value", string)
						.parameter("What", e.what());
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime value;
				if (!value.fromISOString(string)) {
					Log(Error, "invalid time value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaStatusCode value = OpcUaStatusCodeMap::statusCode(string);
				if (value == BadStatusCodeUnknown) {
					Log(Error, "invalid status code value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
				if (!value->value(string)) {
					Log(Error, "invalid guid value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
				if (!value->fromHexString(string)) {
					Log(Error, "invalid hex string value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaString::SPtr value = constructSPtr<OpcUaString>();
				value->value(string);
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				// FIXME: actualy not used
				return false;
				break;
			}

			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaNodeId::SPtr value = constructSPtr<OpcUaNodeId>();
				if (!value->fromString(string)) {
					Log(Error, "invalid node id value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				return false;
				break;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaQualifiedName::SPtr value = constructSPtr<OpcUaQualifiedName>();
				if (!value->fromString(string)) {
					Log(Error, "invalid qualified name value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaLocalizedText::SPtr value = constructSPtr<OpcUaLocalizedText>();
				if (!value->fromString(string)) {
					Log(Error, "invalid localized text value")
						.parameter("Value", string);
					return false;
				}
				variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				return false;
				break;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				return false;
				break;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				return false;
				break;
			}
			default:
			{
				Log(Error, "unknown data type")
					.parameter("Value", string);
				return false;
				return false;
			}
		}

		return true;
	}

	void 
	OpcUaVariantValue::copyTo(OpcUaVariantValue& variantValue)
	{
		switch (variantType()) 
		{
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean value;
				value = boost::get<OpcUaBoolean>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte value;
				value = boost::get<OpcUaSByte>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte value;
				value = boost::get<OpcUaByte>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 value;
				value = boost::get<OpcUaInt16>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 value;
				value = boost::get<OpcUaUInt16>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 value;
				value = boost::get<OpcUaInt32>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value;
				value = boost::get<OpcUaUInt32>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 value;
				value = boost::get<OpcUaInt64>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 value;
				value = boost::get<OpcUaUInt64>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat value;
				value = boost::get<OpcUaFloat>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble value;
				value = boost::get<OpcUaDouble>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime value;
				boost::get<OpcUaDateTime>(variantValue_).copyTo(value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaStatusCode value;
				value = boost::get<OpcUaStatusCode>(variantValue_);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaGuid::SPtr opcUaGuidSPtr = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr.objectSPtr_);
				opcUaGuidSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaByteString::SPtr opcUaByteStringSPtr = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr.objectSPtr_);
				opcUaByteStringSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaString::SPtr value = constructSPtr<OpcUaString>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaString::SPtr opcUaStringSPtr = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr.objectSPtr_);
				opcUaStringSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				// FIXME: actualy not used
				break;
			}
			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaNodeId::SPtr value = constructSPtr<OpcUaNodeId>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaNodeId::SPtr opcUaNodeIdSPtr = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr.objectSPtr_);
				opcUaNodeIdSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaExpandedNodeId::SPtr value = constructSPtr<OpcUaExpandedNodeId>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr.objectSPtr_);
				opcUaExpandedNodeIdSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaQualifiedName::SPtr value = constructSPtr<OpcUaQualifiedName>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr.objectSPtr_);
				opcUaQualifiedNameSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaLocalizedText::SPtr value = constructSPtr<OpcUaLocalizedText>();
				OpcUaVariantSPtr opcUaVariantSPtr = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr.objectSPtr_);
				opcUaLocalizedTextSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaExtensionObject::SPtr value = constructSPtr<OpcUaExtensionObject>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr.objectSPtr_);
				opcUaExtensionObjectSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				OpcUaDataValue::SPtr value = constructSPtr<OpcUaDataValue>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaDataValue::SPtr dataValueSPtr = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr.objectSPtr_);
				dataValueSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				OpcUaDiagnosticInfo::SPtr value = constructSPtr<OpcUaDiagnosticInfo>();
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaDiagnosticInfo::SPtr dataValueSPtr = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr.objectSPtr_);
				dataValueSPtr->copyTo(*value);
				variantValue.variant(value);
				break;
			}
		}
	}

	void 
	OpcUaVariantValue::out(std::ostream& os) const
	{
		switch (variantType()) 
		{
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				os << boost::get<OpcUaBoolean>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				os << (int64_t)boost::get<OpcUaSByte>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				os << (int64_t)boost::get<OpcUaByte>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				os << (int64_t)boost::get<OpcUaInt16>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				os << (int64_t)boost::get<OpcUaUInt16>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				os << boost::get<OpcUaInt32>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				os << boost::get<OpcUaUInt32>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				os << boost::get<OpcUaInt64>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				os << boost::get<OpcUaUInt64>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				os << boost::get<OpcUaFloat>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				os << boost::get<OpcUaDouble>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				os << boost::get<OpcUaDateTime>(variantValue_);
				break;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				os << OpcUaStatusCodeMap::shortString(boost::get<OpcUaStatusCode>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaGuid::SPtr opcUaGuidSPtr = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaGuidSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaByteString::SPtr opcUaByteStringSPtr = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaByteStringSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaString::SPtr opcUaStringSPtr = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaStringSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				// FIXME: actualy not used
				break;
			}
			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaNodeId::SPtr opcUaNodeIdSPtr = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaNodeIdSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaExpandedNodeIdSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaQualifiedNameSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr opcUaVariantSPtr = boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaLocalizedTextSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr.objectSPtr_);
				os << *opcUaExtensionObjectSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaDataValue::SPtr dataValueSPtr = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr.objectSPtr_);
				os << *dataValueSPtr;
				break;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaDiagnosticInfo::SPtr dataValueSPtr = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr.objectSPtr_);
				os << *dataValueSPtr;
				break;
			}
		}
	}

	void 
	OpcUaVariantValue::opcUaBinaryEncode(std::ostream& os, OpcUaBuildInType variantType) const
	{
		switch (variantType) 
		{
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaBoolean>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaSByte>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaByte>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaInt16>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaUInt16>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaInt32>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaUInt32>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaInt64>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaUInt64>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaFloat>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaDouble>(variantValue_));
				break;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				boost::get<OpcUaDateTime>(variantValue_).opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaInt32 value = (OpcUaInt32)boost::get<OpcUaStatusCode>(variantValue_);
				OpcUaNumber::opcUaBinaryEncode(os, value);
				break;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaGuid::SPtr opcUaGuidSPtr = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr.objectSPtr_);
				opcUaGuidSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaByteString::SPtr opcUaByteStringSPtr = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr.objectSPtr_);
				opcUaByteStringSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaString::SPtr opcUaStringSPtr = boost::static_pointer_cast<OpcUaString>(opcUaVariantSPtr.objectSPtr_);
				opcUaStringSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaXmlElement::SPtr opcUaXmlElementSPtr = boost::static_pointer_cast<OpcUaXmlElement>(opcUaVariantSPtr.objectSPtr_);
				opcUaXmlElementSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaNodeId::SPtr opcUaNodeIdSPtr = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr.objectSPtr_);
				opcUaNodeIdSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr.objectSPtr_);
				opcUaExpandedNodeIdSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr.objectSPtr_);
				opcUaQualifiedNameSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr.objectSPtr_);
				opcUaLocalizedTextSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr.objectSPtr_);
				opcUaExtensionObjectSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaDataValue::SPtr dataValueSPtr = boost::static_pointer_cast<OpcUaDataValue>(opcUaVariantSPtr.objectSPtr_);
				dataValueSPtr->opcUaBinaryEncode(os);
				break;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaDiagnosticInfo::SPtr dataValueSPtr = boost::static_pointer_cast<OpcUaDiagnosticInfo>(opcUaVariantSPtr.objectSPtr_);
				dataValueSPtr->opcUaBinaryEncode(os);
				break;
			}
		}
	}
		
	void 
	OpcUaVariantValue::opcUaBinaryDecode(std::istream& is, OpcUaBuildInType variantType)
	{
		OpcUaVariantValueType opcUaVariantValue;
		switch (variantType) 
		{
			case  OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean opcUaBoolean;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaBoolean);
				opcUaVariantValue = opcUaBoolean;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte opcUaSByte;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaSByte);
				opcUaVariantValue = opcUaSByte;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte opcUaByte;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaByte);
				opcUaVariantValue = opcUaByte;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 opcUaInt16;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaInt16);
				opcUaVariantValue = opcUaInt16;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 opcUaUInt16;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaUInt16);
				opcUaVariantValue = opcUaUInt16;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 opcUaInt32;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaInt32);
				opcUaVariantValue = opcUaInt32;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 opcUaUInt32;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaUInt32);
				opcUaVariantValue = opcUaUInt32;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 opcUaInt64;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaInt64);
				opcUaVariantValue = opcUaInt64;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 opcUaUInt64;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaUInt64);
				opcUaVariantValue = opcUaUInt64;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat opcUaFloat;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaFloat);
				opcUaVariantValue = opcUaFloat;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble opcUaDouble;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaDouble);
				opcUaVariantValue = opcUaDouble;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime opcUaDateTime;
				opcUaDateTime.opcUaBinaryDecode(is);
				opcUaVariantValue = opcUaDateTime;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaInt32 opcUaStatusCode;
				OpcUaNumber::opcUaBinaryDecode(is, opcUaStatusCode);
				opcUaVariantValue = (OpcUaStatusCode)opcUaStatusCode;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr val;

				OpcUaGuid::SPtr opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
				opcUaGuidSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaGuidSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaGuid;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr val;

				OpcUaByteString::SPtr opcUaByteStringSPtr = constructSPtr<OpcUaByteString>();
				opcUaByteStringSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaByteStringSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaByteString;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaString:
			{
				OpcUaVariantSPtr val;

				OpcUaString::SPtr opcUaStringSPtr = constructSPtr<OpcUaString>();
				opcUaStringSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaStringSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaString;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaXmlElement:
			{
				OpcUaVariantSPtr val;

				OpcUaXmlElement::SPtr opcUaXmlElementSPtr = constructSPtr<OpcUaXmlElement>();
				opcUaXmlElementSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaXmlElementSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaXmlElement;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr val;

				OpcUaNodeId::SPtr opcUaNodeIdSPtr = constructSPtr<OpcUaNodeId>();
				opcUaNodeIdSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaNodeIdSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaNodeId;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr val;

				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = constructSPtr<OpcUaExpandedNodeId>();
				opcUaExpandedNodeIdSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaExpandedNodeIdSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExpandedNodeId;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr val;

				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = constructSPtr<OpcUaQualifiedName>();
				opcUaQualifiedNameSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaQualifiedNameSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaQualifiedName;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr val;

				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = constructSPtr<OpcUaLocalizedText>();
				opcUaLocalizedTextSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaLocalizedTextSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaLocalizedText;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr val;

				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = constructSPtr<OpcUaExtensionObject>();
				opcUaExtensionObjectSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = opcUaExtensionObjectSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExtensionObject;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaDataValue:
			{
				OpcUaVariantSPtr val;

				OpcUaDataValue::SPtr dataValueSPtr = constructSPtr<OpcUaDataValue>();
				dataValueSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = dataValueSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaDataValue;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				OpcUaVariantSPtr val;

				OpcUaDiagnosticInfo::SPtr diagnosticInfoSPtr = constructSPtr<OpcUaDiagnosticInfo>();
				diagnosticInfoSPtr->opcUaBinaryDecode(is);
				val.objectSPtr_ = diagnosticInfoSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaDiagnosticInfo;
				variantValue_ = val;
				break;
			}
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaVariant
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaVariant::OpcUaVariant(void)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
	}

	OpcUaVariant::OpcUaVariant(const OpcUaVariant& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		const_cast<OpcUaVariant*>(&value)->copyTo(*this);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaBoolean value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaByte value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaSByte value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaUInt16 value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaInt16 value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaUInt32 value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaInt32 value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaUInt64 value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaInt64 value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaFloat value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaDouble value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaString& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaDateTime& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaGuid& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaByteString& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaXmlElement& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaNodeId& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaExpandedNodeId& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaStatusCode& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaQualifiedName& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaLocalizedText& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}

	OpcUaVariant::OpcUaVariant(const OpcUaExtensionObject& value)
	:  Object()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
		setValue(value);
	}
		
	OpcUaVariant::~OpcUaVariant(void)
	{
	}

	void 
	OpcUaVariant::clear(void)
	{
		OpcUaVariantValue variantValue;
		variantValueVec_.clear();
		variantValueVec_.push_back(variantValue);

		arrayLength_ = -1;
		arrayDimensionsVec_.clear();
	}

	void 
	OpcUaVariant::arrayLength(const OpcUaInt32& arrayLength)
	{
		arrayLength_ = arrayLength;
	}

	OpcUaInt32 
	OpcUaVariant::arrayLength(void)
	{
		return arrayLength_;
	}

	bool
	OpcUaVariant::isArray(void) const
	{
		return arrayLength_ > -1;
	}

	void 
	OpcUaVariant::arrayDimension(const OpcUaArrayDimensionsVec& arrayDimensionsVec)
	{
		if (arrayLength_ < 2) {
			return;
		}
		if (arrayDimensionsVec.size() == 0) {
			return;
		}

		uint32_t count = 0;
		OpcUaArrayDimensionsVec::const_iterator it;
		for (it = arrayDimensionsVec.begin(); it != arrayDimensionsVec.end(); it++) {
			if (it == arrayDimensionsVec.begin()) {
				count = *it;
			}
			else {
				count *= *it;
			}
		}

		if (arrayLength_ != count) {
			return;
		}

		arrayDimensionsVec_.clear();
		arrayDimensionsVec_ = arrayDimensionsVec;
	}
	
	OpcUaArrayDimensionsVec&
	OpcUaVariant::arrayDimension(void)
	{
		return arrayDimensionsVec_;
	}

	void 
	OpcUaVariant::variant(const OpcUaVariantValue::Vec& variantValueVec)
	{
		variantValueVec_ = variantValueVec;
		arrayLength_ = variantValueVec_.size();
	}

	OpcUaVariantValue::Vec& 
	OpcUaVariant::variant(void)
	{
		return variantValueVec_;
	}

	void 
	OpcUaVariant::pushBack(const OpcUaVariantValue& variantValue)
	{
		if (arrayLength_ == -1 && variantValueVec_.size() == 1) {
			variantValueVec_[0] = variantValue;
			arrayLength_ = variantValueVec_.size();
			return;
		}

		variantValueVec_.push_back(variantValue);
		arrayLength_ = variantValueVec_.size();
	}

	OpcUaBuildInType 
	OpcUaVariant::variantType(void) const
	{
		if (variantValueVec_.size() == 0) {
			return OpcUaBuildInType_Unknown;
		}
		return variantValueVec_[0].variantType();
	}

	bool
	OpcUaVariant::isNull(void) const
	{
		return variantType() == OpcUaBuildInType_Unknown;
	}

	bool
	OpcUaVariant::fromString(const std::string& string)
	{
		// split string into type and variable
		size_t pos = string.find(":");
		if (pos == std::string::npos) return false;

		std::string typeString = string.substr(0, pos);
		std::string valueString = string.substr(pos+1, string.length()-pos-1);
		bool isArray = false;

		// type can be an array
		if (typeString.length() > 5) {
			std::string substr = typeString.substr(typeString.length()-5, 5);
			boost::to_upper(substr);
			if (substr == "ARRAY") {
				isArray = true;
				typeString = typeString.substr(0, typeString.length()-5);
			}
		}

		// get build in type
		OpcUaBuildInType type = OpcUaBuildInTypeMap::string2BuildInType(typeString);

		// create build in type
		return fromString(type, isArray, valueString);
	}

	bool
	OpcUaVariant::fromString(OpcUaBuildInType type, bool isArray, const std::string& string)
	{
		// FIXME: read array
		if (isArray) return false;

		OpcUaVariantValue variantValue;
		if (!variantValue.fromString(type, string)) return false;
		clear();
		variantValueVec_[0] = variantValue;
		return true;
	}

	void 
	OpcUaVariant::copyTo(OpcUaVariant& variant)
	{
		variant.variant().clear();
		OpcUaVariantValue::Vec& sourceVariantValueVec = this->variant();
		OpcUaVariantValue::Vec& destVariantValueVec = variant.variant();

		OpcUaVariantValue::Vec::iterator it;
		for (it = sourceVariantValueVec.begin(); it != sourceVariantValueVec.end(); it++) {
			OpcUaVariantValue value;
			it->copyTo(value);
			destVariantValueVec.push_back(value);
		}

		variant.arrayLength(arrayLength_);
		variant.arrayDimension(arrayDimensionsVec_);
	}

	void
	OpcUaVariant::copyFrom(OpcUaVariant& variant)
	{
		variant.copyTo(*this);
	}

	bool
	OpcUaVariant::operator<(const OpcUaVariant& variant) const
	{
		OpcUaVariant* v = const_cast<OpcUaVariant*>(&variant);

		if (v->arrayLength() < arrayLength_) return true;
		if (v->arrayLength() > arrayLength_) return false;
		if (v->variant().size() < variantValueVec_.size() ) return true;
		if (v->variant().size() > variantValueVec_.size() ) return false;
		if (v->arrayDimension().size() < arrayDimensionsVec_.size()) return true;
		if (v->arrayDimension().size() > arrayDimensionsVec_.size()) return false;

		OpcUaVariantValue::Vec& sourceVariantValueVec = const_cast<OpcUaVariant*>(this)->variant();
		OpcUaVariantValue::Vec& destVariantValueVec = v->variant();
		for (uint32_t idx=0; idx<variantValueVec_.size(); idx++) {
			if (sourceVariantValueVec[idx] < destVariantValueVec[idx]) return true;
		}

		OpcUaArrayDimensionsVec& sourceDimensionsVec = const_cast<OpcUaVariant*>(this)->arrayDimensionsVec_;
		OpcUaArrayDimensionsVec& destDimensionsVec = v->arrayDimension();
		for (uint32_t idx=0; idx<sourceDimensionsVec.size(); idx++) {
			if (sourceDimensionsVec[idx] < destDimensionsVec[idx]) return true;
		}

		return true;
	}

	bool 
	OpcUaVariant::operator==(OpcUaVariant& variant)
	{
		if (variant.arrayLength() != arrayLength_) return false;
		if (variant.variant().size() != variantValueVec_.size() ) return false;
		if (variant.arrayDimension().size() != arrayDimensionsVec_.size()) return false;

		OpcUaVariantValue::Vec& sourceVariantValueVec = this->variant();
		OpcUaVariantValue::Vec& destVariantValueVec = variant.variant();
		for (uint32_t idx=0; idx<variantValueVec_.size(); idx++) {
			if (sourceVariantValueVec[idx] != destVariantValueVec[idx]) return false; 
		}

		OpcUaArrayDimensionsVec& sourceDimensionsVec = arrayDimensionsVec_;
		OpcUaArrayDimensionsVec& destDimensionsVec = variant.arrayDimension();
		for (uint32_t idx=0; idx<sourceDimensionsVec.size(); idx++) {
			if (sourceDimensionsVec[idx] != destDimensionsVec[idx]) return false; 
		}

		return true;
	}

	bool 
	OpcUaVariant::operator!=(OpcUaVariant& variant)
	{
		return !operator==(variant);
	}

	void 
	OpcUaVariant::out(std::ostream& os) const
	{
		if (this->variantType() == OpcUaBuildInType_Unknown) {
			os << "---";
			return;
		}

		if (arrayLength_ == -1) {
			os << variantValueVec_[0];
		}
		else if (arrayLength_ == 0) {
			os << "[]";
		} 
		else {
			bool first = true;
			OpcUaVariantValue::Vec::const_iterator it;
			os << "[";
			for (it = variantValueVec_.begin(); it != variantValueVec_.end(); it++) {
				if (!first) os << ",";
				os << *it;
				first = false;
			}
			os << "]";
		}
	}

	void
	OpcUaVariant::setValue(const OpcUaBoolean value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaByte value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaSByte value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaUInt16 value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaInt16 value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaUInt32 value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaInt32 value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaUInt64 value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaInt64 value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaFloat value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaDouble value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaString& value)
	{
		OpcUaString::SPtr tmpValue = constructSPtr<OpcUaString>();
		const_cast<OpcUaString*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaDateTime& value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaGuid& value)
	{
		OpcUaGuid::SPtr tmpValue = constructSPtr<OpcUaGuid>();
		const_cast<OpcUaGuid*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaByteString& value)
	{
		OpcUaByteString::SPtr tmpValue = constructSPtr<OpcUaByteString>();
		const_cast<OpcUaByteString*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaXmlElement& value)
	{
		OpcUaXmlElement::SPtr tmpValue = constructSPtr<OpcUaXmlElement>();
		const_cast<OpcUaXmlElement*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaNodeId& value)
	{
		OpcUaNodeId::SPtr tmpValue = constructSPtr<OpcUaNodeId>();
		const_cast<OpcUaNodeId*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaExpandedNodeId& value)
	{
		OpcUaExpandedNodeId::SPtr tmpValue = constructSPtr<OpcUaExpandedNodeId>();
		const_cast<OpcUaExpandedNodeId*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaStatusCode& value)
	{
		variant(value);
	}

	void
	OpcUaVariant::setValue(const OpcUaQualifiedName& value)
	{
		OpcUaQualifiedName::SPtr tmpValue = constructSPtr<OpcUaQualifiedName>();
		const_cast<OpcUaQualifiedName*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaLocalizedText& value)
	{
		OpcUaLocalizedText::SPtr tmpValue = constructSPtr<OpcUaLocalizedText>();
		const_cast<OpcUaLocalizedText*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaExtensionObject& value)
	{
		OpcUaExtensionObject::SPtr tmpValue = constructSPtr<OpcUaExtensionObject>();
		const_cast<OpcUaExtensionObject*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaDataValue& value)
	{
		OpcUaDataValue::SPtr tmpValue = constructSPtr<OpcUaDataValue>();
		const_cast<OpcUaDataValue*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	void
	OpcUaVariant::setValue(const OpcUaDiagnosticInfo& value)
	{
		OpcUaDiagnosticInfo::SPtr tmpValue = constructSPtr<OpcUaDiagnosticInfo>();
		const_cast<OpcUaDiagnosticInfo*>(&value)->copyTo(*tmpValue);
		variant(tmpValue);
	}

	bool
	OpcUaVariant::getValue(OpcUaBoolean& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
		value = variant<OpcUaBoolean>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaByte& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaByte) return false;
		value = variant<OpcUaByte>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaSByte& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaSByte) return false;
		value = variant<OpcUaSByte>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaUInt16& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaUInt16) return false;
		value = variant<OpcUaUInt16>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaInt16& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaInt16) return false;
		value = variant<OpcUaInt16>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaUInt32& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
		value = variant<OpcUaUInt32>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaInt32& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaInt32) return false;
		value = variant<OpcUaInt32>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaUInt64& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaUInt64) return false;
		value = variant<OpcUaUInt64>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaInt64& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaInt64) return false;
		value = variant<OpcUaInt64>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaFloat& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaFloat) return false;
		value = variant<OpcUaFloat>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaDouble& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaDouble) return false;
		value = variant<OpcUaDouble>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaString& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaString) return false;
		OpcUaString::SPtr tmpValue = variantSPtr<OpcUaString>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaDateTime& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaDateTime) return false;
		value = variant<OpcUaDateTime>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaGuid& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaGuid) return false;
		OpcUaGuid::SPtr tmpValue = variantSPtr<OpcUaGuid>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaByteString& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaByteString) return false;
		OpcUaByteString::SPtr tmpValue = variantSPtr<OpcUaByteString>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaXmlElement& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaXmlElement) return false;
		OpcUaXmlElement::SPtr tmpValue = variantSPtr<OpcUaXmlElement>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaNodeId& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaNodeId) return false;
		OpcUaNodeId::SPtr tmpValue = variantSPtr<OpcUaNodeId>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaExpandedNodeId& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaExpandedNodeId) return false;
		OpcUaExpandedNodeId::SPtr tmpValue = variantSPtr<OpcUaExpandedNodeId>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaStatusCode& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaStatusCode) return false;
		value = variant<OpcUaStatusCode>();
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaQualifiedName& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaQualifiedName) return false;
		OpcUaQualifiedName::SPtr tmpValue = variantSPtr<OpcUaQualifiedName>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaLocalizedText& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaLocalizedText) return false;
		OpcUaLocalizedText::SPtr tmpValue = variantSPtr<OpcUaLocalizedText>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaExtensionObject& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaExtensionObject) return false;
		OpcUaExtensionObject::SPtr tmpValue = variantSPtr<OpcUaExtensionObject>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaDataValue& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaDataValue) return false;
		OpcUaDataValue::SPtr tmpValue = variantSPtr<OpcUaDataValue>();
		tmpValue->copyTo(value);
		return true;
	}

	bool
	OpcUaVariant::getValue(OpcUaDiagnosticInfo& value)
	{
		if (variantType() != OpcUaBuildInType_OpcUaDiagnosticInfo) return false;
		OpcUaDiagnosticInfo::SPtr tmpValue = variantSPtr<OpcUaDiagnosticInfo>();
		tmpValue->copyTo(value);
		return true;
	}

	void 
	OpcUaVariant::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaBuildInType variantType = this->variantType();
		OpcUaByte encodingMask = (OpcUaByte)variantType;
		OpcUaInt32 arrayLength = arrayLength_;

		// handle null value
		if (arrayLength_ == -1 && isNull()) {
			encodingMask = 0x00;
			OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
			return;
		}

		// handle array 
		if (arrayLength != -1 && arrayLength != variantValueVec_.size()) arrayLength = 0;
		if (arrayLength != -1 && variantType == OpcUaBuildInType_Unknown) arrayLength = 0; 

		if (arrayLength != -1) {
			encodingMask += 128;
		}

		if (arrayDimensionsVec_.size() > 0) {
			encodingMask += 64;
		}

		OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
		if (arrayLength != -1) {
			OpcUaNumber::opcUaBinaryEncode(os, arrayLength);
		}

		if (variantType != OpcUaBuildInType_Unknown) {
			if (arrayLength == -1) {
				variantValueVec_[0].opcUaBinaryEncode(os, variantType);
			}
			else if (arrayLength == 0) {
			} 
			else {
				OpcUaVariantValue::Vec::const_iterator it;
				for (it = variantValueVec_.begin(); it != variantValueVec_.end(); it++) {
					it->opcUaBinaryEncode(os, variantType);
				}
			}
		}

		if (arrayDimensionsVec_.size() > 0) {
			OpcUaArrayDimensionsVec::const_iterator it;
			for (it = arrayDimensionsVec_.begin(); it != arrayDimensionsVec_.end(); it++) {
				OpcUaNumber::opcUaBinaryEncode(os, *it);
			}
		}
	}
		
	void 
	OpcUaVariant::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;

		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		// handle null value
		if (encodingMask == 0x00) return;

		arrayLength_ = -1;
		if ((encodingMask & 128) == 128) {
			OpcUaNumber::opcUaBinaryDecode(is, arrayLength_);
		}

		OpcUaByte encodingMaskTmp = encodingMask & 0x3F;
		OpcUaBuildInType variantType = (OpcUaBuildInType)encodingMaskTmp;

		variantValueVec_.clear();
		if (variantType != OpcUaBuildInType_Unknown) {
			if (arrayLength_ == -1) {
				OpcUaVariantValue variantValue;
				variantValueVec_.push_back(variantValue);
				variantValueVec_[0].opcUaBinaryDecode(is, variantType);
			}
			else if (arrayLength_ == 0) {
			}
			else {
				for (uint32_t idx=0; idx<(uint32_t)arrayLength_; idx++) {
					OpcUaVariantValue variantValue;
					variantValue.opcUaBinaryDecode(is, variantType);
					variantValueVec_.push_back(variantValue);
				}
			}
		}

		arrayDimensionsVec_.clear();

		if (arrayLength_ < 2) {
			return;
		}

		if ((encodingMask & 64) == 64) {
			OpcUaUInt32 arrayDimensions;
			OpcUaNumber::opcUaBinaryDecode(is, arrayDimensions);
			arrayDimensionsVec_.push_back(arrayDimensions);
			OpcUaUInt32 count = arrayDimensions;

			while (count < (uint32_t)arrayLength_) {
				OpcUaNumber::opcUaBinaryDecode(is, arrayDimensions);
				arrayDimensionsVec_.push_back(arrayDimensions);
				count = count * arrayDimensions;
			}
		}
	}

	bool
	OpcUaVariant::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaVariant::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		switch (variantType())
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				if (isArray()) return xmlEncodeBooleanArray(pt, xmlns);
				else return xmlEncodeBooleanScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaSByte:
			{
				if (isArray()) return xmlEncodeSByteArray(pt, xmlns);
				else return xmlEncodeSByteScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				if (isArray()) return xmlEncodeByteArray(pt, xmlns);
				else return xmlEncodeByteScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				if (isArray()) return xmlEncodeInt16Array(pt, xmlns);
				else return xmlEncodeInt16Scalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				if (isArray()) return xmlEncodeUInt16Array(pt, xmlns);
				else return xmlEncodeUInt16Scalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				if (isArray()) return xmlEncodeInt32Array(pt, xmlns);
				else return xmlEncodeInt32Scalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				if (isArray()) return xmlEncodeUInt32Array(pt, xmlns);
				else return xmlEncodeUInt32Scalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				if (isArray()) return xmlEncodeInt64Array(pt, xmlns);
				else return xmlEncodeInt64Scalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				if (isArray()) return xmlEncodeUInt64Array(pt, xmlns);
				else return xmlEncodeUInt64Scalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				if (isArray()) return xmlEncodeFloatArray(pt, xmlns);
				else return xmlEncodeFloatScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				if (isArray()) return xmlEncodeDoubleArray(pt, xmlns);
				else return xmlEncodeDoubleScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				if (isArray()) return xmlEncodeDateTimeArray(pt, xmlns);
				else return xmlEncodeDateTimeScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				if (isArray()) return xmlEncodeStringArray(pt, xmlns);
				else return xmlEncodeStringScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				if (isArray()) return xmlEncodeByteStringArray(pt, xmlns);
				else return xmlEncodeByteStringScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				if (isArray()) return xmlEncodeGuidArray(pt, xmlns);
				else return xmlEncodeGuidScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				if (isArray()) return xmlEncodeNodeIdArray(pt, xmlns);
				else return xmlEncodeNodeIdScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				if (isArray()) return xmlEncodeExpandedNodeIdArray(pt, xmlns);
				else return xmlEncodeExpandedNodeIdScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				if (isArray()) return xmlEncodeQualifiedNameArray(pt, xmlns);
				else return xmlEncodeQualifiedNameScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				if (isArray()) return xmlEncodeLocalizedTextArray(pt, xmlns);
				else return xmlEncodeLocalizedTextScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaExtensionObject:
			{
				if (isArray()) return xmlEncodeExtensionObjectArray(pt, xmlns);
				else return xmlEncodeExtensionObjectScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaDataValue:
			{
				if (isArray()) return xmlEncodeDataValueArray(pt, xmlns);
				else return xmlEncodeDataValueScalar(pt, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				if (isArray()) return xmlEncodeDiagnosticInfoArray(pt, xmlns);
				else return xmlEncodeDiagnosticInfoScalar(pt, xmlns);
				break;
			}
			default:
			{
				std::stringstream ss;
				ss << variantType();
				Log(Error, "OpcUaVariant xml encode error - data type unknown")
					.parameter("DataType", ss.str());
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaVariant::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		bool isArray = false;

		// check if first element exist
		if (pt.empty()) {
			Log(Error, "OpcUaVariant xml decode error - variable not exist");
			return false;
		}
		std::string element = pt.front().first;
		boost::property_tree::ptree tmpTree = pt.front().second;

		// check array
		element = xmlns.cutPrefix(element);
		if (boost::starts_with(element, "ListOf")) {
			isArray = true;
			element = element.substr(6, element.size());
		}

		// get data type from element name
		OpcUaBuildInType dataType = OpcUaBuildInTypeMap::string2BuildInType(element);
		if (dataType == OpcUaBuildInType_Unknown) {
			Log(Error, "OpcUaVariant xml decode error - data type unknown")
				.parameter("DataType", element);
			return false;
		}

		// decode element
		switch (dataType)
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				if (isArray) return xmlDecodeBooleanArray(tmpTree, xmlns, element);
				else return xmlDecodeBooleanScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaSByte:
			{
				if (isArray) return xmlDecodeSByteArray(tmpTree, xmlns, element);
				else return xmlDecodeSByteScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				if (isArray) return xmlDecodeByteArray(tmpTree, xmlns, element);
				else return xmlDecodeByteScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				if (isArray) return xmlDecodeInt16Array(tmpTree, xmlns, element);
				else return xmlDecodeInt16Scalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				if (isArray) return xmlDecodeUInt16Array(tmpTree, xmlns, element);
				else return xmlDecodeUInt16Scalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				if (isArray) return xmlDecodeInt32Array(tmpTree, xmlns, element);
				else return xmlDecodeInt32Scalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				if (isArray) return xmlDecodeUInt32Array(tmpTree, xmlns, element);
				else return xmlDecodeUInt32Scalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				if (isArray) return xmlDecodeInt64Array(tmpTree, xmlns, element);
				else return xmlDecodeInt64Scalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				if (isArray) return xmlDecodeUInt64Array(tmpTree, xmlns, element);
				else return xmlDecodeUInt64Scalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				if (isArray) return xmlDecodeFloatArray(tmpTree, xmlns, element);
				else return xmlDecodeFloatScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				if (isArray) return xmlDecodeDoubleArray(tmpTree, xmlns, element);
				else return xmlDecodeDoubleScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				if (isArray) return xmlDecodeDateTimeArray(tmpTree, xmlns, element);
				else return xmlDecodeDateTimeScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				if (isArray) return xmlDecodeStringArray(tmpTree, xmlns, element);
				else return xmlDecodeStringScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				if (isArray) return xmlDecodeByteStringArray(tmpTree, xmlns, element);
				else return xmlDecodeByteStringScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				if (isArray) return xmlDecodeGuidArray(tmpTree, xmlns, element);
				else return xmlDecodeGuidScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				if (isArray) return xmlDecodeNodeIdArray(tmpTree, xmlns, element);
				else return xmlDecodeNodeIdScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				if (isArray) return xmlDecodeExpandedNodeIdArray(tmpTree, xmlns, element);
				else return xmlDecodeExpandedNodeIdScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				if (isArray) return xmlDecodeQualifiedNameArray(tmpTree, xmlns, element);
				else return xmlDecodeQualifiedNameScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				if (isArray) return xmlDecodeLocalizedTextArray(tmpTree, xmlns, element);
				else return xmlDecodeLocalizedTextScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaExtensionObject:
			{
				if (isArray) return xmlDecodeExtensionObjectArray(tmpTree, xmlns, element);
				else return xmlDecodeExtensionObjectScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaDataValue:
			{
				if (isArray) return xmlDecodeDataValueArray(tmpTree, xmlns, element);
				else return xmlDecodeDataValueScalar(tmpTree, xmlns, element);
				break;
			}
			case OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				if (isArray) return xmlDecodeDiagnosticInfoArray(tmpTree, xmlns, element);
				else return xmlDecodeDiagnosticInfoScalar(tmpTree, xmlns, element);
				break;
			}
			default:
			{
				Log(Error, "OpcUaVariant xml encode error - data type unknown")
					.parameter("DataType", element);
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaVariant::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		pt.put("Type", variantType());

		if (variantType() == 0) {
			return true;
		}

		switch (variantType())
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				if (isArray()) return jsonEncodeBooleanArray(pt);
				else return jsonEncodeBooleanScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaSByte:
			{
				if (isArray()) return jsonEncodeSByteArray(pt);
				else return jsonEncodeSByteScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				if (isArray()) return jsonEncodeByteArray(pt);
				else return jsonEncodeByteScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				if (isArray()) return jsonEncodeInt16Array(pt);
				else return jsonEncodeInt16Scalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				if (isArray()) return jsonEncodeUInt16Array(pt);
				else return jsonEncodeUInt16Scalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				if (isArray()) return jsonEncodeInt32Array(pt);
				else return jsonEncodeInt32Scalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				if (isArray()) return jsonEncodeUInt32Array(pt);
				else return jsonEncodeUInt32Scalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				if (isArray()) return jsonEncodeInt64Array(pt);
				else return jsonEncodeInt64Scalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				if (isArray()) return jsonEncodeUInt64Array(pt);
				else return jsonEncodeUInt64Scalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				if (isArray()) return jsonEncodeFloatArray(pt);
				else return jsonEncodeFloatScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				if (isArray()) return jsonEncodeDoubleArray(pt);
				else return jsonEncodeDoubleScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				if (isArray()) return jsonEncodeDateTimeArray(pt);
				else return jsonEncodeDateTimeScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				if (isArray()) return jsonEncodeStringArray(pt);
				else return jsonEncodeStringScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				if (isArray()) return jsonEncodeByteStringArray(pt);
				else return jsonEncodeByteStringScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				if (isArray()) return jsonEncodeGuidArray(pt);
				else return jsonEncodeGuidScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				if (isArray()) return jsonEncodeNodeIdArray(pt);
				else return jsonEncodeNodeIdScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				if (isArray()) return jsonEncodeExpandedNodeIdArray(pt);
				else return jsonEncodeExpandedNodeIdScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				if (isArray()) return jsonEncodeQualifiedNameArray(pt);
				else return jsonEncodeQualifiedNameScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				if (isArray()) return jsonEncodeLocalizedTextArray(pt);
				else return jsonEncodeLocalizedTextScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaExtensionObject:
			{
				if (isArray()) return jsonEncodeExtensionObjectArray(pt);
				else return jsonEncodeExtensionObjectScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaDataValue:
			{
				if (isArray()) return jsonEncodeDataValueArray(pt);
				else return jsonEncodeDataValueScalar(pt);
				break;
			}
			case OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				if (isArray()) return jsonEncodeDiagnosticInfoArray(pt);
				else return jsonEncodeDiagnosticInfoScalar(pt);
				break;
			}
			default:
			{
				std::stringstream ss;
				ss << variantType();
				Log(Error, "OpcUaVariant json encode error - data type unknown")
					.parameter("DataType", ss.str());
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaVariant::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// check if first element exist
		if (pt.empty()) {
			Log(Error, "OpcUaVariant json encode error - variable not exist");
			return false;
		}

		// get data Type
		uint32_t dataType;
		if (!JsonNumber::jsonDecode(pt, dataType, "Type")) {
			Log(Error, "OpcUaVariant json encode error - data type unknown")
				.parameter("Element", "Type");
			return false;
		}
		if (dataType == 0) {
			return true;
		}

		// check if Body is an array
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional("Body");
		if (!tree) {
			Log(Error, "OpcUaVariant json encode error - variable not exist")
				.parameter("Element", "Body");
			return false;
		}

		// check array
		bool isArray = false;
		if (tree->begin() != tree->end() && tree->front().first == "") {
			isArray = true;
		}

		// decode element
		switch (dataType)
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				if (isArray) return jsonDecodeBooleanArray(*tree, "Body");
				else return jsonDecodeBooleanScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaSByte:
			{
				if (isArray) return jsonDecodeSByteArray(*tree, "Body");
				else return jsonDecodeSByteScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				if (isArray) return jsonDecodeByteArray(*tree, "Body");
				else return jsonDecodeByteScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				if (isArray) return jsonDecodeInt16Array(*tree, "Body");
				else return jsonDecodeInt16Scalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				if (isArray) return jsonDecodeUInt16Array(*tree, "Body");
				else return jsonDecodeUInt16Scalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				if (isArray) return jsonDecodeInt32Array(*tree, "Body");
				else return jsonDecodeInt32Scalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				if (isArray) return jsonDecodeUInt32Array(*tree, "Body");
				else return jsonDecodeUInt32Scalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				if (isArray) return jsonDecodeInt64Array(*tree, "Body");
				else return jsonDecodeInt64Scalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				if (isArray) return jsonDecodeUInt64Array(*tree, "Body");
				else return jsonDecodeUInt64Scalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				if (isArray) return jsonDecodeFloatArray(*tree, "Body");
				else return jsonDecodeFloatScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				if (isArray) return jsonDecodeDoubleArray(*tree, "Body");
				else return jsonDecodeDoubleScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				if (isArray) return jsonDecodeDateTimeArray(*tree, "Body");
				else return jsonDecodeDateTimeScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				if (isArray) return jsonDecodeStringArray(*tree, "Body");
				else return jsonDecodeStringScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				if (isArray) return jsonDecodeByteStringArray(*tree, "Body");
				else return jsonDecodeByteStringScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				if (isArray) return jsonDecodeGuidArray(*tree, "Body");
				else return jsonDecodeGuidScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				if (isArray) return jsonDecodeNodeIdArray(*tree, "Body");
				else return jsonDecodeNodeIdScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				if (isArray) return jsonDecodeExpandedNodeIdArray(*tree, "Body");
				else return jsonDecodeExpandedNodeIdScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				if (isArray) return jsonDecodeQualifiedNameArray(*tree, "Body");
				else return jsonDecodeQualifiedNameScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				if (isArray) return jsonDecodeLocalizedTextArray(*tree, "Body");
				else return jsonDecodeLocalizedTextScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaExtensionObject:
			{
				if (isArray) return jsonDecodeExtensionObjectArray(*tree, "Body");
				else return jsonDecodeExtensionObjectScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaDataValue:
			{
				if (isArray) return jsonDecodeDataValueArray(*tree, "Body");
				else return jsonDecodeDataValueScalar(*tree, "Body");
				break;
			}
			case OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				if (isArray) return jsonDecodeDiagnosticInfoArray(*tree, "Body");
				else return jsonDecodeDiagnosticInfoScalar(*tree, "Body");
				break;
			}
			default:
			{
				Log(Error, "OpcUaVariant json encode error - data type unknown")
					.parameter("DataType", dataType);
				return false;
			}
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode boolean
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeBooleanScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaBoolean value = get<OpcUaBoolean>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Boolean"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Boolean");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeBooleanArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaBoolean value = get<OpcUaBoolean>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Boolean"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Boolean");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfBoolean"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeBooleanScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaBoolean value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Boolean");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeBooleanArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Boolean") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Boolean");
				return false;
			}
			OpcUaBoolean value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Boolean");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode sbyte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeSByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaSByte value = get<OpcUaSByte>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("SByte"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "SByte");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeSByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaSByte value = get<OpcUaSByte>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("SByte"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "SByte");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfSByte"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeSByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaSByte value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "SByte");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeSByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "SByte") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "SByte");
				return false;
			}
			OpcUaSByte value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "SByte");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode byte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaByte value = get<OpcUaByte>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Byte"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Byte");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaByte value = get<OpcUaByte>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Byte"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Byte");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfByte"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaByte value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Byte");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Byte") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Byte");
				return false;
			}
			OpcUaByte value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Byte");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode int16
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaInt16 value = get<OpcUaInt16>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Int16"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Int16");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt16 value = get<OpcUaInt16>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Int16"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Int16");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfInt16"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaInt16 value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Int16");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Int16") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Int16");
				return false;
			}
			OpcUaInt16 value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Int16");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode uint16
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeUInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaUInt16 value = get<OpcUaUInt16>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("UInt16"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "UInt16");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeUInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaUInt16 value = get<OpcUaUInt16>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("UInt16"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "UInt16");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfUInt16"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeUInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaUInt16 value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "UInt16");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeUInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "UInt16") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "UInt16");
				return false;
			}
			OpcUaUInt16 value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "UInt16");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode int32
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaInt32 value = get<OpcUaInt32>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Int32"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Int32");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt32 value = get<OpcUaInt32>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Int32"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Int32");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfInt32"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaInt32 value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Int32");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Int32") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Int32");
				return false;
			}
			OpcUaInt32 value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Int32");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode uint32
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeUInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaUInt32 value = get<OpcUaUInt32>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("UInt32"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "UInt32");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeUInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaUInt32 value = get<OpcUaUInt32>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("UInt32"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "UInt32");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfUInt32"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeUInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaUInt32 value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "UInt32");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeUInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "UInt32") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "UInt32");
				return false;
			}
			OpcUaUInt32 value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "UInt32");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode int64
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaInt64 value = get<OpcUaInt64>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Int64"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Int64");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt64 value = get<OpcUaInt64>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Int64"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Int64");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfInt64"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaInt64 value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Int64");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Int64") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Int64");
				return false;
			}
			OpcUaInt64 value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Int64");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode uint64
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeUInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaUInt64 value = get<OpcUaUInt64>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("UInt64"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "UInt64");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeUInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt64 value = get<OpcUaUInt64>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("UInt64"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "UInt64");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfUInt64"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeUInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaUInt64 value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "UInt64");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeUInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "UInt64") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "UInt64");
				return false;
			}
			OpcUaUInt64 value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "UInt64");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode float
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeFloatScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaFloat value = get<OpcUaFloat>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Float"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Float");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeFloatArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaFloat value = get<OpcUaFloat>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Float"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Float");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfFloat"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeFloatScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaFloat value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Float");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeFloatArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Float") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Float");
				return false;
			}
			OpcUaFloat value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Float");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode double
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeDoubleScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaDouble value = get<OpcUaDouble>();
		if (!XmlNumber::xmlEncode(pt, value, xmlns.addPrefix("Double"))) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Double");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeDoubleArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDouble value = get<OpcUaDouble>(idx);
			if (!XmlNumber::xmlEncode(list, value, xmlns.addPrefix("Double"))) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Double");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfDouble"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDoubleScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaDouble value;
		if (!XmlNumber::xmlDecode(pt, value)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Double");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDoubleArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Double") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Double");
				return false;
			}
			OpcUaDouble value;
			if (!XmlNumber::xmlDecode(it->second, value)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Double");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode date time
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeDateTimeScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaDateTime value = get<OpcUaDateTime>();
		if (!value.xmlEncode(pt, "DateTime", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "DateTime");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeDateTimeArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDateTime value = get<OpcUaDateTime>(idx);
			if (!value.xmlEncode(list, "DateTime", xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "DateTime");
				return false;
			}
		}
		pt.add_child(xmlns.addPrefix("ListOfDateTime"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDateTimeScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaDateTime value;
		if (!value.xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "DateTime");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDateTimeArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "DateTime") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "DateTime");
				return false;
			}
			OpcUaDateTime value;
			if (!value.xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "DateTime");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode string
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaString::SPtr value = variantSPtr<OpcUaString>();
		if (!value->xmlEncode(pt, "String", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "String");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaString::SPtr value = getSPtr<OpcUaString>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "String");
				return false;
			}
			list.add_child(xmlns.addPrefix("String"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfString"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaString::SPtr value = constructSPtr<OpcUaString>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "String");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "String") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "String");
				return false;
			}
			OpcUaString::SPtr value = constructSPtr<OpcUaString>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "String");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode byte string
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeByteStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaByteString::SPtr value = variantSPtr<OpcUaByteString>();
		if (!value->xmlEncode(pt, "ByteString", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "ByteString");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeByteStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaByteString::SPtr value = getSPtr<OpcUaByteString>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "ByteString");
				return false;
			}
			list.add_child(xmlns.addPrefix("ByteString"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfByteString"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeByteStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "ByteString");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeByteStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "ByteString") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "ByteString");
				return false;
			}
			OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "ByteString");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode guid
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeGuidScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaGuid::SPtr value = variantSPtr<OpcUaGuid>();
		if (!value->xmlEncode(pt, "Guid", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "Guid");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeGuidArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaGuid::SPtr value = getSPtr<OpcUaGuid>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "Guid");
				return false;
			}
			list.add_child(xmlns.addPrefix("Guid"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfGuid"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeGuidScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "Guid");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeGuidArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "Guid") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Guid");
				return false;
			}
			OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "Guid");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode nodeid
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaNodeId::SPtr value = variantSPtr<OpcUaNodeId>();
		if (!value->xmlEncode(pt, "NodeId", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "NodeId");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaNodeId::SPtr value = getSPtr<OpcUaNodeId>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "NodeId");
				return false;
			}
			list.add_child(xmlns.addPrefix("NodeId"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfNodeId"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaNodeId::SPtr value = constructSPtr<OpcUaNodeId>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "NodeId");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "NodeId") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "NodeId");
				return false;
			}
			OpcUaNodeId::SPtr value = constructSPtr<OpcUaNodeId>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "NodeId");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode expanded nodeid
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeExpandedNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaExpandedNodeId::SPtr value = variantSPtr<OpcUaExpandedNodeId>();
		if (!value->xmlEncode(pt, "ExpandedNodeId", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "ExpandedNodeId");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeExpandedNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaExpandedNodeId::SPtr value = getSPtr<OpcUaExpandedNodeId>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "ExpandedNodeId");
				return false;
			}
			list.add_child(xmlns.addPrefix("ExpandedNodeId"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfExpandedNodeId"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeExpandedNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaExpandedNodeId::SPtr value = constructSPtr<OpcUaExpandedNodeId>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "ExpandedNodeId");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeExpandedNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "ExpandedNodeId") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "ExpandedNodeId");
				return false;
			}
			OpcUaExpandedNodeId::SPtr value = constructSPtr<OpcUaExpandedNodeId>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "ExpandedNodeId");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode qualified name
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeQualifiedNameScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaQualifiedName::SPtr value = variantSPtr<OpcUaQualifiedName>();
		if (!value->xmlEncode(pt, "QualifiedName", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "QualifiedName");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeQualifiedNameArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaQualifiedName::SPtr value = getSPtr<OpcUaQualifiedName>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "QualifiedName");
				return false;
			}
			list.add_child(xmlns.addPrefix("QualifiedName"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfQualifiedName"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeQualifiedNameScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaQualifiedName::SPtr value = constructSPtr<OpcUaQualifiedName>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "QualifiedName");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeQualifiedNameArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "QualifiedName") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "QualifiedName");
				return false;
			}
			OpcUaQualifiedName::SPtr value = constructSPtr<OpcUaQualifiedName>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "QualifiedName");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode localized text
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeLocalizedTextScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaLocalizedText::SPtr value = variantSPtr<OpcUaLocalizedText>();
		if (!value->xmlEncode(pt, "LocalizedText", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "LocalizedText");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeLocalizedTextArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaLocalizedText::SPtr value = getSPtr<OpcUaLocalizedText>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "LocalizedText");
				return false;
			}
			list.add_child(xmlns.addPrefix("LocalizedText"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfLocalizedText"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeLocalizedTextScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaLocalizedText::SPtr value = constructSPtr<OpcUaLocalizedText>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "LocalizedText");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeLocalizedTextArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "LocalizedText") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "LocalizedText");
				return false;
			}
			OpcUaLocalizedText::SPtr value = constructSPtr<OpcUaLocalizedText>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "LocalizedText");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode extension object
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeExtensionObjectScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaExtensionObject::SPtr value = variantSPtr<OpcUaExtensionObject>();
		if (!value->xmlEncode(pt, "ExtensionObject", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "ExtensionObject");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeExtensionObjectArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaExtensionObject::SPtr value = getSPtr<OpcUaExtensionObject>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "ExtensionObject");
				return false;
			}
			list.add_child(xmlns.addPrefix("ExtensionObject"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfExtensionObject"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeExtensionObjectScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaExtensionObject::SPtr value = constructSPtr<OpcUaExtensionObject>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "ExtensionObject");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeExtensionObjectArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "ExtensionObject") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "ExtensionObject");
				return false;
			}
			OpcUaExtensionObject::SPtr value = constructSPtr<OpcUaExtensionObject>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "ExtensionObject");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode data value
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeDataValueScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaDataValue::SPtr value = variantSPtr<OpcUaDataValue>();
		if (!value->xmlEncode(pt, "DataValue", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "DataValue");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeDataValueArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDataValue::SPtr value = getSPtr<OpcUaDataValue>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "DataValue");
				return false;
			}
			list.add_child(xmlns.addPrefix("DataValue"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfDataValue"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDataValueScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaDataValue::SPtr value = constructSPtr<OpcUaDataValue>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "DataValue");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDataValueArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "DataValue") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "DataValue");
				return false;
			}
			OpcUaDataValue::SPtr value = constructSPtr<OpcUaDataValue>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "DataValue");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// xml encode decode diagnostic info
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::xmlEncodeDiagnosticInfoScalar(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaDiagnosticInfo::SPtr value = variantSPtr<OpcUaDiagnosticInfo>();
		if (!value->xmlEncode(pt, "DiagnosticInfo", xmlns)) {
			Log(Error, "OpcUaVariant xml encoder error")
				.parameter("Element", "DiagnosticInfo");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::xmlEncodeDiagnosticInfoArray(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDiagnosticInfo::SPtr value = getSPtr<OpcUaDiagnosticInfo>(idx);
			boost::property_tree::ptree element;
			if (!value->xmlEncode(element, xmlns)) {
				Log(Error, "OpcUaVariant xml encoder error")
					.parameter("Element", "DiagnosticInfo");
				return false;
			}
			list.add_child(xmlns.addPrefix("DiagnosticInfo"), element);
		}
		pt.add_child(xmlns.addPrefix("ListOfDiagnosticInfo"), list);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDiagnosticInfoScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		OpcUaDiagnosticInfo::SPtr value = constructSPtr<OpcUaDiagnosticInfo>();
		if (!value->xmlDecode(pt, xmlns)) {
			Log(Error, "OpcUaVariant xml decode error")
				.parameter("Element", element)
				.parameter("DataType", "DiagnosticInfo");
			return false;
		}
		variant(value);
		return true;
	}

	bool
	OpcUaVariant::xmlDecodeDiagnosticInfoArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element)
	{
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "DiagnosticInfo") {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "DiagnosticInfo");
				return false;
			}
			OpcUaDiagnosticInfo::SPtr value = constructSPtr<OpcUaDiagnosticInfo>();
			if (!value->xmlDecode(it->second, xmlns)) {
				Log(Error, "OpcUaVariant xml decode error")
					.parameter("Element", element)
					.parameter("DataType", "DiagnosticInfo");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json boolean encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeBooleanScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaBoolean value = get<OpcUaBoolean>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "Boolean");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeBooleanArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaBoolean value = get<OpcUaBoolean>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Boolean");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeBooleanScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaBoolean value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "Boolean");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeBooleanArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Boolean");
				return false;
			}
			OpcUaBoolean value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Boolean");
				return false;
			}
			pushBack(value);
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json sbyte encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeSByteScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaSByte value = get<OpcUaSByte>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaSByte");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeSByteArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaSByte value = get<OpcUaSByte>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "SByte");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeSByteScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaSByte value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaSByte");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeSByteArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "SByte");
				return false;
			}
			OpcUaSByte value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "SByte");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json byte encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeByteScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaByte value = get<OpcUaByte>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaByte");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeByteArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaByte value = get<OpcUaByte>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Byte");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeByteScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaByte value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaByte");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeByteArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Byte");
				return false;
			}
			OpcUaByte value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Byte");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json uint16 encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeUInt16Scalar(boost::property_tree::ptree& pt) const
	{
		OpcUaUInt16 value = get<OpcUaUInt16>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaUInt16");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeUInt16Array(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaUInt16 value = get<OpcUaUInt16>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "OpcUaInt16");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeUInt16Scalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaUInt16 value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaUInt16");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeUInt16Array(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "UInt16");
				return false;
			}
			OpcUaUInt16 value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "UInt16");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json int16 encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeInt16Scalar(boost::property_tree::ptree& pt) const
	{
		OpcUaInt16 value = get<OpcUaInt16>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaInt16");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeInt16Array(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt16 value = get<OpcUaInt16>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Int16");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeInt16Scalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaInt16 value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaInt16");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeInt16Array(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Int16");
				return false;
			}
			OpcUaInt16 value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Int16");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json uint32 encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeUInt32Scalar(boost::property_tree::ptree& pt) const
	{
		OpcUaUInt32 value = get<OpcUaUInt32>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaUInt32");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeUInt32Array(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaUInt32 value = get<OpcUaUInt32>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "UInt32");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeUInt32Scalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaUInt32 value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaUInt32");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeUInt32Array(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "UInt32");
				return false;
			}
			OpcUaUInt32 value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "UInt32");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json int32 encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeInt32Scalar(boost::property_tree::ptree& pt) const
	{
		OpcUaInt32 value = get<OpcUaInt32>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaInt32");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeInt32Array(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt32 value = get<OpcUaInt32>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Int32");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeInt32Scalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaInt32 value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaInt32");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeInt32Array(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Int32");
				return false;
			}
			OpcUaInt32 value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Int32");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json uint64 encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeUInt64Scalar(boost::property_tree::ptree& pt) const
	{
		OpcUaUInt64 value = get<OpcUaUInt64>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaUInt64");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeUInt64Array(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaUInt64 value = get<OpcUaUInt64>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "UInt64");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeUInt64Scalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaUInt64 value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaUInt64");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeUInt64Array(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "UInt64");
				return false;
			}
			OpcUaUInt64 value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "UInt64");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json int64 encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeInt64Scalar(boost::property_tree::ptree& pt) const
	{
		OpcUaInt64 value = get<OpcUaInt64>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaInt64");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeInt64Array(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaInt64 value = get<OpcUaInt64>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Int64");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeInt64Scalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaInt64 value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaInt64");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeInt64Array(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Int64");
				return false;
			}
			OpcUaInt64 value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Int64");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json float encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeFloatScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaFloat value = get<OpcUaFloat>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaFloat");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeFloatArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaFloat value = get<OpcUaFloat>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Float");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeFloatScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaFloat value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaFloat");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeFloatArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Float");
				return false;
			}
			OpcUaFloat value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Float");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json double encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeDoubleScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaDouble value = get<OpcUaDouble>();
		if (!JsonNumber::jsonEncode(pt, value, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaDouble");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeDoubleArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDouble value = get<OpcUaDouble>(idx);
			if (!JsonNumber::jsonEncode(list, value, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Double");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDoubleScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaDouble value;
		if (!JsonNumber::jsonDecode(pt, value)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaDouble");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDoubleArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Double");
				return false;
			}
			OpcUaDouble value;
			if (!JsonNumber::jsonDecode(it->second, value)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "Double");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json datetime encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeDateTimeScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaDateTime value = get<OpcUaDateTime>();
		if (!value.jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaDateTime");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeDateTimeArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDateTime value = get<OpcUaDateTime>(idx);
			if (!value.jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "DateTime");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDateTimeScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaDateTime value;
		if (!value.jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaDateTime");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDateTimeArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaDateTime");
				return false;
			}
			OpcUaDateTime value;
			if (!value.jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaDateTime");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json string encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeStringScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaString::SPtr value = getSPtr<OpcUaString>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaString");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeStringArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaString::SPtr value = getSPtr<OpcUaString>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "String");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeStringScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaString::SPtr value = constructSPtr<OpcUaString>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaString");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeStringArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaString");
				return false;
			}
			OpcUaString::SPtr value = constructSPtr<OpcUaString>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaString");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json bytestring encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeByteStringScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaByteString::SPtr value = getSPtr<OpcUaByteString>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcByteUaString");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeByteStringArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaByteString::SPtr value = getSPtr<OpcUaByteString>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "ByteString");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeByteStringScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaByteString");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeByteStringArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaByteString");
				return false;
			}
			OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUByteaString");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json guid encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeGuidScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaGuid::SPtr value = getSPtr<OpcUaGuid>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaGuid");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeGuidArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaGuid::SPtr value = getSPtr<OpcUaGuid>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "Guid");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeGuidScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaGuid");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeGuidArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaGuid");
				return false;
			}
			OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUGuid");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json nodeid encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeNodeIdScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaNodeId::SPtr value = getSPtr<OpcUaNodeId>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaNodeId");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeNodeIdArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaNodeId::SPtr value = getSPtr<OpcUaNodeId>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "NodeId");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeNodeIdScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaNodeId::SPtr value = constructSPtr<OpcUaNodeId>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaNodeId");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeNodeIdArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaNodeId");
				return false;
			}
			OpcUaNodeId::SPtr value = constructSPtr<OpcUaNodeId>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaNodeId");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json enpanded node id encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeExpandedNodeIdScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaExpandedNodeId::SPtr value = getSPtr<OpcUaExpandedNodeId>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaExpandedNodeId");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeExpandedNodeIdArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaExpandedNodeId::SPtr value = getSPtr<OpcUaExpandedNodeId>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "ExpandedNodeId");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeExpandedNodeIdScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaExpandedNodeId::SPtr value = constructSPtr<OpcUaExpandedNodeId>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaExpandedNodeId");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeExpandedNodeIdArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaExpandedNodeId");
				return false;
			}
			OpcUaExpandedNodeId::SPtr value = constructSPtr<OpcUaExpandedNodeId>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaExpandedNodeId");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json qualified name encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeQualifiedNameScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaQualifiedName::SPtr value = getSPtr<OpcUaQualifiedName>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaQualifiedName");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeQualifiedNameArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaQualifiedName::SPtr value = getSPtr<OpcUaQualifiedName>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "QualifiedName");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeQualifiedNameScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaQualifiedName::SPtr value = constructSPtr<OpcUaQualifiedName>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaQualifiedName");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeQualifiedNameArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaQualifiedName");
				return false;
			}
			OpcUaQualifiedName::SPtr value = constructSPtr<OpcUaQualifiedName>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaQualifiedName");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json localized text encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeLocalizedTextScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaLocalizedText::SPtr value = getSPtr<OpcUaLocalizedText>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaLocalizedText");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeLocalizedTextArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaLocalizedText::SPtr value = getSPtr<OpcUaLocalizedText>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "LocalizedText");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeLocalizedTextScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaLocalizedText::SPtr value = constructSPtr<OpcUaLocalizedText>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaLocalizedText");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeLocalizedTextArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaLocalizedText");
				return false;
			}
			OpcUaLocalizedText::SPtr value = constructSPtr<OpcUaLocalizedText>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaLocalizedText");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json extension object encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeExtensionObjectScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaExtensionObject::SPtr value = getSPtr<OpcUaExtensionObject>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaExtensionObject");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeExtensionObjectArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaExtensionObject::SPtr value = getSPtr<OpcUaExtensionObject>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "ExtensionObject");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeExtensionObjectScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaExtensionObject::SPtr value = constructSPtr<OpcUaExtensionObject>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaExtensionObject");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeExtensionObjectArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaExtensionObject");
				return false;
			}
			OpcUaExtensionObject::SPtr value = constructSPtr<OpcUaExtensionObject>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaExtensionObject");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json data value encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeDataValueScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaDataValue::SPtr value = getSPtr<OpcUaDataValue>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaDataValue");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeDataValueArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDataValue::SPtr value = getSPtr<OpcUaDataValue>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "DataValue");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDataValueScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaDataValue::SPtr value = constructSPtr<OpcUaDataValue>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaDataValue");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDataValueArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaDataValue");
				return false;
			}
			OpcUaDataValue::SPtr value = constructSPtr<OpcUaDataValue>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaDataValue");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// json diagnostic info encode decode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaVariant::jsonEncodeDiagnosticInfoScalar(boost::property_tree::ptree& pt) const
	{
		OpcUaDiagnosticInfo::SPtr value = getSPtr<OpcUaDiagnosticInfo>();
		if (!value->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaVariant json encoder error")
				.parameter("Element", "OpcUaDiagnosticInfo");
			return false;
		}
		return true;
	}

	bool
	OpcUaVariant::jsonEncodeDiagnosticInfoArray(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree list;
		for (uint32_t idx=0; idx<arrayLength_; idx++) {
			OpcUaDiagnosticInfo::SPtr value = getSPtr<OpcUaDiagnosticInfo>(idx);
			if (!value->jsonEncode(list, "")) {
				Log(Error, "OpcUaVariant json encoder error")
					.parameter("Element", "DiagnosticInfo");
				return false;
			}
		}
		pt.put_child("Body", list);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDiagnosticInfoScalar(const boost::property_tree::ptree& pt, const std::string& element)
	{
		OpcUaDiagnosticInfo::SPtr value = constructSPtr<OpcUaDiagnosticInfo>();
		if (!value->jsonDecode(pt)) {
			Log(Error, "OpcUaVariant json decode error")
				.parameter("Element", element)
				.parameter("DataType", "OpcUaDiagnosticInfo");
			return false;
		}
		set(value);
		return true;
	}

	bool
	OpcUaVariant::jsonDecodeDiagnosticInfoArray(const boost::property_tree::ptree& pt, const std::string& element)
	{
		for (auto it = pt.begin(); it != pt.end(); it++) {
			if (it->first != "") {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaDiagnosticInfo");
				return false;
			}
			OpcUaDiagnosticInfo::SPtr value = constructSPtr<OpcUaDiagnosticInfo>();
			if (!value->jsonDecode(it->second)) {
				Log(Error, "OpcUaVariant json decode error")
					.parameter("Element", "Body")
					.parameter("DataType", "OpcUaDiagnosticInfo");
				return false;
			}
			pushBack(value);
		}
		return true;
	}

};
