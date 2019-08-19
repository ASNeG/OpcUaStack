/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ApplicationService_h__
#define __OpcUaStackServer_ApplicationService_h__

#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationService
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<ApplicationService> SPtr;

		ApplicationService(void);
		~ApplicationService(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveRegisterForwardNodeRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterForwardMethodRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterForwardGlobalRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveGetNodeReferenceRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveNamespaceInfoRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveCreateNodeInstanceRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveDelNodeInstanceRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveFireEventRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowsePathToNodeIdRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveCreateVariableRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveCreateObjectRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void getNodeIdFromBrowsePath(OpcUaStackCore::BrowseName::SPtr& browseName, OpcUaStackCore::NodeIdResult::SPtr& nodeIdResult);
	};

}

#endif
