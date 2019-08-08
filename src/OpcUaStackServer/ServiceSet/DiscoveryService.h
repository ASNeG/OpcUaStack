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

#ifndef __OpcUaStackServer_DiscoveryService_h__
#define __OpcUaStackServer_DiscoveryService_h__

#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/ServiceSet/DiscoveryServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescriptionSet.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT DiscoveryService 
	: public ServiceSetBase
	, public Object
	{
	  public:
		typedef boost::shared_ptr<DiscoveryService> SPtr;

		DiscoveryService(void);
		~DiscoveryService(void);

		void discoveryIf(DiscoveryIf* discoveryIf);
		void endpointDescriptionSet(EndpointDescriptionSet::SPtr& endpointDescriptionSet);
		void cryptoManager(CryptoManager::SPtr& cryptoManager);

		void getEndpointRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void registerServerRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void findServersRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;
		CryptoManager::SPtr cryptoManager_;
		DiscoveryIf* discoveryIf_;
	};

}

#endif
