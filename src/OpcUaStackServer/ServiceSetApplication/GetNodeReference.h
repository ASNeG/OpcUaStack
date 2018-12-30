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

#ifndef __OpcUaStackServer_GetNodeReference_h__
#define __OpcUaStackServer_GetNodeReference_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT GetNodeReference
	{
	  public:
		typedef boost::shared_ptr<GetNodeReference> SPtr;

		GetNodeReference(void);
		GetNodeReference(const OpcUaNodeId& node);
		GetNodeReference(const std::vector<OpcUaNodeId>& nodes);
		GetNodeReference(std::initializer_list<OpcUaNodeId> nodes);
		virtual ~GetNodeReference(void);

		void addNode(const OpcUaNodeId& node);
		void addNodes(const std::vector<OpcUaNodeId>& nodes);
		void node(const OpcUaNodeId& node);
		void nodes(const std::vector<OpcUaNodeId>& nodes);
		std::vector<OpcUaNodeId>& nodes(void);

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStatusCode>& statuses(void);
		std::vector<BaseNodeClass::WPtr>& nodeReferences(void);

	  private:
		std::vector<OpcUaNodeId> nodes_;
		OpcUaStatusCode resultCode_;
		std::vector<OpcUaStatusCode> statuses_;
		std::vector<BaseNodeClass::WPtr> nodeReferences_;
	};

}
#endif
