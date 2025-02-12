#ifndef __OpcUaStackPubSub_NetworkMessage_h__
#define __OpcUaStackPubSub_NetworkMessage_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackPubSub/DataSetWriter/DataSetWriterBase.h"
#include "OpcUaStackPubSub/Events/NetworkSendEvent.h"
#include "OpcUaStackPubSub/Events/NetworkRecvEvent.h"
#include "OpcUaStackPubSub/NetworkMessage/NetworkMessageHeader.h"
#include "OpcUaStackPubSub/NetworkMessage/GroupHeader.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <vector>

using namespace OpcUaStackCore;
class NetworkMessageHeader;
class GroupHeader;

namespace OpcUaStackPubSub
{

  class DLLEXPORT NetworkMessage 
    : public OpcUaStackCore::Object
	  , public OpcUaStackServer::ServerServiceBase
    {
      public:
        using SPtr = boost::shared_ptr<NetworkMessage>;
        
        NetworkMessage();
        virtual ~NetworkMessage();

        void addPayLoadItem(uint32_t& dataSetMessage);
        NetworkMessageHeader::SPtr networkMessageHeader();
        void networkMessageHeader(const NetworkMessageHeader::SPtr networkMessageHeader);
        GroupHeader::SPtr groupHeader();
        void groupHeader(const GroupHeader::SPtr groupHeader);
        bool opcUaBinaryEncode(std::ostream& os) const;
        bool opcUaBinaryDecode(std::istream& is);

      private:
        NetworkMessageHeader::SPtr networkMessageHeader_;
        GroupHeader::SPtr groupHeader_;
        OpcUaInt32Array payLoad_;
        //std::vector<uint32_t> payLoad_;            //actual payload datatype is DataSetMessage
    };
}

#endif