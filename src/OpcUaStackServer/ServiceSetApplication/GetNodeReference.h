/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_GetNodeReference_h__
#define __OpcUaStackServer_GetNodeReference_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT GetNodeReference
	{
	  public:
		typedef boost::shared_ptr<GetNodeReference> SPtr;

		GetNodeReference(void);
		GetNodeReference(const OpcUaStackCore::OpcUaNodeId& node);
		GetNodeReference(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		GetNodeReference(std::initializer_list<OpcUaStackCore::OpcUaNodeId> nodes);
		virtual ~GetNodeReference(void);

		void addNode(const OpcUaStackCore::OpcUaNodeId& node);
		void addNodes(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		void node(const OpcUaStackCore::OpcUaNodeId& node);
		void nodes(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		std::vector<OpcUaStackCore::OpcUaNodeId>& nodes(void);

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStackCore::OpcUaStatusCode>& statuses(void);
		std::vector<BaseNodeClass::WPtr>& nodeReferences(void);

	  private:
		std::vector<OpcUaStackCore::OpcUaNodeId> nodes_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
		std::vector<OpcUaStackCore::OpcUaStatusCode> statuses_;
		std::vector<BaseNodeClass::WPtr> nodeReferences_;
	};

}
#endif
