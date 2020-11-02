/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_RegisterforwardNodeAsync_h__
#define __OpcUaStackServer_RegisterforwardNodeAsync_h__

#include <vector>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardNodeAsync
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardNodeAsync> SPtr;

		RegisterForwardNodeAsync(void);
		RegisterForwardNodeAsync(const OpcUaStackCore::OpcUaNodeId& node);
		RegisterForwardNodeAsync(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		RegisterForwardNodeAsync(std::initializer_list<OpcUaStackCore::OpcUaNodeId> nodes);
		virtual ~RegisterForwardNodeAsync(void);

		void addNode(const OpcUaStackCore::OpcUaNodeId& node);
		void addNodes(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		void node(const OpcUaStackCore::OpcUaNodeId& node);
		void nodes(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		std::vector<OpcUaStackCore::OpcUaNodeId>& nodes(void);

		void addApplicationContext(OpcUaStackCore::BaseClass::SPtr& applicationContext);
		void addApplicationContext(std::vector<OpcUaStackCore::BaseClass::SPtr>& applicationContextVec);
		void applicationContext(OpcUaStackCore::BaseClass::SPtr& applicationContext);
		void applicationContext(std::vector<OpcUaStackCore::BaseClass::SPtr>& applicationContextVec);
		std::vector<OpcUaStackCore::BaseClass::SPtr>& applicationContextVec(void);

		OpcUaStackCore::ForwardNodeAsync& forwardNodeAsync(void);


		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStackCore::OpcUaStatusCode>& statuses(void);

	  private:
		std::vector<OpcUaStackCore::OpcUaNodeId> nodes_;
		std::vector<OpcUaStackCore::BaseClass::SPtr> applicationContextVec_;
		OpcUaStackCore::ForwardNodeAsync forwardNodeAsync_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
		std::vector<OpcUaStackCore::OpcUaStatusCode> statuses_;
	};

}
#endif
