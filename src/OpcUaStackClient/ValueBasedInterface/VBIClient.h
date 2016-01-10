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
#include "OpcUaStackClient/ValueBasedInterface/VBIContext.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT VBIClient
	: public SessionServiceIf
	, public AttributeServiceIf
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
				Callback callback(handler);
				asyncConnect(callback, connectContext);
			}


		OpcUaStatusCode syncDisconnect(void);
		void asyncDisconnect(void);
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

		// read
		ReadContext& defaultReadContext(void);
		OpcUaStatusCode syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue);
		OpcUaStatusCode syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, ReadContext& readContext);
		void asyncRead(OpcUaNodeId& nodeId, Callback& callback);
		template<typename HANDLER>
		    void asyncRead(OpcUaNodeId& nodeId, HANDLER handler) {
				Callback callback = handler;
				asyncRead(nodeId, handler);
			}
		void asyncRead(OpcUaNodeId& nodeId, Callback& callback, ReadContext& readContext);
		template<typename HANDLER>
			void asyncRead(OpcUaNodeId& nodeId, HANDLER handler, ReadContext& readContext) {
				Callback callback = handler;
				asyncRead(nodeId, handler, readContext);
			}


		// write
		WriteContext& defaultWriteContext(void);
		OpcUaStatusCode syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue);
		OpcUaStatusCode syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, WriteContext& writeContext);
		void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback);
		template<typename HANDLER>
		    void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, HANDLER handler) {
				Callback callback = handler;
				asyncWrite(nodeId, dataValue, callback);
			}
		void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback, WriteContext& writeContext);
		template<typename HANDLER>
		    void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, HANDLER handler, WriteContext& writeContext) {
				Callback callback = handler;
				asyncWrite(nodeId, dataValue, callback, writeContext);
			}

	  private:
		// BEGIN SessionServiceIf
		void sessionStateUpdate(SessionBase& session, SessionState sessionState);
		// END SessionServiceIf

		// BEGIN AttributeServiceIf
        void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead);
		void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);

		// END AttributeServiceIf

		ServiceSetManager serviceSetManager_;
		std::string ioThreadName_;

		SessionService::SPtr sessionService_;
		AttributeService::SPtr attributeService_;
		Callback sessionStateUpdateCallback_;

		ReadContext defaultReadContext_;
		WriteContext defaultWriteContext_;
	};

}

#endif
