/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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

	OpcUaTypeConversion::OpcUaTypeConversion(void)
	{
	}

	OpcUaTypeConversion::~OpcUaTypeConversion(void)
	{
	}


	uint8_t
	OpcUaTypeConversion::precedenceRank(OpcUaBuildInType type)
	{
		switch (type)
		{
		case OpcUaBuildInType_OpcUaDouble: 			return 0;
		case OpcUaBuildInType_OpcUaFloat:           return 1;
		case OpcUaBuildInType_OpcUaInt64:           return 2;
		case OpcUaBuildInType_OpcUaUInt64:          return 3;
		case OpcUaBuildInType_OpcUaInt32:           return 4;
		case OpcUaBuildInType_OpcUaUInt32:          return 5;
		case OpcUaBuildInType_OpcUaStatusCode:      return 6;
		case OpcUaBuildInType_OpcUaInt16:           return 7;
		case OpcUaBuildInType_OpcUaUInt16:          return 8;
		case OpcUaBuildInType_OpcUaSByte:           return 9;
		case OpcUaBuildInType_OpcUaByte:            return 10;
		case OpcUaBuildInType_OpcUaBoolean:         return 11;
		case OpcUaBuildInType_OpcUaGuid:            return 12;
		case OpcUaBuildInType_OpcUaString:          return 13;
		case OpcUaBuildInType_OpcUaExpandedNodeId:  return 14;
		case OpcUaBuildInType_OpcUaNodeId:          return 15;
		case OpcUaBuildInType_OpcUaLocalizedText:   return 16;
		case OpcUaBuildInType_OpcUaQualifiedName:   return 17;
		case OpcUaBuildInType_OpcUaByteString:   	return 18;
		case OpcUaBuildInType_OpcUaDateTime:   		return 19;
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

	bool
	OpcUaTypeConversion::conversion(
		OpcUaVariant& sourceVariant,		// source variant data
		OpcUaBuildInType targetType,			// target type
		OpcUaVariant& targetVariant 		// target variant data
	)
	{
		auto sourceType = sourceVariant.variantType();

		switch (conversionType(sourceType, targetType))
		{
		case '-':
		{
			if (&sourceVariant != &targetVariant) {
				targetVariant.copyFrom(sourceVariant);
			}

			return true;
		}
		case 'I':
		case 'E':
		{
			return cast(sourceVariant, targetType, targetVariant);
		}

		case 'X':
			return false;
		}

		return false;
	}

	bool
	OpcUaTypeConversion::cast(
		OpcUaVariant& sourceVariant,
		OpcUaBuildInType targetType,
		OpcUaVariant& targetVariant
	)
	{
		if (sourceVariant.isArray()) {
			Log(LogLevel::Warning, "array conversion is not supported");
			return false;
		}

		switch (sourceVariant.variantType())
		{
		case OpcUaBuildInType_OpcUaBoolean:
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaByte:	return cast<OpcUaBoolean, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaBoolean, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaBoolean, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return cast<OpcUaBoolean, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaBoolean, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaBoolean, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return cast<OpcUaBoolean, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.get<OpcUaBoolean>() ? "1" : "0");
				targetVariant.setValue(value);

				return true;
			}
			case OpcUaBuildInType_OpcUaUInt16:	return cast<OpcUaBoolean, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return cast<OpcUaBoolean, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaBoolean, OpcUaUInt64>(sourceVariant, targetVariant);
			default: 							return false;
			}
		case OpcUaBuildInType_OpcUaByte:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaByte, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaByte, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaByte, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return cast<OpcUaByte, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaByte, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaByte, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaByte, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(
						boost::lexical_cast<std::string>((int)sourceVariant.get<OpcUaByte>()));
				targetVariant.setValue(value);

				return true;
			}
			case OpcUaBuildInType_OpcUaUInt16:	return cast<OpcUaByte, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return cast<OpcUaByte, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaByte, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaByteString:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaGuid:
			{
				std::string hexString = sourceVariant.getSPtr<OpcUaByteString>()->toHexString();

				hexString.insert(8, "-");
				hexString.insert(13, "-");
				hexString.insert(18, "-");
				hexString.insert(23, "-");

				OpcUaGuid::SPtr guid = boost::make_shared<OpcUaGuid>();

				if (guid->value(hexString)) {
					targetVariant.variant(guid);
					return true;
				}

				return false;
			}
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaDateTime:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.get<OpcUaDateTime>().toISOString());
				targetVariant.setValue(value);

				return true;
			}
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaDouble:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaDouble, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castRealToInteger<OpcUaDouble, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaDouble, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castRealToInteger<OpcUaDouble, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return castRealToInteger<OpcUaDouble, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return castRealToInteger<OpcUaDouble, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castRealToInteger<OpcUaDouble, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castRealToInteger<OpcUaDouble, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castRealToInteger<OpcUaDouble, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return castRealToInteger<OpcUaDouble, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaExpandedNodeId:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaNodeId:
			{

				OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
				((OpcUaNodeIdBase*)sourceVariant.getSPtr<OpcUaExpandedNodeId>().get())->copyTo((OpcUaNodeId&)*nodeId);

				targetVariant.variant(nodeId);
				return true;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.getSPtr<OpcUaExpandedNodeId>()->toString());
				targetVariant.setValue(value);
				return true;
			}
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaFloat:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaFloat, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castRealToInteger<OpcUaFloat, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaFloat, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castRealToInteger<OpcUaFloat, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return castRealToInteger<OpcUaFloat, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return castRealToInteger<OpcUaFloat, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castRealToInteger<OpcUaFloat, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castRealToInteger<OpcUaFloat, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castRealToInteger<OpcUaFloat, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return castRealToInteger<OpcUaFloat, OpcUaUInt64>(sourceVariant, targetVariant);
			default: 							return false;
			}
		}

		case OpcUaBuildInType_OpcUaGuid:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaByteString:
			{
				std::string guidString =  sourceVariant.getSPtr<OpcUaGuid>()->value();
				boost::replace_all(guidString, "-", "");

				OpcUaByteString::SPtr byteString = boost::make_shared<OpcUaByteString>();
				byteString->fromHexString(guidString);

				targetVariant.variant(byteString);
				return true;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.getSPtr<OpcUaGuid>()->value());
				targetVariant.setValue(value);
				return true;
			}
				default: 						return false;
			}
		}
		case OpcUaBuildInType_OpcUaInt16:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaInt16, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaInt16, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaInt16, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaInt16, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaInt16, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaInt16, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaInt16, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castIntegerToInteger<OpcUaInt16, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return cast<OpcUaInt16, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaInt16, OpcUaUInt64>(sourceVariant, targetVariant);
				default: 						return false;
			}
		}
		case OpcUaBuildInType_OpcUaInt32:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaInt32, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaInt32, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaInt32, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaInt32, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castIntegerToInteger<OpcUaInt32, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaInt32, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaInt32, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaStatusCode: return castStatusCode<OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castIntegerToInteger<OpcUaInt32, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castIntegerToInteger<OpcUaInt32, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaInt32, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}

		case OpcUaBuildInType_OpcUaInt64:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaInt64, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaInt64, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaInt64, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaInt64, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castIntegerToInteger<OpcUaInt64, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return castIntegerToInteger<OpcUaInt64, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaInt64, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaStatusCode: return castStatusCode<OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castIntegerToInteger<OpcUaInt64, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castIntegerToInteger<OpcUaInt64, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return castIntegerToInteger<OpcUaInt64, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaNodeId:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaExpandedNodeId::SPtr expandedNodeId = boost::make_shared<OpcUaExpandedNodeId>();
				expandedNodeId->copyFrom(*sourceVariant.getSPtr<OpcUaNodeId>());
				targetVariant.variant(expandedNodeId);
				return true;

			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.getSPtr<OpcUaNodeId>()->toString());
				targetVariant.setValue(value);
				return true;
			}
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaSByte:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaSByte, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaSByte, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaSByte, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaSByte, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return cast<OpcUaSByte, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaSByte, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaSByte, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(boost::lexical_cast<std::string>((int)sourceVariant.get<OpcUaSByte>()));
				targetVariant.setValue(value);

				return true;
			}
			case OpcUaBuildInType_OpcUaUInt16:	return castIntegerToInteger<OpcUaSByte, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castIntegerToInteger<OpcUaSByte, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return castIntegerToInteger<OpcUaSByte, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaStatusCode:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaStatusCode, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaStatusCode, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 value = (0xFFFF0000 & sourceVariant.get<OpcUaStatusCode>()) >> 16;
				targetVariant.variant(value);

				return true;
			}
			case OpcUaBuildInType_OpcUaUInt32:	return cast<OpcUaStatusCode, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaStatusCode, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaString:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				std::string value = sourceVariant.getSPtr<OpcUaString>()->toStdString();
				if (value == "0" || value == "false") {
					targetVariant.set<OpcUaBoolean>(false);
					return true;
				}

				if (value == "1" || value == "true") {
					targetVariant.set<OpcUaBoolean>(true);
					return true;
				}


				return false;
			}
			case OpcUaBuildInType_OpcUaByte:	return castStringToInteger<OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime value;
				if (value.fromISOString(sourceVariant.getSPtr<OpcUaString>()->toStdString())) {
					targetVariant.variant(value);
					return true;
				}

				return false;
			}
			case OpcUaBuildInType_OpcUaDouble: 	return castStringToReal<OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaExpandedNodeId::SPtr value = boost::make_shared<OpcUaExpandedNodeId>();
				if (value->fromString(sourceVariant.getSPtr<OpcUaString>()->toStdString())) {
					targetVariant.variant(value);
					return true;
				}

				return false;

			}
			case OpcUaBuildInType_OpcUaFloat: 	return castStringToReal<OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr value = boost::make_shared<OpcUaGuid>();
				if (value->value(sourceVariant.getSPtr<OpcUaString>()->toStdString())) {
					targetVariant.variant(value);
					return true;
				}

				return false;

			}
			case OpcUaBuildInType_OpcUaInt16:	return castStringToInteger<OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return castStringToInteger<OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return castStringToInteger<OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaNodeId::SPtr value = boost::make_shared<OpcUaNodeId>();
				if (value->fromString(sourceVariant.getSPtr<OpcUaString>()->toStdString())) {
					targetVariant.variant(value);
					return true;
				}

				return false;

			}
			case OpcUaBuildInType_OpcUaSByte:	return castStringToInteger<OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaLocalizedText::SPtr value = boost::make_shared<OpcUaLocalizedText>();
				if (value->fromString(sourceVariant.getSPtr<OpcUaString>()->toStdString())) {
					targetVariant.variant(value);
					return true;
				}

				return false;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaQualifiedName::SPtr value = boost::make_shared<OpcUaQualifiedName>();
				if (value->fromString(sourceVariant.getSPtr<OpcUaString>()->toStdString())) {
					targetVariant.variant(value);
					return true;
				}

				return false;
			}
			case OpcUaBuildInType_OpcUaUInt16:	return castStringToInteger<OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castStringToInteger<OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return castStringToInteger<OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaLocalizedText:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.getSPtr<OpcUaLocalizedText>()->text());
				targetVariant.setValue(value);
				return true;
			}
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaQualifiedName:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString value(sourceVariant.getSPtr<OpcUaQualifiedName>()->toString());
				targetVariant.setValue(value);
				return true;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaLocalizedText::SPtr value = boost::make_shared<OpcUaLocalizedText>("", sourceVariant.getSPtr<OpcUaQualifiedName>()->toString());
				targetVariant.variant(value);
				return true;
			}
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaUInt16:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaUInt16, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaUInt16, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaUInt16, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaUInt16, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castIntegerToInteger<OpcUaUInt16, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return cast<OpcUaUInt16, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaUInt16, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaUInt16, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaVariant tmpVariant;
				tmpVariant.variant(static_cast<OpcUaUInt64>(sourceVariant.get<OpcUaUInt16>() << 16));

				return castStatusCode<OpcUaUInt64>(tmpVariant, targetVariant);
			}
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return cast<OpcUaUInt16, OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaUInt16, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaUInt32:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaUInt32, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaUInt32, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaUInt32, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaUInt32, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castIntegerToInteger<OpcUaUInt32, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return castIntegerToInteger<OpcUaUInt32, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return cast<OpcUaUInt32, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaUInt32, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaStatusCode: return castStatusCode<OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaUInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castIntegerToInteger<OpcUaUInt32, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt64:	return cast<OpcUaUInt32, OpcUaUInt64>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		case OpcUaBuildInType_OpcUaUInt64:
		{
			switch (targetType)
			{
			case OpcUaBuildInType_OpcUaBoolean:	return cast<OpcUaUInt64, OpcUaBoolean>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaByte:	return castIntegerToInteger<OpcUaUInt64, OpcUaByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaDouble:	return cast<OpcUaUInt64, OpcUaDouble>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaFloat:	return cast<OpcUaUInt64, OpcUaFloat>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt16:	return castIntegerToInteger<OpcUaUInt64, OpcUaInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt32:	return castIntegerToInteger<OpcUaUInt64, OpcUaInt32>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaInt64:	return castIntegerToInteger<OpcUaUInt64, OpcUaInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaSByte:	return castIntegerToInteger<OpcUaUInt64, OpcUaSByte>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaStatusCode: return castStatusCode<OpcUaUInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaString:  return castToString<OpcUaUInt64>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt16:	return castIntegerToInteger<OpcUaUInt64, OpcUaUInt16>(sourceVariant, targetVariant);
			case OpcUaBuildInType_OpcUaUInt32:	return castIntegerToInteger<OpcUaUInt64, OpcUaUInt32>(sourceVariant, targetVariant);
			default:							return false;
			}
		}
		default:	return false;
		}


	}

	char
	OpcUaTypeConversion::conversationTypeTable[TYPE_CONVERSATION_TABLE_SIZE][TYPE_CONVERSATION_TABLE_SIZE] =
	{
			{'-', 'I', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', 'I', 'X', 'E', 'X', 'X', 'I', 'I', 'I', 'X'}, //bool
			{'E', '-', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', 'I', 'X', 'E', 'X', 'X', 'I', 'I', 'I', 'X'}, //byte
			{'X', 'X', '-', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}, //byte string
			{'X', 'X', 'X', '-', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X'}, //datetime
			{'E', 'E', 'X', 'X', '-', 'X', 'E', 'X', 'E', 'E', 'E', 'X', 'E', 'X', 'E', 'X', 'X', 'E', 'E', 'E', 'X'}, //double
			{'X', 'X', 'X', 'X', 'X', '-', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'I', 'X', 'X', 'X', 'X', 'X', 'X'}, //expNodeId
			{'E', 'E', 'X', 'X', 'I', 'X', '-', 'X', 'E', 'E', 'E', 'X', 'E', 'X', 'E', 'X', 'X', 'E', 'E', 'E', 'X'}, //float
			{'X', 'X', 'E', 'X', 'X', 'X', 'X', '-', 'X', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X'}, //guid
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', '-', 'I', 'I', 'X', 'E', 'X', 'E', 'X', 'X', 'E', 'I', 'I', 'X'}, //int16
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', '-', 'I', 'X', 'E', 'E', 'E', 'X', 'X', 'E', 'E', 'I', 'X'}, //int32
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', 'E', '-', 'X', 'E', 'E', 'E', 'X', 'X', 'E', 'E', 'E', 'X'}, //int64
			{'X', 'X', 'X', 'X', 'X', 'I', 'X', 'X', 'X', 'X', 'X', '-', 'X', 'X', 'I', 'X', 'X', 'X', 'X', 'X', 'X'}, //nodeId
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', '-', 'X', 'E', 'X', 'X', 'I', 'I', 'I', 'X'}, //sbyte
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'I', 'I', 'X', 'X', '-', 'X', 'X', 'X', 'E', 'I', 'I', 'X'}, //statusCode
			{'I', 'I', 'X', 'E', 'I', 'E', 'I', 'I', 'I', 'I', 'I', 'E', 'I', 'X', '-', 'E', 'E', 'I', 'I', 'I', 'X'}, //string
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'I', '-', 'X', 'X', 'X', 'X', 'X'}, //localizedText
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'I', 'I', '-', 'X', 'X', 'X', 'X'}, //qualifiedText
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'I', 'I', 'I', 'X', 'E', 'I', 'E', 'X', 'X', '-', 'I', 'I', 'X'}, //uint16
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', 'I', 'I', 'X', 'E', 'E', 'E', 'X', 'X', 'E', '-', 'I', 'X'}, //uint32
			{'E', 'E', 'X', 'X', 'I', 'X', 'I', 'X', 'E', 'E', 'I', 'X', 'E', 'E', 'E', 'X', 'X', 'E', 'E', '-', 'X'}, //uint64
			{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '-'}, //xmlElemnt
	};

	int8_t
	OpcUaTypeConversion::indexForConversationTable(OpcUaBuildInType type) {
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

}

