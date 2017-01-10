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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComplexDataTypeParser
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ComplexDataTypeParser::ComplexDataTypeParser(void)
	: fileName_("")
	, complexDataTypeMap_()
	{
	}

	ComplexDataTypeParser::~ComplexDataTypeParser(void)
	{
	}

	ComplexDataType::Vec&
	ComplexDataTypeParser::complexDataTypeMap(void)
	{
		return complexDataTypeMap_;
	}

	bool
	ComplexDataTypeParser::parse(const std::string& fileName)
	{
		fileName_ = fileName;

		bool success;

		//
		// read configuration file
		//
        Log(Info, "read complex data type configuration file")
            .parameter("FileName", fileName);
		Config config;
		ConfigXml configXml;
		success = configXml.parse(fileName_, &config);
		if (!success) {
			Log(Error, "read complex data type configuration file error")
			   .parameter("FileName", fileName);
			   return false;
		}

		// read complex data types
		std::vector<Config> configVec;
		config.getChilds("OpcUaComplexDataTypes.ComplexDataType", configVec);
		if (configVec.size() == 0) {
			Log(Error, "parameter missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("FileName", fileName);
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = configVec.begin(); it != configVec.end(); it++) {
			Config& child = *it;
			ComplexDataType::SPtr complexDataType = constructSPtr<ComplexDataType>();

			success = parseComplexDataType(child, complexDataType);
			if (!success) return false;

			complexDataTypeMap_.insert(std::make_pair(complexDataType->name(), complexDataType));
		}

		return true;
	}

	bool
	ComplexDataTypeParser::parseComplexDataType(Config& config, ComplexDataType::SPtr& complexDataType)
	{
		// type name
		std::string typeName;
		if (!config.getConfigParameter("<xmlattr>.TypeName", typeName)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("Attribute", "TypeName")
				.parameter("FileName", fileName_);
			return false;
		}
		complexDataType->name(typeName);

		// type binary node id
		std::string binaryNodeIdStr;
		if (!config.getConfigParameter("<xmlattr>.TypeBinaryNodeId", typeName)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("Attribute", "TypeBinaryNodeId")
				.parameter("FileName", fileName_);
			return false;
		}
		OpcUaNodeId binaryNodeId;
		if (!binaryNodeId.fromString(binaryNodeIdStr)) {
			Log(Error, "attribute value error in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("Attribute", "TypeBinaryNodeId")
				.parameter("Value", binaryNodeIdStr)
				.parameter("FileName", fileName_);
			return false;
		}
		complexDataType->binaryTypeId(binaryNodeId);

		// type xml node id
		OpcUaNodeId xmlNodeId;
		std::string xmlNodeIdStr;
		if (config.getConfigParameter("<xmlattr>.TypeXMlNodeId", typeName)) {
			if (!binaryNodeId.fromString(xmlNodeIdStr)) {
				Log(Error, "attribute value error in complex data type config file")
					.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
					.parameter("Attribute", "TypeBinaryNodeId")
					.parameter("Value", "TypeXMlNodeId")
					.parameter("FileName", fileName_);
				return false;
			}
		}
		complexDataType->xmlTypeId(xmlNodeId);

		return false;
	}


#if 0
		<OpcUaComplexDataTypes>

			<ComplexDataType TypeName="BaseEventType" TypeBinaryNodeId="i=2041" TypeXMlNodeId="">
			    <Variable Name="EventId" 	 Type="ByteString" 		 ModellingRule="M"></Variable>
			    <Variable Name="EventType" 	 Type="NodeId" 			 ModellingRule="M"></Variable>
			    <Variable Name="SourceNode"  Type="NodeId"	 		 ModellingRule="M"></Variable>
			    <Variable Name="SourceName"  Type="String" 			 ModellingRule="M"</Variable>
			    <Variable Name="Time" 		 Type="DateTime" 		 ModellingRule="M"></Variable>
			    <Variable Name="ReceiveTime" Type="DateTime" 		 ModellingRule="M"></Variable>
			    <Variable Name="LocalTime" 	 Type="TimeZoneDataType" ModellingRule="O"></Variable>
			    <Variable Name="Message" 	 Type="LocalizedText" 	 ModellingRule="M"></Variable>
			    <Variable Name="Severity" 	 Type="UInt16" 			 ModellingRule="M"></Variable>
			</ComplexDataType>
#endif

}


