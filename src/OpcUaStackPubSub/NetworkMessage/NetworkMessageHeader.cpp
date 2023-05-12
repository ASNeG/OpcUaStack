#include "OpcUaStackPubSub/NetworkMessage/NetworkMessageHeader.h"

namespace OpcUaStackPubSub
{
    
    OpcUaByte& NetworkMessageHeader::uadpVersionAndFlags()
    {
        //OpcUaByte uadpVersionAndFlags;
        //uadpVersionAndFlags &= uadpVersion_;
        //uadpVersionAndFlags = (uadpVersionAndFlags<<4) & uadpFlags_;
        return uadpVersionAndFlags_;
    }

    void NetworkMessageHeader::uadpVersionAndFlags(const OpcUaByte& uadpVersionAndFlags)
    {
        //uadpVersion_ = uadpVersionAndFlags & 0x0F;
        //uadpFlags_   = uadpVersionAndFlags>>4 & 0x0F;
        uadpVersionAndFlags_ = uadpVersionAndFlags;
    }
  
    OpcUaByte& NetworkMessageHeader::extendedFlags1()
    {
        return extendedFlags1_;
    }
    void NetworkMessageHeader::extendedFlags1(const OpcUaByte& extendedFlags1)
    {
        extendedFlags1_ = extendedFlags1;
    }
      
    OpcUaByte& NetworkMessageHeader::extendedFlags2()
    {
        return extendedFlags2_;
    }
    void NetworkMessageHeader::extendedFlags2(const OpcUaByte& extendedFlags2)
    {
        extendedFlags2_ = extendedFlags2;
    }
      
    OpcUaUInt32& NetworkMessageHeader::publisherId()
    {
        return publisherId_;
    }
    void NetworkMessageHeader::publisherId(const OpcUaUInt32& publisherId)
    {
        publisherId_ = publisherId;
    }
      
    OpcUaGuid& NetworkMessageHeader::dataSetClassId()
    {
        return dataSetClassId_;
    }

    void NetworkMessageHeader::dataSetClassId(const OpcUaGuid& dataSetClassId)
    {
        dataSetClassId_ = dataSetClassId;
    }
    
    // ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// NetworkMessageHeader Encoding and Decoding
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    bool
	NetworkMessageHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;
        rc &= OpcUaNumber::opcUaBinaryEncode(os, uadpVersionAndFlags_);
        //rc &= OpcUaNumber::opcUaBinaryEncode(os, uadpFlags_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, extendedFlags1_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, extendedFlags2_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os, publisherId_);
        rc &= dataSetClassId_.opcUaBinaryEncode(os);
		return rc;
	}
		
	bool
	NetworkMessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;
        //OpcUaByte versionFlags;
        rc &= OpcUaNumber::opcUaBinaryDecode(is, uadpVersionAndFlags_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, extendedFlags1_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, extendedFlags2_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is, publisherId_);
        //uadpVersion_ = versionFlags & 0x0F;
        //uadpFlags_   = versionFlags>>4 & 0x0F;
		return rc;
	}
	

}