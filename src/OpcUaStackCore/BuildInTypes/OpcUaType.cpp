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

#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"

namespace OpcUaStackCore
{

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
			case OpcUaBuildInType_OpcUaInt32: return "Int32";
			case OpcUaBuildInType_OpcUaUInt32: return "UInt32";
			case OpcUaBuildInType_OpcUaInt64: return "Int64";
			case OpcUaBuildInType_OpcUaUInt64: return "UInt64";
			case OpcUaBuildInType_OpcUaFloat: return "Float";
			case OpcUaBuildInType_OpcUaDouble: return "Double";
			case OpcUaBuildInType_OpcUaString: return "String";
			case OpcUaBuildInType_OpcUaDateTime: return "DateTime";
			case OpcUaBuildInType_OpcUaGuid: return "Guid";
			case OpcUaBuildInType_OpcUaByteString: return "ByteString";
			case OpcUaBuildInType_OpcUaXmlElement: return "XmlElement";
			case OpcUaBuildInType_OpcUaNodeId: return "NodeId";
			case OpcUaBuildInType_OpcUaExpandedNodeId: return "ExpandedNodeId";
			case OpcUaBuildInType_OpcUaStatusCode: return "StatusCode";
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
	OpcUaBuildInTypeMap::string2BuildInType(const std::string& type)
	{
		if (type == "Unknown") return OpcUaBuildInType_Unknown;
		else if (type == "Boolean") return OpcUaBuildInType_OpcUaBoolean;
		else if (type == "SByte") return OpcUaBuildInType_OpcUaSByte;
		else if (type == "Byte") return OpcUaBuildInType_OpcUaByte;
		else if (type == "Int16") return OpcUaBuildInType_OpcUaInt16;
		else if (type == "UInt16") return OpcUaBuildInType_OpcUaUInt16;
		else if (type == "Int32") return OpcUaBuildInType_OpcUaInt32;
		else if (type == "UInt32") return OpcUaBuildInType_OpcUaUInt32;
		else if (type == "Int64") return OpcUaBuildInType_OpcUaInt64;
		else if (type == "UInt64") return OpcUaBuildInType_OpcUaUInt64;
		else if (type == "Float") return OpcUaBuildInType_OpcUaFloat;
		else if (type == "Double") return OpcUaBuildInType_OpcUaDouble;
		else if (type == "String") return OpcUaBuildInType_OpcUaString;
		else if (type == "DateTime") return OpcUaBuildInType_OpcUaDateTime;
		else if (type == "Guid") return OpcUaBuildInType_OpcUaGuid;
		else if (type == "ByteString") return OpcUaBuildInType_OpcUaByteString;
		else if (type == "XmlElement") return OpcUaBuildInType_OpcUaXmlElement;
		else if (type == "NodeId") return OpcUaBuildInType_OpcUaNodeId;
		else if (type == "ExpandedNodeId") return OpcUaBuildInType_OpcUaExpandedNodeId;
		else if (type == "StatusCode") return OpcUaBuildInType_OpcUaStatusCode;
		else if (type == "QualifiedName") return OpcUaBuildInType_OpcUaQualifiedName;
		else if (type == "LocalizedText") return OpcUaBuildInType_OpcUaLocalizedText;
		else if (type == "ExtensionObject") return OpcUaBuildInType_OpcUaExtensionObject;
		else if (type == "DataValue") return OpcUaBuildInType_OpcUaDataValue;
		else if (type == "Variant") return OpcUaBuildInType_OpcUaVariant;
		else if (type == "DiagnosticInfo") return OpcUaBuildInType_OpcUaDiagnosticInfo;
		else return OpcUaBuildInType_Unknown;
	}

}
