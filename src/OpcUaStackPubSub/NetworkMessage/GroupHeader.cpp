#include "OpcUaStackPubSub/NetworkMessage/GroupHeader.h"

namespace OpcUaStackPubSub
{
    
    OpcUaByte& GroupHeader::groupFlags()
    {
        return groupFlags_;
    }
    void GroupHeader::groupFlags(OpcUaByte& groupFlags)
    {
        groupFlags_ = groupFlags;
    }

    OpcUaUInt16& GroupHeader::writerGroupId()
    {
        return writerGroupId_;
    }
    void GroupHeader::writerGroupId(OpcUaUInt16& writerGroupId)
    {
        writerGroupId_ = writerGroupId;
    }
      
    OpcUaByte& GroupHeader::groupVersion()
    {
        return groupVersion_;
    }
    
    void GroupHeader::groupVersion(OpcUaByte& groupVersion)
    {
        groupVersion_ = groupVersion;
    }
      
    OpcUaUInt16& GroupHeader::networkMessageNumber()
    {
        return networkMessageNumber_;
    }
    void GroupHeader::networkMessageNumber(OpcUaUInt16& networkMessageNumber)
    {
        networkMessageNumber_ = networkMessageNumber;
    }
    OpcUaUInt16& GroupHeader::sequenceNumber()
    {
        return sequenceNumber_;
    }
    void GroupHeader::sequenceNumber(OpcUaUInt16& sequenceNumber)
    {
        sequenceNumber_ = sequenceNumber;
    }
    // ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// GroupHeader Encoding and Decoding
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    bool
	GroupHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;
        rc &= OpcUaNumber::opcUaBinaryEncode(os, groupFlags_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, writerGroupId_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, groupVersion_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, networkMessageNumber_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, sequenceNumber_);

		return rc;
	}
	bool
	GroupHeader::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;
        rc &= OpcUaNumber::opcUaBinaryDecode(is, groupFlags_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, writerGroupId_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, groupVersion_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, networkMessageNumber_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, sequenceNumber_);
        return rc;
	}

    
	

}