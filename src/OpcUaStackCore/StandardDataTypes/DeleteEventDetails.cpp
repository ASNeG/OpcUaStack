/*
    DataTypeClass: DeleteEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DeleteEventDetails.h"

namespace OpcUaStackCore
{
    
    DeleteEventDetails::DeleteEventDetails(void)
    : HistoryUpdateDetails()
    , eventIds_()
    {
    }
    
    DeleteEventDetails::~DeleteEventDetails(void)
    {
    }
    
    OpcUaByteStringArray&
    DeleteEventDetails::eventIds(void)
    {
        return eventIds_;
    }
    
    bool
    DeleteEventDetails::operator==(const DeleteEventDetails& value)
    {
        DeleteEventDetails* dst = const_cast<DeleteEventDetails*>(&value);
        if (eventIds_ != dst->eventIds()) return false;
        return true;
    }
    
    bool
    DeleteEventDetails::operator!=(const DeleteEventDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    DeleteEventDetails::copyTo(DeleteEventDetails& value)
    {
        eventIds_.copyTo(value.eventIds());
    }
    
    DeleteEventDetails&
    DeleteEventDetails::operator=(const DeleteEventDetails& value)
    {
        const_cast<DeleteEventDetails*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    DeleteEventDetails::factory(void)
    {
    	return constructSPtr<DeleteEventDetails>();
    }
    
    std::string
    DeleteEventDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DeleteEventDetails::typeName(void)
    {
    	return "DeleteEventDetails";
    }
    
    OpcUaNodeId
    DeleteEventDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)692,0);
    }
    
    OpcUaNodeId
    DeleteEventDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)694, 0);
    }
    
    OpcUaNodeId
    DeleteEventDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)693, 0);
    }
    
    OpcUaNodeId
    DeleteEventDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15285, 0);
    }
    
    void
    DeleteEventDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryUpdateDetails::opcUaBinaryEncode(os);
        eventIds_.opcUaBinaryEncode(os);
    }
    
    void
    DeleteEventDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryUpdateDetails::opcUaBinaryDecode(is);
        eventIds_.opcUaBinaryDecode(is);
    }
    
    bool
    DeleteEventDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DeleteEventDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DeleteEventDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DeleteEventDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!eventIds_.xmlEncode(elementTree, "ByteString", xmlns)) return false;
        pt.push_back(std::make_pair("EventIds", elementTree));
    
        return true;
    }
    
    bool
    DeleteEventDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DeleteEventDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("EventIds");
        if (!tree) return false;
        if (!eventIds_.xmlDecode(*tree, "ByteString", xmlns)) return false;
    
        return true;
    }
    
    bool
    DeleteEventDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DeleteEventDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DeleteEventDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DeleteEventDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DeleteEventDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DeleteEventDetails* dst = dynamic_cast<DeleteEventDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DeleteEventDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DeleteEventDetails* dst = dynamic_cast<DeleteEventDetails*>(&extensionObjectBase);
    	return *const_cast<DeleteEventDetails*>(this) == *dst;
    }
    
    void
    DeleteEventDetails::out(std::ostream& os)
    {
        os << "EventIds="; eventIds_.out(os);
    }

}
