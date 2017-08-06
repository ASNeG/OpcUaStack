/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (timin-ayu@nefteavtomatika.ru)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

namespace OpcUaStackCore
{

	//operator bool(const std::string& value) const
	//{
	//	return true;
	//}



	OpcUaTypeConversion::OpcUaTypeConversion(void)
	{
	}

	OpcUaTypeConversion::~OpcUaTypeConversion(void)
	{
	}

	int8_t OpcUaTypeConversion::indexForConversationTable(OpcUaBuildInType type) {
		switch (type) {
		case OpcUaBuildInType_OpcUaBoolean: 		return 0;
		case OpcUaBuildInType_OpcUaByte:			return 1;
		case OpcUaBuildInType_OpcUaByteString: 		return 2;
		case OpcUaBuildInType_OpcUaDateTime: 		return 3;
		case OpcUaBuildInType_OpcUaDouble: 			return 4;
		case OpcUaBuildInType_OpcUaExpandedNodeId:	return 5;
		case OpcUaBuildInType_OpcUaFloat: 			return 6;
		case OpcUaBuildInType_OpcUaGuid: 			return 7;
		case OpcUaBuildInType_OpcUaInt16: 			return 8;
		case OpcUaBuildInType_OpcUaInt32: 			return 9;
		case OpcUaBuildInType_OpcUaInt64: 			return 10;
		case OpcUaBuildInType_OpcUaNodeId: 			return 11;
		case OpcUaBuildInType_OpcUaSByte: 			return 12;
		case OpcUaBuildInType_OpcUaStatusCode: 		return 13;
		case OpcUaBuildInType_OpcUaString: 			return 14;
		case OpcUaBuildInType_OpcUaLocalizedText: 	return 15;
		case OpcUaBuildInType_OpcUaQualifiedName: 	return 16;
		case OpcUaBuildInType_OpcUaUInt16: 			return 17;
		case OpcUaBuildInType_OpcUaUInt32: 			return 18;
		case OpcUaBuildInType_OpcUaUInt64: 			return 19;
		case OpcUaBuildInType_OpcUaXmlElement: 		return 20;

		default: return -1;
		}
	}

	char
	OpcUaTypeConversion::conversionType(OpcUaBuildInType sourceType, OpcUaBuildInType targetType)
	{
		int8_t sourceTypeIdx = indexForConversationTable(sourceType);
		int8_t targetTypeIdx = indexForConversationTable(targetType);

		if ((sourceTypeIdx >= 0) && (targetTypeIdx >= 0)) {
			return conversationTypeTable[sourceTypeIdx][targetTypeIdx];
		}

		return 'X';
	}

	bool OpcUaTypeConversion::conversion(
		OpcUaVariant::SPtr& sourceVariant,		// source variant data
		OpcUaBuildInType targetType,			// target type
		OpcUaVariant::SPtr& targetVariant 		// target variant data
	)
	{
		if (sourceVariant.get() == nullptr) return false;
		OpcUaBuildInType sourceType = sourceVariant->variantType();

		switch (conversionType(sourceType, targetType)){
		case '-':
			targetVariant->copyFrom(*sourceVariant);
			return true;
		case 'I':
		case 'E': {
			return cast(sourceVariant, targetType, targetVariant);
		}

		case 'X':
			return false;
		}

		return false;
	}

	bool OpcUaTypeConversion::cast(OpcUaVariant::SPtr& sourceVariant, OpcUaBuildInType targetType, OpcUaVariant::SPtr& targetVariant)
	{
		switch (sourceVariant->variantType()) {
		case OpcUaBuildInType_OpcUaBoolean:
			switch (targetType) {
			case OpcUaBuildInType_OpcUaByte:	return cast<OpcUaBoolean, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaBoolean, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaBoolean, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return cast<OpcUaBoolean, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaBoolean, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaBoolean, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return cast<OpcUaBoolean, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString: {
				OpcUaString::SPtr value = constructSPtr<OpcUaString>(sourceVariant->get<OpcUaBoolean>() ? "true" : "false");
				targetVariant->variant(value);

				return true;
			}
			case OpcUaBuildInType_OpcUaUInt16:	return cast<OpcUaBoolean, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return cast<OpcUaBoolean, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaBoolean, OpcUaUInt64>(sourceVariant, targetVariant);
			default: 							return false;
			}
		default:	return false;
		}
	}

