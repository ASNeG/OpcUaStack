/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_SecureChannelMapOld_h__
#define __OpcUaStackServer_SecureChannelMapOld_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServerOld.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum {
		SecureChannelState_Init,
		SecureChannelState_Connect
	} SecureChannelState;


	class DLLEXPORT SecureChannelElementOld
	: public Object
	{
	  public:
		typedef boost::shared_ptr<SecureChannelElementOld> SPtr;

		OpcUaUInt32 channelId_;
		SecureChannelState secureChannelState_;
		SecureChannelServerOld::SPtr secureChannelServer_;
	};


	class DLLEXPORT SecureChannelMapOld
	{
	  public:
		typedef std::map<OpcUaInt32, SecureChannelElementOld::SPtr> SecureChannelElementOldMap;

		SecureChannelMapOld(void);
		~SecureChannelMapOld(void);

		uint32_t size(void);
		bool insert(OpcUaInt32 channelId, SecureChannelServerOld::SPtr secureChannelServer);
		bool connect(OpcUaInt32 channelId);
		bool disconnect(OpcUaInt32 channelId);

		SecureChannelServerOld::SPtr get(OpcUaUInt32 channelId);

	  private:
		SecureChannelElementOld::SPtr secureChannelElement(OpcUaInt32 channelId);

		SecureChannelElementOldMap secureChannelElementMap_;
	};

}

#endif
