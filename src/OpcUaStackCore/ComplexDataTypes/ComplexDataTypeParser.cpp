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
		Config::SPtr config;
		success = configXmlManager.registerConfiguration(fileName, config);
		if (!success) {
			Log(Error, "read complex data type configuration file error")
			   .parameter("ConfigFile", fileName);
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

		return true;
	}

}


