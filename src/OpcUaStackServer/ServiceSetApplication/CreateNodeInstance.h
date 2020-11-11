/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_CreateNodeInstance_h__
#define __OpcUaStackServer_CreateNodeInstance_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT CreateNodeInstance
	{
	  public:
		using SPtr = boost::shared_ptr<CreateNodeInstance>;

		CreateNodeInstance(void);
		CreateNodeInstance(
			const std::string& name,
			const OpcUaStackCore::NodeClass::Enum nodeClassType,
			const OpcUaStackCore::OpcUaNodeId& parentNodeId,
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaLocalizedText& displayName,
			const OpcUaStackCore::OpcUaQualifiedName& browseName,
			const OpcUaStackCore::OpcUaNodeId& referenceNodeId,
			const OpcUaStackCore::OpcUaNodeId& typeNodeId
		);
		virtual ~CreateNodeInstance(void);

		void name(const std::string& name);
		void nodeClassType(OpcUaStackCore::NodeClass::Enum nodeClassType);
		void parentNodeId(const OpcUaStackCore::OpcUaNodeId& parentNodeId);
		void nodeId(const OpcUaStackCore::OpcUaNodeId& nodeId);
		void displayName(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		void browseName(const OpcUaStackCore::OpcUaQualifiedName& browseName);
		void referenceNodeId(const OpcUaStackCore::OpcUaNodeId& referenceNodeId);
		void typeNodeId(const OpcUaStackCore::OpcUaNodeId& typeNodeId);

		bool query(ApplicationServiceIf* applicationServiceIf);

		OpcUaStackCore::OpcUaStatusCode resultCode(void);
		OpcUaStackServer::BaseNodeClass::WPtr& baseNodeClass(void);

	  private:
		std::string name_;
		OpcUaStackCore::NodeClass::Enum nodeClass_;
		OpcUaStackCore::OpcUaNodeId parentNodeId_;
		OpcUaStackCore::OpcUaNodeId nodeId_;
		OpcUaStackCore::OpcUaLocalizedText displayName_;
		OpcUaStackCore::OpcUaQualifiedName browseName_;
		OpcUaStackCore::OpcUaNodeId referenceNodeId_;
		OpcUaStackCore::OpcUaNodeId typeNodeId_;			// optional

		OpcUaStackCore::OpcUaStatusCode resultCode_ = OpcUaStackCore::Success;	// result code of the operation
		OpcUaStackServer::BaseNodeClass::WPtr baseNodeClass_;// base class reference of the created node
	};

}
#endif
