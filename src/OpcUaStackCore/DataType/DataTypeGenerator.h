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

#ifndef __OpcUaStackCore_DataTypeGenerator_h__
#define __OpcUaStackCore_DataTypeGenerator_h__

#include <boost/property_tree/ptree.hpp>
#include <vector>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/DataType/DataTypeDefinition.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DataTypeGeneratorIf
	{
	  public:
		DataTypeGeneratorIf(void) {}
		virtual ~DataTypeGeneratorIf(void) {}

		virtual std::string getTypeNameFromNodeId(OpcUaNodeId& typeNodeId) = 0;
	};

	class DLLEXPORT DataTypeGenerator
	{
	  public:
		typedef boost::shared_ptr<DataTypeGenerator> SPtr;

		DataTypeGenerator(void);
		~DataTypeGenerator(void);

		void binaryEncodingNodeId(OpcUaNodeId& binaryEncodingNodeId);
		void xmlEncodingNodeId(OpcUaNodeId& xmlEncodingNodeId);
		void dataTypeGeneratorIf(DataTypeGeneratorIf* dataTypeGeneratorIf);
		void projectNamespace(const std::string& projectName);
		void projectDirectory(const std::string& projectDirectory);
		void dataTypeDefinition(DataTypeDefinition::SPtr& dataTypeDefinition);
		void superTypeDataTypeDefinition(DataTypeDefinition::SPtr& dataTypeDefinition);
		std::string& sourceFileContent(void);
		std::string& headerFileContent(void);

		bool generate(void);

	  private:
		std::string getIdentifier(OpcUaNodeId& nodeId);
		std::string getTypeNameFromNodeId(OpcUaNodeId& typeNodeId);
		bool createVariableName(DataTypeField::SPtr& dataTypeField, std::string& variableName, bool headerFile, bool ext = true);
		bool createVariableType(DataTypeField::SPtr& dataTypeField, std::string& variableType, bool headerFile, bool sptr = true);

		bool isBoolean(OpcUaNodeId& typeNodeId);
		bool isByte(OpcUaNodeId& typeNodeId);
	    bool isNumber(OpcUaNodeId& typeNodeId);
	    bool isObject(OpcUaNodeId& typeNodeId);

		DataTypeGeneratorIf* dataTypeGeneratorIf_;

		//
		// header functions
		//
		bool generateHeader(void);
		bool generateHeaderComments(void);
		bool generateHeaderBegin(void);
		bool generateHeaderEnd(void);
		bool generateHeaderClassBegin(const std::string& prefix);
		bool generateHeaderClassEnd(const std::string& prefix);
		bool generateHeaderClassExtensionInterface(const std::string& prefix);
		bool generateHeaderClassPublic(const std::string& prefix);
		bool generateHeaderClassPrivate(const std::string& prefix);
		bool generateHeaderClassValueGetter(const std::string& prefix);
		bool generateHeaderClassValueDefinition(const std::string& prefix);

		//
		// source functions
		//
		bool generateSource(void);
		bool generateSourceComments(void);
		bool generateSourceIncludes(void);
		bool generateSourceClassBegin(void);
		bool generateSourceClassEnd(void);
		bool generateSourceClassConstructor(const std::string& prefix);
		bool generateSourceClassDestructor(const std::string& prefix);
		bool generateSourceClassGetter(const std::string& prefix);
		bool generateSourceClassPublicEQ(const std::string& prefix);
		bool generateSourceClassPublicCP(const std::string& prefix);
		bool generateSourceClassExtensionObjectBase(const std::string& prefix);
		bool generateSourceClassFactory(const std::string& prefix);
		bool generateSourceClassBinaryTypeId(const std::string& prefix);
		bool generateSourceClassXmlTypeId(const std::string& prefix);
		bool generateSourceClassBinaryEncode(const std::string& prefix);
		bool generateSourceClassBinaryDecode(const std::string& prefix);
		bool generateSourceClassXmlEncode(const std::string& prefix);
		bool generateSourceClassXmlDecode(const std::string& prefix);
		bool generateSourceClassCopyTo(const std::string& prefix);
		bool generateSourceClassEqual(const std::string& prefix);
		bool generateSourceClassOut(const std::string& prefix);

		OpcUaNodeId binaryEncodingNodeId_;
		OpcUaNodeId xmlEncodingNodeId_;
		std::string projectNamespace_;
		std::string projectDirectory_;
		DataTypeDefinition::SPtr dataTypeDefinition_;
		DataTypeDefinition::SPtr superTypeDataTypeDefinition_;
		std::string sourceContent_;
		std::string headerContent_;
	};


}

#endif
