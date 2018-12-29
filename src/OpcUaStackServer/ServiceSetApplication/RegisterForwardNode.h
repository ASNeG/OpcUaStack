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

#ifndef __OpcUaStackServer_RegisterForwardNode_h__
#define __OpcUaStackServer_RegisterForwardNode_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardNode
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardNode> SPtr;

		RegisterForwardNode(void);
		RegisterForwardNode(const OpcUaNodeId& node);
		RegisterForwardNode(const std::vector<OpcUaNodeId>& nodes);
		virtual ~RegisterForwardNode(void);

		void addNode(const OpcUaNodeId& node);
		void addNodes(const std::vector<OpcUaNodeId>& nodes);
		void node(const OpcUaNodeId& node);
		void nodes(const std::vector<OpcUaNodeId>& nodes);
		std::vector<OpcUaNodeId>& nodes(void);

		void setReadCallback(Callback& callback);
		template<typename T>
		  void setReadCallback(T handler) {
			  Callback callback;
			  callback.reset(handler);
			  setReadCallback(callback);
		  }
		void setWriteCallback(Callback& callback);
		template<typename T>
		  void setWriteCallback(T handler) {
			  Callback callback;
			  callback.reset(handler);
			  setWriteCallback(callback);
		  }


			//ForwardCallback& readHService(void);
			//ForwardCallback& readHEService(void);
			//ForwardCallback& writeHService(void);
			//ForwardCallback& methodService(void);
			//ForwardCallback& monitoredItemStartService(void);
			//ForwardCallback& monitoredItemStopService(void);

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStatusCode>& statuses(void);

	  private:
		std::vector<OpcUaNodeId> nodes_;
		ForwardNodeSync forwardNodeSync_;
		OpcUaStatusCode resultCode_;
		std::vector<OpcUaStatusCode> statuses_;
	};

}
#endif
