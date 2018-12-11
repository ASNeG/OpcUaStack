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

#include <boost/date_time/date_facet.hpp>
#include <locale>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"
#include "OpcUaStackServer/NodeSet/NodeSetValueParser.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// DataTypeElement
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	DataTypeElement::DataTypeElement(void)
	: buildInType_(OpcUaBuildInType_Unknown)
	, isArray_(true)
	{
	}

	DataTypeElement::DataTypeElement(OpcUaBuildInType buildInType, bool isArray)
	: buildInType_(buildInType)
	, isArray_(isArray)
	{
	}

	DataTypeElement::~DataTypeElement(void)
	{
	}

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// NodeSetParser
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	NodeSetValueParser::DataTypeElementMap NodeSetValueParser::dataTypeElementMap_;
	bool NodeSetValueParser::initial_ = false;

	NodeSetValueParser::NodeSetValueParser(void)
	{
		start();
	}

	NodeSetValueParser::~NodeSetValueParser(void)
	{
	}

	void 
	NodeSetValueParser::insertDataTypeElement(const std::string& elementName, const DataTypeElement& dataTypeELement)
	{
		dataTypeElementMap_.insert(std::make_pair(elementName, dataTypeELement));
	}

	bool 
	NodeSetValueParser::findDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeElement)
	{
		DataTypeElementMap::iterator it;
		it = dataTypeElementMap_.find(elementName);  
		if (it == dataTypeElementMap_.end()) return false;
		dataTypeElement = it->second;
		return true;
	}

	void
	NodeSetValueParser::start(void)
	{
		if (initial_) return;
		initial_ = true;

		// decode elements
		insertDataTypeElement("Boolean", DataTypeElement(OpcUaBuildInType_OpcUaBoolean, false));
		insertDataTypeElement("ListOfBoolean", DataTypeElement(OpcUaBuildInType_OpcUaBoolean, true));
		insertDataTypeElement("SByte", DataTypeElement(OpcUaBuildInType_OpcUaSByte, false));
		insertDataTypeElement("ListOfSByte", DataTypeElement(OpcUaBuildInType_OpcUaSByte, true));
		insertDataTypeElement("Byte", DataTypeElement(OpcUaBuildInType_OpcUaByte, false));
		insertDataTypeElement("ListOfByte", DataTypeElement(OpcUaBuildInType_OpcUaByte, true));
		insertDataTypeElement("Int16", DataTypeElement(OpcUaBuildInType_OpcUaInt16, false));
		insertDataTypeElement("ListOfInt16", DataTypeElement(OpcUaBuildInType_OpcUaInt16, true));
		insertDataTypeElement("UInt16", DataTypeElement(OpcUaBuildInType_OpcUaUInt16, false));
		insertDataTypeElement("ListOfUInt16", DataTypeElement(OpcUaBuildInType_OpcUaUInt16, true));
		insertDataTypeElement("Int32", DataTypeElement(OpcUaBuildInType_OpcUaInt32, false));
		insertDataTypeElement("ListOfInt32", DataTypeElement(OpcUaBuildInType_OpcUaInt32, true));
		insertDataTypeElement("UInt32", DataTypeElement(OpcUaBuildInType_OpcUaUInt32, false));
		insertDataTypeElement("ListOfUInt32", DataTypeElement(OpcUaBuildInType_OpcUaUInt32, true));
		insertDataTypeElement("Int64", DataTypeElement(OpcUaBuildInType_OpcUaInt64, false));
		insertDataTypeElement("ListOfInt64", DataTypeElement(OpcUaBuildInType_OpcUaInt64, true));
		insertDataTypeElement("UInt64", DataTypeElement(OpcUaBuildInType_OpcUaUInt64, false));
		insertDataTypeElement("ListOfUInt64", DataTypeElement(OpcUaBuildInType_OpcUaUInt64, true));
		insertDataTypeElement("Float", DataTypeElement(OpcUaBuildInType_OpcUaFloat, false));
		insertDataTypeElement("ListOfFloat", DataTypeElement(OpcUaBuildInType_OpcUaFloat, true));
		insertDataTypeElement("Double", DataTypeElement(OpcUaBuildInType_OpcUaDouble, false));
		insertDataTypeElement("ListOfDouble", DataTypeElement(OpcUaBuildInType_OpcUaDouble, true));
		insertDataTypeElement("StatusCode", DataTypeElement(OpcUaBuildInType_OpcUaStatusCode, false));
		insertDataTypeElement("ListOfStatusCode", DataTypeElement(OpcUaBuildInType_OpcUaStatusCode, true));
		insertDataTypeElement("String", DataTypeElement(OpcUaBuildInType_OpcUaString, false));
		insertDataTypeElement("ListOfString", DataTypeElement(OpcUaBuildInType_OpcUaString, true));
		insertDataTypeElement("ByteString", DataTypeElement(OpcUaBuildInType_OpcUaByteString, false));
		insertDataTypeElement("ListOfByteString", DataTypeElement(OpcUaBuildInType_OpcUaByteString, true));
		insertDataTypeElement("LocalizedText", DataTypeElement(OpcUaBuildInType_OpcUaLocalizedText, false));
		insertDataTypeElement("ListOfLocalizedText", DataTypeElement(OpcUaBuildInType_OpcUaLocalizedText, true));
		insertDataTypeElement("DateTime", DataTypeElement(OpcUaBuildInType_OpcUaDateTime, false));
		insertDataTypeElement("ListOfDateTime", DataTypeElement(OpcUaBuildInType_OpcUaDateTime, true));
		insertDataTypeElement("Guid", DataTypeElement(OpcUaBuildInType_OpcUaGuid, false));
		insertDataTypeElement("ListOfGuid", DataTypeElement(OpcUaBuildInType_OpcUaGuid, true));
		insertDataTypeElement("NodeId", DataTypeElement(OpcUaBuildInType_OpcUaNodeId, false));
		insertDataTypeElement("ListOfNodeId", DataTypeElement(OpcUaBuildInType_OpcUaNodeId, true));
		insertDataTypeElement("QualifiedName", DataTypeElement(OpcUaBuildInType_OpcUaQualifiedName, false));
		insertDataTypeElement("ListOfQualifiedName", DataTypeElement(OpcUaBuildInType_OpcUaQualifiedName, true));
		insertDataTypeElement("ExtensionObject", DataTypeElement(OpcUaBuildInType_OpcUaExtensionObject, false));
		insertDataTypeElement("ListOfExtensionObject", DataTypeElement(OpcUaBuildInType_OpcUaExtensionObject, true));
		insertDataTypeElement("DataValue", DataTypeElement(OpcUaBuildInType_OpcUaDataValue, false));
		insertDataTypeElement("ListOfDataValue", DataTypeElement(OpcUaBuildInType_OpcUaDataValue, true));
	}


	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// decode value
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	bool 
	NodeSetValueParser::xmlDecodeValue(
		const std::string& nodeId,
		boost::property_tree::ptree& ptree,
		OpcUaVariant& variant,
		Xmlns& xmlns
	)
	{
		// Test whether the value tag exist. If not exit function
		boost::optional<boost::property_tree::ptree&> ptreeValue = ptree.get_child_optional("Value");
		if (!ptreeValue) return false;
		if (ptreeValue->begin() == ptreeValue->end()) return false;

		// Test whether the data type of the value exist in data type element list. If not exit function
		std::string dataTypeString;
		dataTypeString = xmlns.cutPrefix(ptreeValue->front().first);
		DataTypeElement dataTypeElement;
		if (!findDataTypeElement(dataTypeString, dataTypeElement)) {
			Log(Warning, "data type unknown in node set value parser")
				.parameter("Element", ptreeValue->front().first)
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
			return false;
		}

		// execute decoder function depending on the variable type
		bool rc;
		switch (dataTypeElement.buildInType_)
		{
			case OpcUaBuildInType_OpcUaBoolean:
				rc = xmlDecode<OpcUaBoolean>(dataTypeElement, *ptreeValue, variant, "Boolean", xmlns);
				break;
			case OpcUaBuildInType_OpcUaSByte:
				rc = xmlDecode<OpcUaSByte>(dataTypeElement, *ptreeValue, variant, "SByte", xmlns);
				break;
			case OpcUaBuildInType_OpcUaByte:
				rc = xmlDecode<OpcUaByte>(dataTypeElement, *ptreeValue, variant, "Byte", xmlns);
				break;
			case OpcUaBuildInType_OpcUaUInt16:
				rc = xmlDecode<OpcUaUInt16>(dataTypeElement, *ptreeValue, variant, "UInt16", xmlns);
				break;
			case OpcUaBuildInType_OpcUaInt16:
				rc = xmlDecode<OpcUaInt16>(dataTypeElement, *ptreeValue, variant, "Int16", xmlns);
				break;
			case OpcUaBuildInType_OpcUaUInt32:
				rc = xmlDecode<OpcUaUInt32>(dataTypeElement, *ptreeValue, variant, "UInt32", xmlns);
				break;
			case OpcUaBuildInType_OpcUaInt32:
				rc = xmlDecode<OpcUaInt32>(dataTypeElement, *ptreeValue, variant, "Int32", xmlns);
				break;
			case OpcUaBuildInType_OpcUaUInt64:
				rc = xmlDecode<OpcUaUInt64>(dataTypeElement, *ptreeValue, variant, "UInt64", xmlns);
				break;
			case OpcUaBuildInType_OpcUaInt64:
				rc = xmlDecode<OpcUaInt64>(dataTypeElement, *ptreeValue, variant, "Int64", xmlns);
				break;
			case OpcUaBuildInType_OpcUaFloat:
				rc = xmlDecode<OpcUaFloat>(dataTypeElement, *ptreeValue, variant, "Float", xmlns);
				break;
			case OpcUaBuildInType_OpcUaStatusCode:
				rc = xmlDecode<OpcUaStatusCode>(dataTypeElement, *ptreeValue, variant, "StatusCode", xmlns);
				break;
			case OpcUaBuildInType_OpcUaDouble:
				rc = xmlDecode<OpcUaDouble>(dataTypeElement, *ptreeValue, variant, "Double", xmlns);
				break;
			case OpcUaBuildInType_OpcUaDateTime:
				rc = xmlDecode<OpcUaDateTime>(dataTypeElement, *ptreeValue, variant, "DateTime", xmlns);
				break;
			case OpcUaBuildInType_OpcUaString:
				rc = xmlDecodeSPtr<OpcUaString>(dataTypeElement, *ptreeValue, variant, "String", xmlns);
				break;
			case OpcUaBuildInType_OpcUaByteString:
				rc = xmlDecodeSPtr<OpcUaByteString>(dataTypeElement, *ptreeValue, variant, "ByteString", xmlns);
				break;
			case OpcUaBuildInType_OpcUaLocalizedText:
				rc = xmlDecodeSPtr<OpcUaLocalizedText>(dataTypeElement, *ptreeValue, variant, "LocalizedText", xmlns);
				break;
			case OpcUaBuildInType_OpcUaGuid:
				rc = xmlDecodeSPtr<OpcUaGuid>(dataTypeElement, *ptreeValue, variant, "Guid", xmlns);
				break;
			case OpcUaBuildInType_OpcUaNodeId:
				rc = xmlDecodeSPtr<OpcUaNodeId>(dataTypeElement, *ptreeValue, variant, "NodeId", xmlns);
				break;
			case OpcUaBuildInType_OpcUaQualifiedName:
				rc = xmlDecodeSPtr<OpcUaQualifiedName>(dataTypeElement, *ptreeValue, variant, "QualifiedName", xmlns);
				break;
			case OpcUaBuildInType_OpcUaExtensionObject:
				rc = xmlDecodeSPtr<OpcUaExtensionObject>(dataTypeElement, *ptreeValue, variant, "ExtensionObject", xmlns);
				break;
			case OpcUaBuildInType_OpcUaDataValue:
				rc = xmlDecodeSPtr<OpcUaDataValue>(dataTypeElement, *ptreeValue, variant, "DataValue", xmlns);
				break;
			case OpcUaBuildInType_OpcUaDiagnosticInfo:
				rc = xmlDecodeSPtr<OpcUaDiagnosticInfo>(dataTypeElement, *ptreeValue, variant, "DiagnosticInfo", xmlns);
				break;
			default:
			{
				Log(Error, "data type unknown in node set value decoder")
					.parameter("NodeId", nodeId)
					.parameter("DataType", dataTypeString);
				return false;
			}
		}

		if (!rc) {
			Log(Warning, "decode value error")
				.parameter("NodeId", nodeId)
				.parameter("DataType", dataTypeString);
		}

		return rc;
	}

	bool
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaStatusCode& destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		OpcUaStatus status;
		if (!status.xmlDecode(ptree, xmlns)) {
			return false;
		}
		destValue = status.enumeration();
		return true;
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaBoolean& destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return XmlNumber::xmlDecode(ptree, destValue);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaByte& destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return XmlNumber::xmlDecode(ptree, destValue);
	}
		
	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaSByte& destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return XmlNumber::xmlDecode(ptree, destValue);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaDateTime& destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue.xmlDecode(ptree, xmlns);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaString::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue->xmlDecode(ptree, xmlns);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaByteString::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue->xmlDecode(ptree, xmlns);
	}
	
	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaLocalizedText::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue->xmlDecode(ptree, xmlns);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaGuid::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue->xmlDecode(ptree, xmlns);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaNodeId::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue->xmlDecode(ptree, xmlns);
	}

	bool 
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaQualifiedName::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return destValue->xmlDecode(ptree, xmlns);
	}

	bool
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaExtensionObject::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		if (!destValue->xmlDecode(ptree, xmlns)) {
			return false;
		}

		return true;
	}

	bool
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaDataValue::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		if (!destValue->xmlDecode(ptree, xmlns)) {
			return false;
		}

		return true;
	}

	bool
	NodeSetValueParser::xmlDecode(
		boost::property_tree::ptree& ptree,
		OpcUaDiagnosticInfo::SPtr destValue,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		if (!destValue->xmlDecode(ptree, xmlns)) {
			return false;
		}

		return true;
	}

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// encode value
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	bool 
	NodeSetValueParser::xmlEncodeValue(
		const std::string& nodeId,
		boost::property_tree::ptree& ptree,
		OpcUaVariant& opcUaVariant,
		Xmlns& xmlns
	)
	{
		bool rc = false;
		std::string dataTypeString;

		switch (opcUaVariant.variantType())
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				dataTypeString = "Boolean";
				rc = xmlEncode<OpcUaBoolean>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaSByte:
			{
				dataTypeString = "SByte";
				rc = xmlEncode<OpcUaSByte>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				dataTypeString = "Byte";
				rc = xmlEncode<OpcUaByte>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				dataTypeString = "Int16";
				rc = xmlEncode<OpcUaInt16>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				dataTypeString = "UInt16";
				rc = xmlEncode<OpcUaUInt16>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				dataTypeString = "Int32";
				rc = xmlEncode<OpcUaInt32>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				dataTypeString = "UInt32";
				rc = xmlEncode<OpcUaUInt32>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				dataTypeString = "Int64";
				rc = xmlEncode<OpcUaInt64>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				dataTypeString = "UInt64";
				rc = xmlEncode<OpcUaUInt64>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				dataTypeString = "Float";
				rc = xmlEncode<OpcUaFloat>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaStatusCode:
				dataTypeString = "StatusCode";
				rc = xmlEncode<OpcUaStatusCode>(ptree, opcUaVariant, dataTypeString, xmlns);
				break;
				break;
			case OpcUaBuildInType_OpcUaDouble:
			{
				dataTypeString = "Double";
				rc = xmlEncode<OpcUaDouble>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				dataTypeString = "DateTime";
				rc = xmlEncode<OpcUaDateTime>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaString:
			{
				dataTypeString = "String";
				rc = xmlEncodeSPtr<OpcUaString>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				dataTypeString = "Guid";
				rc = xmlEncodeSPtr<OpcUaGuid>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				dataTypeString = "ByteString";
				rc = xmlEncodeSPtr<OpcUaByteString>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				dataTypeString = "NodeId";
				rc = xmlEncodeSPtr<OpcUaNodeId>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				dataTypeString = "QualifiedName";
				rc = xmlEncodeSPtr<OpcUaQualifiedName>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				dataTypeString = "LocalizedText";
				rc = xmlEncodeSPtr<OpcUaLocalizedText>(ptree, opcUaVariant, dataTypeString, xmlns);
				break; 
			}
			case OpcUaBuildInType_OpcUaExtensionObject:
			{
				dataTypeString = "ExtensionObject";
				rc = xmlEncodeSPtr<OpcUaExtensionObject>(ptree, opcUaVariant, dataTypeString, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaDataValue:
			{
				dataTypeString = "DataValue";
				rc = xmlEncodeSPtr<OpcUaDataValue>(ptree, opcUaVariant, dataTypeString, xmlns);
				break;
			}
			case OpcUaBuildInType_OpcUaDiagnosticInfo:
			{
				dataTypeString = "DiagnosticInfo";
				rc = xmlEncodeSPtr<OpcUaDiagnosticInfo>(ptree, opcUaVariant, dataTypeString, xmlns);
				break;
			}
			default:
			{
				std::stringstream ss;
				ss << opcUaVariant.variantType();
				Log(Error, "data type unknown in node set value encoder")
					.parameter("NodeId", nodeId)
					.parameter("DataType", ss.str());
				return false;
			}
		}

		if (!rc) {
			Log(Warning, "encode value error")
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
		}

		return true;
	}

	bool
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaStatusCode& value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		OpcUaStatus status;
		status.enumeration(value);
		if (!status.xmlEncode(ptree, element, xmlns)) {
			return false;
		}
		return true;
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaBoolean& value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return XmlNumber::xmlEncode(ptree, value, xmlns.addPrefix(element));
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaByte& value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return XmlNumber::xmlEncode(ptree, value, xmlns.addPrefix(element));
	}
		
	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaSByte& value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return XmlNumber::xmlEncode(ptree, value, xmlns.addPrefix(element));
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaDateTime& value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value.xmlEncode(ptree, element, xmlns);
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaString::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaByteString::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}
	
	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaLocalizedText::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaGuid::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaNodeId::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool 
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaQualifiedName::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaExtensionObject::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaDataValue::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

	bool
	NodeSetValueParser::xmlEncode(
		boost::property_tree::ptree& ptree,
		OpcUaDiagnosticInfo::SPtr value,
		const std::string& element,
		Xmlns& xmlns
	)
	{
		return value->xmlEncode(ptree, element, xmlns);
	}

}
