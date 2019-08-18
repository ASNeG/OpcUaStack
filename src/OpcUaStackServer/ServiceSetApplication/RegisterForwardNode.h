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

#ifndef __OpcUaStackServer_RegisterForwardNode_h__
#define __OpcUaStackServer_RegisterForwardNode_h__

#include <vector>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
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

		void setReadCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setReadCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setReadCallback(callback);
		  }
		void setWriteCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setWriteCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setWriteCallback(callback);
		  }
		void setReadHCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setReadHCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setReadHCallback(callback);
		  }
		void setReadHECallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setReadHECallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setReadHECallback(callback);
		  }
		void setWriteHCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setWriteHCallback(T handler) {
		  	  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setReadHCallback(callback);
		  }
		void setMethodCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setMethodCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setMethodCallback(callback);
		  }
		void setMonitoredItemStartCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setMonitoredItemStartCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setMonitoredItemStartCallback(callback);
		  }
		void setMonitoredItemStopCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setMonitoredItemStopCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setMonitoredItemStopCallback(callback);
		  }

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStackCore::OpcUaStatusCode>& statuses(void);

	  private:
		std::vector<OpcUaStackCore::OpcUaNodeId> nodes_;
		OpcUaStackCore::ForwardNodeSync forwardNodeSync_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
		std::vector<OpcUaStackCore::OpcUaStatusCode> statuses_;
	};

}
#endif