	char OpcUaTypeConversion::conversationTypeTable[TYPE_CONVERSATION_TABLE_SIZE][TYPE_CONVERSATION_TABLE_SIZE] = {
			{'-', 'I', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', 'I', 'X', 'E', 'X', 'X', 'I', 'I', 'I', 'X'}, //bool
			{'E', '-', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', 'I', 'X', 'E', 'X', 'X', 'I', 'I', 'I', 'X'}, //byte
			{'X', 'X', '-', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}, //byte string
			{'X', 'X', 'X', '-', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X'}, //datetime
			{'E', 'E', 'X', 'X', '-', 'X', 'E', 'X', 'E', 'E', 'E', 'X', 'E', 'X', 'E', 'X', 'X', 'E', 'E', 'E', 'X'}, //double
			{'X', 'X', 'X', 'X', 'X', '-', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'I', 'X', 'X', 'X', 'X', 'X', 'X'}, //expNodeId
			{'E', 'X', 'X', 'X', 'I', 'X', '-', 'X', 'E', 'E', 'E', 'X', 'E', 'X', 'E', 'X', 'X', 'E', 'E', 'E', 'X'}, //float
			{'X', 'X', 'E', 'X', 'X', 'X', 'X', '-', 'X', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X'}, //guid
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', '-', 'I', 'I', 'X', 'E', 'X', 'E', 'X', 'X', 'E', 'I', 'E', 'X'}, //int16
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', '-', 'I', 'X', 'E', 'E', 'E', 'X', 'X', 'E', 'E', 'X', 'X'}, //int32
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', 'E', '-', 'X', 'E', 'E', 'E', 'X', 'X', 'E', 'E', 'I', 'X'}, //int64
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '-', 'X', 'X', 'I', 'X', 'X', 'X', 'X', 'X', 'X'}, //nodeId
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', '-', 'X', 'E', 'X', 'X', 'I', 'I', 'I', 'X'}, //sbyte
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'I', 'I', 'X', 'X', '-', 'X', 'X', 'X', 'E', 'I', 'I', 'X'}, //statusCode
			{'I', 'I', 'X', 'E', 'I', 'E', 'I', 'I', 'I', 'I', 'I', 'E', 'I', 'X', '-', 'E', 'X', 'I', 'I', 'I', 'X'}, //string
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'I', '-', 'E', 'X', 'X', 'X', 'X'}, //localizedText
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'I', 'X', '-', 'X', 'X', 'X', 'X'}, //qualifiedText
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', 'E', 'X', 'E', 'X', 'X', '-', 'I', 'I', 'X'}, //uint16
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', 'I', 'I', 'X', 'E', 'E', 'E', 'X', 'X', 'E', '-', 'I', 'X'}, //uint32
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', 'E', 'I', 'X', 'E', 'E', 'E', 'X', 'X', 'E', 'Y', '-', 'X'}, //uint64
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '-'}, //xmlElemnt
	};

#if 0

	typedef enum
	{
		OpcUaBuildInType_Unknown = 0,
		OpcUaBuildInType_OpcUaBoolean = 1,
		OpcUaBuildInType_OpcUaSByte = 2,
		OpcUaBuildInType_OpcUaByte = 3,
		OpcUaBuildInType_OpcUaInt16 = 4,
		OpcUaBuildInType_OpcUaUInt16 = 5,
		OpcUaBuildInType_OpcUaInt32 = 6,
		OpcUaBuildInType_OpcUaUInt32 = 7,
		OpcUaBuildInType_OpcUaInt64 = 8,
		OpcUaBuildInType_OpcUaUInt64 = 9,
		OpcUaBuildInType_OpcUaFloat = 10,
		OpcUaBuildInType_OpcUaDouble = 11,
		OpcUaBuildInType_OpcUaString = 12,
		OpcUaBuildInType_OpcUaDateTime = 13,
		OpcUaBuildInType_OpcUaGuid = 14,
		OpcUaBuildInType_OpcUaByteString = 15,
		OpcUaBuildInType_OpcUaXmlElement = 16,
		OpcUaBuildInType_OpcUaNodeId = 17,
		OpcUaBuildInType_OpcUaExpandedNodeId = 18,
		OpcUaBuildInType_OpcUaStatusCode = 19,
		OpcUaBuildInType_OpcUaQualifiedName = 20,
		OpcUaBuildInType_OpcUaLocalizedText = 21,
		OpcUaBuildInType_OpcUaExtensionObject = 22,
		OpcUaBuildInType_OpcUaDataValue = 23,
		OpcUaBuildInType_OpcUaVariant = 24,
		OpcUaBuildInType_OpcUaDiagnosticInfo = 25
	} OpcUaBuildInType;

#endif

}
