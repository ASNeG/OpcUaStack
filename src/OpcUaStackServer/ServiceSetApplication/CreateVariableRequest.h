/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_CreateVariableRequest_h__
#define __OpcUaStackServer_CreateVariableRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"

namespace OpcUaStackServer
{

	class DLLEXPORT CreateVariableRequest
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<CreateVariableRequest>;
		using NodeIdMap = std::map<std::string, OpcUaStackCore::OpcUaNodeId>;

		CreateVariableRequest(void);
		virtual ~CreateVariableRequest(void);

		void namespaceName(const std::string& namespaceName);
		std::string& namespaceName(void);
		void displayName(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		OpcUaStackCore::OpcUaLocalizedText& displayName(void);
		void parentNodeId(const OpcUaStackCore::OpcUaNodeId& parentNodeId);
		OpcUaStackCore::OpcUaNodeId& parentNodeId(void);
		void referenceTypeNodeId(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId);
		OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId(void);
        void variableInstance(Object::SPtr& variableInstance);
        Object::SPtr& variableInstance(void);
        bool addNodeId(const std::string& nodeName, const OpcUaStackCore::OpcUaNodeId& nodeId);
        bool getNodeId(const std::string& nodeName, OpcUaStackCore::OpcUaNodeId& nodeId);
        CreateVariableRequest::NodeIdMap& nodeIdMap(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		std::string namespaceName_;
		OpcUaStackCore::OpcUaLocalizedText displayName_;
		OpcUaStackCore::OpcUaNodeId parentNodeId_;
		OpcUaStackCore::OpcUaNodeId referenceTypeNodeId_;
		Object::SPtr variableInstance_;
		NodeIdMap nodeIdMap_;
	};

}

#endif
