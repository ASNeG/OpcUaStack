#ifndef __OpcUaStackPubSub_GroupHeader_h__
#define __OpcUaStackPubSub_GroupHeader_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <vector>

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{
  
  class GroupHeader
  {
    public:
      using SPtr = boost::shared_ptr<GroupHeader>;
      GroupHeader() = default;
      virtual ~GroupHeader() = default;
      bool opcUaBinaryEncode(std::ostream& os) const;
      bool opcUaBinaryDecode(std::istream& is);

      OpcUaByte& groupFlags();
      void groupFlags(OpcUaByte& groupFlags);

      OpcUaUInt16& writerGroupId();
      void writerGroupId(OpcUaUInt16& writerGroupId);
      
      OpcUaByte& groupVersion();
      void groupVersion(OpcUaByte& groupVersion);
      
      OpcUaUInt16& networkMessageNumber();
      void networkMessageNumber(OpcUaUInt16& networkMessageNumber);
      
      OpcUaUInt16& sequenceNumber();
      void sequenceNumber(OpcUaUInt16& sequenceNumber);
        
    private:
      OpcUaByte  groupFlags_;
      OpcUaUInt16 writerGroupId_;
      OpcUaByte  groupVersion_;
      OpcUaUInt16 networkMessageNumber_;
      OpcUaUInt16 sequenceNumber_;
  };
    
}

#endif