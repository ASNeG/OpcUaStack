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

#ifndef __OpcUaStackServer_RegisterForwardNode_h__
#define __OpcUaStackServer_RegisterForwardNode_h__

#include <vector>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardNode
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardNode> SPtr;

		RegisterForwardNode(void);
		RegisterForwardNode(const OpcUaStackCore::OpcUaNodeId& node);
		RegisterForwardNode(const std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		RegisterForwardNode(std::initializer_list<OpcUaStackCore::OpcUaNodeId> nodes);
		virtual ~RegisterForwardNode(void);

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


		void setReadCallback(
			OpcUaStackCore::ApplicationCallback::Read callback
		);
		void setWriteCallback(
			OpcUaStackCore::ApplicationCallback::Write callback
		);
		void setReadHCallback(
			OpcUaStackCore::ApplicationCallback::HRead callback
		);
		void setReadHECallback(
			OpcUaStackCore::ApplicationCallback::HERead callback
		);
		void setWriteHCallback(
			OpcUaStackCore::ApplicationCallback::HWrite callback
		);
		void setMethodCallback(
			OpcUaStackCore::ApplicationCallback::Method callback
		);
		void setMonitoredItemStartCallback(
			OpcUaStackCore::ApplicationCallback::MonitoredItemStart callback
		);
		void setMonitoredItemStopCallback(
			OpcUaStackCore::ApplicationCallback::MonitoredItemStop callback
		);

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStackCore::OpcUaStatusCode>& statuses(void);

	  private:
		std::vector<OpcUaStackCore::OpcUaNodeId> nodes_;
		std::vector<OpcUaStackCore::BaseClass::SPtr> applicationContextVec_;
		ForwardNodeSync forwardNodeSync_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
		std::vector<OpcUaStackCore::OpcUaStatusCode> statuses_;
	};

}
#endif
