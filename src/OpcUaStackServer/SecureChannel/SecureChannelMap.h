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

#ifndef __OpcUaStackServer_SecureChannelMap_h__
#define __OpcUaStackServer_SecureChannelMap_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServer.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum {
		SecureChannelState_Init,
		SecureChannelState_Connect
	} SecureChannelState;


	class DLLEXPORT SecureChannelElement : public ObjectPool<SecureChannelElement>
	{
	  public:
		typedef boost::shared_ptr<SecureChannelElement> SPtr;

		OpcUaUInt32 channelId_;
		SecureChannelState secureChannelState_;
		SecureChannelServer::SPtr secureChannelServer_;
	};


	class DLLEXPORT SecureChannelMap
	{
	  public:
		typedef std::map<OpcUaInt32, SecureChannelElement::SPtr> SecureChannelElementMap;

		SecureChannelMap(void);
		~SecureChannelMap(void);

		uint32_t size(void);
		bool insert(OpcUaInt32 channelId, SecureChannelServer::SPtr secureChannelServer);
		bool connect(OpcUaInt32 channelId);
		bool disconnect(OpcUaInt32 channelId);

		SecureChannelServer::SPtr get(OpcUaUInt32 channelId);

	  private:
		SecureChannelElement::SPtr secureChannelElement(OpcUaInt32 channelId);

		SecureChannelElementMap secureChannelElementMap_;
	};

}

#endif
