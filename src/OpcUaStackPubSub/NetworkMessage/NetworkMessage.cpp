#include "OpcUaStackPubSub/NetworkMessage/NetworkMessage.h"

namespace OpcUaStackPubSub
{
    
    NetworkMessage::NetworkMessage()
    : Object()
    , networkMessageHeader_(boost::make_shared<NetworkMessageHeader>())
    , groupHeader_(boost::make_shared<GroupHeader>())
    {

    }

    NetworkMessage::~NetworkMessage()
    {

    }

    void NetworkMessage::addPayLoadItem(uint32_t& dataSetMessage)
    {
        payLoad_.push_back(dataSetMessage);
    }


    NetworkMessageHeader::SPtr NetworkMessage::networkMessageHeader()
    {
        return networkMessageHeader_;
    }

    void NetworkMessage::networkMessageHeader(const NetworkMessageHeader::SPtr networkMessageHeader)
    {
        networkMessageHeader_ = networkMessageHeader;
    }

    GroupHeader::SPtr NetworkMessage::groupHeader()
    {
        return groupHeader_;
    }

    void NetworkMessage::groupHeader(const GroupHeader::SPtr groupHeader)
    {
        groupHeader_ = groupHeader;
    }

    // ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// NetworkMessage Encoding and Decoding
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    bool
	NetworkMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;
        rc &= networkMessageHeader_->opcUaBinaryEncode(os);
        rc &= groupHeader_->opcUaBinaryEncode(os);
        rc &= payLoad_.opcUaBinaryEncode(os);
		return rc;
	}

	bool
	NetworkMessage::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;
        rc &= networkMessageHeader_->opcUaBinaryDecode(is);
        rc &= groupHeader_->opcUaBinaryDecode(is);;
        rc &= payLoad_.opcUaBinaryDecode(is);
		return rc;
	}	
}