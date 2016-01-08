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

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT VBIClient
	{
	  public:
		VBIClient(void);
		~VBIClient(void);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SessionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		OpcUaStatusCode syncConnect(void);
		void asyncConnect(Callback& callback);
		template<typename HANDLER>
		    void asyncConnect(HANDLER handler) {
				Callback callback = handler;
				asyncConnect(handler);
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
	};

}

#endif
