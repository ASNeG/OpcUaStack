#ifndef __OpcUaStackPubSub_NetworkMessageHeader_h__
#define __OpcUaStackPubSub_NetworkMessageHeader_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{
  class NetworkMessageHeader
  {
    public:
      using SPtr = boost::shared_ptr<NetworkMessageHeader>;
      NetworkMessageHeader() = default;
      virtual ~NetworkMessageHeader() = default;
      bool opcUaBinaryEncode(std::ostream& os) const;
      bool opcUaBinaryDecode(std::istream& is);
      
      OpcUaByte& uadpVersionAndFlags();
      void uadpVersionAndFlags(const OpcUaByte& uadpVersionAndFlags);

      OpcUaByte& extendedFlags1();
      void extendedFlags1(const OpcUaByte& extendedFlags1);
      
      OpcUaByte& extendedFlags2();
      void extendedFlags2(const OpcUaByte& extendedFlags2);
      
      OpcUaUInt32& publisherId();
      void publisherId(const OpcUaUInt32& publisherId);
      
      OpcUaGuid& dataSetClassId();
      void dataSetClassId(const OpcUaGuid& dataSetClassId);


    private:
      OpcUaByte uadpVersionAndFlags_  = 1;
      //OpcUaByte uadpFlags_  :4;
      OpcUaByte extendedFlags1_       = 0;
      OpcUaByte extendedFlags2_       = 0;
      OpcUaUInt32 publisherId_        = 0;
      OpcUaGuid dataSetClassId_;
  };    
}

#endif