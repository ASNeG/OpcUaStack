/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/NodeClass.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT CreateNodeInstance
	{
	  public:
		typedef boost::shared_ptr<CreateNodeInstance> SPtr;

		CreateNodeInstance(void);
		CreateNodeInstance(
			const std::string& name,
			const NodeClassType nodeClassType,
			const OpcUaNodeId& parentNodeId,
			const OpcUaNodeId& nodeId,
			const OpcUaLocalizedText& displayName,
			const OpcUaQualifiedName& browseName,
			const OpcUaNodeId& referenceNodeId,
			const OpcUaNodeId& typeNodeId
		);
		virtual ~CreateNodeInstance(void);

		void name(const std::string& name);
		void nodeClassType(NodeClassType nodeClassType);
		void parentNodeId(const OpcUaNodeId& parentNodeId);
		void nodeId(const OpcUaNodeId& nodeId);
		void displayName(const OpcUaLocalizedText& displayName);
		void browseName(const OpcUaQualifiedName& browseName);
		void referenceNodeId(const OpcUaNodeId& referenceNodeId);
		void typeNodeId(const OpcUaNodeId& typeNodeId);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStatusCode resultCode(void);

	  private:
		std::string name_;
		NodeClassType nodeClassType_;
		OpcUaNodeId parentNodeId_;
		OpcUaNodeId nodeId_;
		OpcUaLocalizedText displayName_;
		OpcUaQualifiedName browseName_;
		OpcUaNodeId referenceNodeId_;
		OpcUaNodeId typeNodeId_;			// optional

		OpcUaStatusCode resultCode_;
	};

}
#endif
