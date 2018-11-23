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

#include <boost/algorithm/string.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBuildInTypeClass
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaBuildInTypeClass::isBoolean(OpcUaBuildInType buildInType)
	{
		return buildInType == OpcUaBuildInType_OpcUaBoolean;
	}

	bool
	OpcUaBuildInTypeClass::isByte(OpcUaBuildInType buildInType)
	{
		return buildInType == OpcUaBuildInType_OpcUaSByte ||
			   buildInType == OpcUaBuildInType_OpcUaByte;
	}

	bool
	OpcUaBuildInTypeClass::isNumber(OpcUaBuildInType buildInType)
	{
		return buildInType == OpcUaBuildInType_OpcUaInt16 ||
			   buildInType == OpcUaBuildInType_OpcUaUInt16 ||
			   buildInType == OpcUaBuildInType_OpcUaInt32 ||
			   buildInType == OpcUaBuildInType_OpcUaUInt32 ||
			   buildInType == OpcUaBuildInType_OpcUaInt64 ||
			   buildInType == OpcUaBuildInType_OpcUaUInt64 ||
			   buildInType == OpcUaBuildInType_OpcUaFloat ||
			   buildInType == OpcUaBuildInType_OpcUaDouble ||
			   buildInType == OpcUaBuildInType_OpcUaIntegerId ||
			   buildInType == OpcUaBuildInType_OpcUaVersionTime ||
			   buildInType == OpcUaBuildInType_OpcUaDataSetFieldContentMask ||
			   buildInType == OpcUaBuildInType_OpcUaDuration ||
			   buildInType == OpcUaBuildInType_OpcUaDataSetFieldFlag ||
			   buildInType == OpcUaBuildInType_OpcUaJsonNetworkMessageContentMask ||
			   buildInType == OpcUaBuildInType_OpcUaUadpNetworkMessageContentMask ||
			   buildInType == OpcUaBuildInType_OpcUaJsonDataSetMessageContentMask ||
			   buildInType == OpcUaBuildInType_OpcUaUadpDataSetMessageContentMask ||
			   buildInType == OpcUaBuildInType_OpcUaPermissionType ||
			   buildInType == OpcUaBuildInType_OpcUaCounter;
	}

	bool
	OpcUaBuildInTypeClass::isObject(OpcUaBuildInType buildInType)
	{
		return !isBoolean(buildInType) && !isByte(buildInType) && !isNumber(buildInType);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBuildInTypeMap
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	std::string
	OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType buildInType)
	{
		switch (buildInType)
		{
			case OpcUaBuildInType_Unknown: return "Unknown";
			case OpcUaBuildInType_OpcUaBoolean: return "Boolean";
			case OpcUaBuildInType_OpcUaSByte: return "SByte";
			case OpcUaBuildInType_OpcUaByte: return "Byte";
			case OpcUaBuildInType_OpcUaInt16: return "Int16";
			case OpcUaBuildInType_OpcUaUInt16: return "UInt16";
			case OpcUaBuildInType_OpcUaDataSetFieldFlag: return "DataSetFieldFlag";
			case OpcUaBuildInType_OpcUaInt32: return "Int32";
			case OpcUaBuildInType_OpcUaUInt32: return "UInt32";
			case OpcUaBuildInType_OpcUaCounter: return "Counter";
			case OpcUaBuildInType_OpcUaVersionTime: return "VersionTime";
			case OpcUaBuildInType_OpcUaIntegerId: return "IntegerId";
			case OpcUaBuildInType_OpcUaDataSetFieldContentMask: return "DataSetFieldContentMask";
			case OpcUaBuildInType_OpcUaJsonNetworkMessageContentMask: return "JsonNetworkMessageContentMask";
			case OpcUaBuildInType_OpcUaUadpNetworkMessageContentMask: return "UadpNetworkMessageContentMask";
			case OpcUaBuildInType_OpcUaJsonDataSetMessageContentMask: return "JsonDataSetMessageContentMask";
			case OpcUaBuildInType_OpcUaUadpDataSetMessageContentMask: return "UadpDataSetMessageContentMask";
			case OpcUaBuildInType_OpcUaPermissionType: return "PermissionType";
			case OpcUaBuildInType_OpcUaInt64: return "Int64";
			case OpcUaBuildInType_OpcUaUInt64: return "UInt64";
			case OpcUaBuildInType_OpcUaFloat: return "Float";
			case OpcUaBuildInType_OpcUaDouble: return "Double";
			case OpcUaBuildInType_OpcUaDuration: return "Duration";
			case OpcUaBuildInType_OpcUaString: return "String";
			case OpcUaBuildInType_OpcUaLocaleId: return "LocaleId";
			case OpcUaBuildInType_OpcUaNumericRange: return "NumericRange";
			case OpcUaBuildInType_OpcUaDateTime: return "DateTime";
			case OpcUaBuildInType_OpcUaUtcTime: return "UtcTime";
			case OpcUaBuildInType_OpcUaGuid: return "Guid";
			case OpcUaBuildInType_OpcUaByteString: return "ByteString";
			case OpcUaBuildInType_OpcUaApplicationInstanceCertificate: return "ApplicationInstanceCertificate";
			case OpcUaBuildInType_OpcUaXmlElement: return "XmlElement";
			case OpcUaBuildInType_OpcUaNodeId: return "NodeId";
			case OpcUaBuildInType_OpcUaExpandedNodeId: return "ExpandedNodeId";
			case OpcUaBuildInType_OpcUaStatusCode: return "Status";
			case OpcUaBuildInType_OpcUaQualifiedName: return "QualifiedName";
			case OpcUaBuildInType_OpcUaLocalizedText: return "LocalizedText";
			case OpcUaBuildInType_OpcUaExtensionObject: return "ExtensionObject";
			case OpcUaBuildInType_OpcUaDataValue: return "DataValue";
			case OpcUaBuildInType_OpcUaVariant: return "Variant";
			case OpcUaBuildInType_OpcUaDiagnosticInfo: return "DiagnosticInfo";
			default: return "Unknown";
		}
	}

	OpcUaBuildInType
	OpcUaBuildInTypeMap::string2BuildInType(const std::string& typeString)
	{
		std::string type = typeString;
		boost::to_upper(type);

		if (type == "UNKNOWN") return OpcUaBuildInType_Unknown;
		else if (type == "BOOLEAN") return OpcUaBuildInType_OpcUaBoolean;
		else if (type == "SBYTE") return OpcUaBuildInType_OpcUaSByte;
		else if (type == "BYTE") return OpcUaBuildInType_OpcUaByte;
		else if (type == "INT16") return OpcUaBuildInType_OpcUaInt16;
		else if (type == "UINT16") return OpcUaBuildInType_OpcUaUInt16;
		else if (type == "DATASETFIELDFLAG") return OpcUaBuildInType_OpcUaDataSetFieldFlag;
		else if (type == "INT32") return OpcUaBuildInType_OpcUaInt32;
		else if (type == "UINT32") return OpcUaBuildInType_OpcUaUInt32;
		else if (type == "VERSIONTIME") return OpcUaBuildInType_OpcUaVersionTime;
		else if (type == "COUNTER") return OpcUaBuildInType_OpcUaCounter;
		else if (type == "INTEGERID") return OpcUaBuildInType_OpcUaIntegerId;
		else if (type == "DATASETFIELDCONTENTMASK") return OpcUaBuildInType_OpcUaDataSetFieldContentMask;
		else if (type == "JSONNETWORKMESSAGECONTENTMASK") return OpcUaBuildInType_OpcUaJsonNetworkMessageContentMask;
		else if (type == "UADPNETWORKMESSAGECONTENTMASK") return OpcUaBuildInType_OpcUaUadpNetworkMessageContentMask;
		else if (type == "JSONDATASETMESSAGECONTENTMASK") return OpcUaBuildInType_OpcUaJsonDataSetMessageContentMask;
		else if (type == "UADPDATASETMESSAGECONTENTMASK") return OpcUaBuildInType_OpcUaUadpDataSetMessageContentMask;
		else if (type == "PERMISSIONTYPE") return OpcUaBuildInType_OpcUaPermissionType;
		else if (type == "INT64") return OpcUaBuildInType_OpcUaInt64;
		else if (type == "UINT64") return OpcUaBuildInType_OpcUaUInt64;
		else if (type == "FLOAT") return OpcUaBuildInType_OpcUaFloat;
		else if (type == "DOUBLE") return OpcUaBuildInType_OpcUaDouble;
		else if (type == "DURATION") return OpcUaBuildInType_OpcUaDuration;
		else if (type == "STRING") return OpcUaBuildInType_OpcUaString;
		else if (type == "LOCALEID") return OpcUaBuildInType_OpcUaLocaleId;
		else if (type == "NUMERICRANGE") return OpcUaBuildInType_OpcUaNumericRange;
		else if (type == "DATETIME") return OpcUaBuildInType_OpcUaDateTime;
		else if (type == "UTCTIME") return OpcUaBuildInType_OpcUaUtcTime;
		else if (type == "GUID") return OpcUaBuildInType_OpcUaGuid;
		else if (type == "BYTESTRING") return OpcUaBuildInType_OpcUaByteString;
		else if (type == "APPLICATIONINSTANCECERTIFICATE") return OpcUaBuildInType_OpcUaApplicationInstanceCertificate;
		else if (type == "XMLELEMENT") return OpcUaBuildInType_OpcUaXmlElement;
		else if (type == "NODEID") return OpcUaBuildInType_OpcUaNodeId;
		else if (type == "EXPANDEDNODEID") return OpcUaBuildInType_OpcUaExpandedNodeId;
		else if (type == "STATUS") return OpcUaBuildInType_OpcUaStatusCode;
		else if (type == "QUALIFIEDNAME") return OpcUaBuildInType_OpcUaQualifiedName;
		else if (type == "LOCALIZEDTEXT") return OpcUaBuildInType_OpcUaLocalizedText;
		else if (type == "EXTENSIONOBJECT") return OpcUaBuildInType_OpcUaExtensionObject;
		else if (type == "DATAVALUE") return OpcUaBuildInType_OpcUaDataValue;
		else if (type == "VARIANT") return OpcUaBuildInType_OpcUaVariant;
		else if (type == "DIAGNOSTICINFO") return OpcUaBuildInType_OpcUaDiagnosticInfo;
		else return OpcUaBuildInType_Unknown;
	}

	std::string
	OpcUaBuildInTypeMap::buildInType2CPPType(OpcUaBuildInType buildInType)
	{
		switch (buildInType)
		{
			case OpcUaBuildInType_Unknown: return "Unknown";
			case OpcUaBuildInType_OpcUaBoolean: return "OpcUaBoolean";
			case OpcUaBuildInType_OpcUaSByte: return "OpcUaSByte";
			case OpcUaBuildInType_OpcUaByte: return "OpcUaByte";
			case OpcUaBuildInType_OpcUaInt16: return "OpcUaInt16";
			case OpcUaBuildInType_OpcUaUInt16: return "OpcUaUInt16";
			case OpcUaBuildInType_OpcUaDataSetFieldFlag: return "OpcUaDataSetFieldFlag";
			case OpcUaBuildInType_OpcUaInt32: return "OpcUaInt32";
			case OpcUaBuildInType_OpcUaUInt32: return "OpcUaUInt32";
			case OpcUaBuildInType_OpcUaCounter: return "OpcUaCounter";
			case OpcUaBuildInType_OpcUaVersionTime: return "OpcUaVersionTime";
			case OpcUaBuildInType_OpcUaIntegerId: return "OpcUaIntegerId";
			case OpcUaBuildInType_OpcUaDataSetFieldContentMask: return "DataSetFieldContentMask";
			case OpcUaBuildInType_OpcUaJsonNetworkMessageContentMask: return "OpcUaJsonNetworkMessageContentMask";
			case OpcUaBuildInType_OpcUaUadpNetworkMessageContentMask: return "OpcUaUadpNetworkMessageContentMask";
			case OpcUaBuildInType_OpcUaJsonDataSetMessageContentMask: return "OpcUaJsonDataSetMessageContentMask";
			case OpcUaBuildInType_OpcUaUadpDataSetMessageContentMask: return "OpcUaUadpDataSetMessageContentMask";
			case OpcUaBuildInType_OpcUaPermissionType: return "OpcUaPermissionType";
			case OpcUaBuildInType_OpcUaInt64: return "OpcUaInt64";
			case OpcUaBuildInType_OpcUaUInt64: return "OpcUaUInt64";
			case OpcUaBuildInType_OpcUaFloat: return "OpcUaFloat";
			case OpcUaBuildInType_OpcUaDouble: return "OpcUaDouble";
			case OpcUaBuildInType_OpcUaDuration: return "OpcUaDuration";
			case OpcUaBuildInType_OpcUaString: return "OpcUaString";
			case OpcUaBuildInType_OpcUaLocaleId: return "OpcUaLocaleId";
			case OpcUaBuildInType_OpcUaNumericRange: return "OpcUaNumericRange";
			case OpcUaBuildInType_OpcUaApplicationInstanceCertificate: return "OpcUaApplicationInstanceCertificate";
			case OpcUaBuildInType_OpcUaDateTime: return "OpcUaDateTime";
			case OpcUaBuildInType_OpcUaUtcTime: return "OpcUaUtcTime";
			case OpcUaBuildInType_OpcUaGuid: return "OpcUaGuid";
			case OpcUaBuildInType_OpcUaByteString: return "OpcUaByteString";
			case OpcUaBuildInType_OpcUaXmlElement: return "OpcUaXmlElement";
			case OpcUaBuildInType_OpcUaNodeId: return "OpcUaNodeId";
			case OpcUaBuildInType_OpcUaExpandedNodeId: return "OpcUaExpandedNodeId";
			case OpcUaBuildInType_OpcUaStatusCode: return "OpcUaStatus";
			case OpcUaBuildInType_OpcUaQualifiedName: return "OpcUaQualifiedName";
			case OpcUaBuildInType_OpcUaLocalizedText: return "OpcUaLocalizedText";
			case OpcUaBuildInType_OpcUaExtensionObject: return "OpcUaExtensionObject";
			case OpcUaBuildInType_OpcUaDataValue: return "OpcUaDataValue";
			case OpcUaBuildInType_OpcUaVariant: return "OpcUaVariant";
			case OpcUaBuildInType_OpcUaDiagnosticInfo: return "OpcUaDiagnosticInfo";
			default: return "Unknown";
		}
	}

}
