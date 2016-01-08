/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_VBIClient_h__
#define __OpcUaStackClient_VBIClient_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ValueBasedInterface/ConnectContext.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT VBIClient
	: public SessionServiceIf
	{
	  public:
		VBIClient(void);
		~VBIClient(void);

		void ioThreadName(const std::string& ioThreadName);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SessionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		OpcUaStatusCode syncConnect(ConnectContext& connectContext);
		void asyncConnect(Callback& callback, ConnectContext& connectContext);
		template<typename HANDLER>
		    void asyncConnect(HANDLER handler, ConnectContext& connectContext) {
				Callback callback = handler;
				asyncConnect(handler, connectContext);
			}


		OpcUaStatusCode syncDisconnect(void);
		void asyncDisconnect(Callback& callback);
		template<typename HANDLER>
		    void asyncDisconnect(HANDLER handler) {
				Callback callback = handler;
				asyncDisconnect(callback);
			}


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// AttributeService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		OpcUaStatusCode syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue);
		void asyncRead(OpcUaNodeId& nodeId, Callback& callback);
		template<typename HANDLER>
		    void asyncRead(OpcUaNodeId& nodeId, HANDLER handler) {
				Callback callback = handler;
				asyncRead(nodeId, handler);
			}


		OpcUaStatusCode syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue);
		void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback);
		template<typename HANDLER>
		    void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, HANDLER handler) {
				Callback callback = handler;
				asyncWrite(nodeId, dataValue, handler);
			}

	  private:
		// BEGIN SessionServiceIf
		void sessionStateUpdate(SessionBase& session, SessionState sessionState);
		// END SessionServiceIf

		ServiceSetManager serviceSetManager_;
		std::string ioThreadName_;

		SessionService::SPtr sessionService_;
		Callback sessionStateUpdateCallback_;
	};

}

#endif
