/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EventTypeGenerator_h__
#define __OpcUaStackCore_EventTypeGenerator_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

    class DLLEXPORT VariableElement
	{
	  public:
    	typedef boost::shared_ptr<VariableElement> SPtr;
    	typedef std::vector<VariableElement::SPtr> Vec;

    	VariableElement(void);
    	~VariableElement(void);

    	void log(void);
    	void prefix(const std::string& prefix);
    	std::string prefix(void);
    	void nodeId(const OpcUaStackCore::OpcUaNodeId& nodeId);
    	OpcUaStackCore::OpcUaNodeId& nodeId(void);
    	void browseName(const OpcUaStackCore::OpcUaQualifiedName& browseName);
    	OpcUaStackCore::OpcUaQualifiedName& browseName(void);
    	void fullName(const std::string& fullName);
    	std::string& fullName(void);
    	void globalVariableName(const std::string& globalVariableName);
    	std::string& globalVariableName(void);
    	void localVariableName(const std::string& localVariableName);
    	std::string& localVariableName(void);
    	void functionName(const std::string& functionName);
    	std::string& functionName(void);
    	void dataTypeName(const std::string& dataTypeName);
    	std::string& dataTypeName(void);

	  private:
    	std::string prefix_;
    	OpcUaStackCore::OpcUaNodeId nodeId_;
    	OpcUaStackCore::OpcUaQualifiedName browseName_;
    	std::string fullName_;
    	std::string globalVariableName_;
    	std::string localVariableName_;
    	std::string functionName_;
    	std::string dataTypeName_;
	};

	class DLLEXPORT EventTypeGenerator
	{
	  public:
		typedef boost::shared_ptr<EventTypeGenerator> SPtr;

		EventTypeGenerator(void);
		~EventTypeGenerator(void);

		void informationModel(InformationModel::SPtr& informationModel);
		void eventType(OpcUaStackCore::OpcUaNodeId& eventType);
		void projectNamespace(const std::string& projectNamespace);
		void parentProjectNamespace(const std::string& parentProjectNamespace);
		std::string& sourceContent(void);
		std::string& headerContent(void);

		bool generate(void);

	  private:
		std::string getTypeNameFromNodeId(OpcUaStackCore::OpcUaNodeId& typeNodeId);
		bool createVariableElementVec(const std::string& prefix, OpcUaStackCore::OpcUaNodeId& nodeId);

		//
		// header functions
		//
		bool generateHeader(void);
		bool generateHeaderComments(void);
		bool generateHeaderBegin(void);
		bool generateHeaderEnd(void);
		bool generateHeaderClassBegin(const std::string& prefix);
		bool generateHeaderClassEnd(const std::string& prefix);
		bool generateHeaderClassPublic(const std::string& prefix);
		bool generateHeaderClassPrivate(const std::string& prefix);

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
		bool generateSourceClassSetter(const std::string& prefix);
		bool generateSourceClassNamespaceUri(const std::string& prefix);
		bool generateSourceClassGet(const std::string& prefix);

		InformationModel::SPtr informationModel_;
		BaseNodeClass::SPtr eventTypeNode_;
		BaseNodeClass::SPtr parentEventTypeNode_;
		OpcUaStackCore::OpcUaNodeId eventTypeNodeId_;
		OpcUaStackCore::OpcUaNodeId parentEventTypeNodeId_;
		uint32_t eventTypeNumber_;
		std::string eventTypeName_;
		std::string parentEventTypeName_;
		std::string sourceContent_;
		std::string headerContent_;

		std::string namespaceUri_;
		std::string projectNamespace_;
		std::string parentProjectNamespace_;
		std::string projectDirectory_;
		std::string parentProjectDirectory_;

		VariableElement::Vec variableElementVec_;
	};


}

#endif
