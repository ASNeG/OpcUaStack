/*
    DataTypeClass: DeleteAtTimeDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DeleteAtTimeDetails.h"

namespace OpcUaStackCore
{
    
    DeleteAtTimeDetails::DeleteAtTimeDetails(void)
    : HistoryUpdateDetails()
    , reqTimes_()
    {
    }
    
    DeleteAtTimeDetails::~DeleteAtTimeDetails(void)
    {
    }
    
    OpcUaUtcTimeArray&
    DeleteAtTimeDetails::reqTimes(void)
    {
        return reqTimes_;
    }
    
    bool
    DeleteAtTimeDetails::operator==(const DeleteAtTimeDetails& value)
    {
        DeleteAtTimeDetails* dst = const_cast<DeleteAtTimeDetails*>(&value);
        if (reqTimes_ != dst->reqTimes()) return false;
        return true;
    }
    
    bool
    DeleteAtTimeDetails::operator!=(const DeleteAtTimeDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    DeleteAtTimeDetails::copyTo(DeleteAtTimeDetails& value)
    {
        reqTimes_.copyTo(value.reqTimes());
    }
    
    DeleteAtTimeDetails&
    DeleteAtTimeDetails::operator=(const DeleteAtTimeDetails& value)
    {
        const_cast<DeleteAtTimeDetails*>(&value)->copyTo(*this);
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
    DeleteAtTimeDetails::factory(void)
    {
    	return constructSPtr<DeleteAtTimeDetails>();
    }
    
    std::string
    DeleteAtTimeDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DeleteAtTimeDetails::typeName(void)
    {
    	return "DeleteAtTimeDetails";
    }
    
    OpcUaNodeId
    DeleteAtTimeDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)689,0);
    }
    
    OpcUaNodeId
    DeleteAtTimeDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)691, 0);
    }
    
    OpcUaNodeId
    DeleteAtTimeDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)690, 0);
    }
    
    OpcUaNodeId
    DeleteAtTimeDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15284, 0);
    }
    
    void
    DeleteAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryUpdateDetails::opcUaBinaryEncode(os);
        reqTimes_.opcUaBinaryEncode(os);
    }
    
    void
    DeleteAtTimeDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryUpdateDetails::opcUaBinaryDecode(is);
        reqTimes_.opcUaBinaryDecode(is);
    }
    
    bool
    DeleteAtTimeDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DeleteAtTimeDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DeleteAtTimeDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DeleteAtTimeDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!reqTimes_.xmlEncode(elementTree, "UtcTime", xmlns)) return false;
        pt.push_back(std::make_pair("ReqTimes", elementTree));
    
        return true;
    }
    
    bool
    DeleteAtTimeDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DeleteAtTimeDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ReqTimes");
        if (!tree) return false;
        if (!reqTimes_.xmlDecode(*tree, "UtcTime", xmlns)) return false;
    
        return true;
    }
    
    bool
    DeleteAtTimeDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DeleteAtTimeDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DeleteAtTimeDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DeleteAtTimeDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DeleteAtTimeDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DeleteAtTimeDetails* dst = dynamic_cast<DeleteAtTimeDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DeleteAtTimeDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DeleteAtTimeDetails* dst = dynamic_cast<DeleteAtTimeDetails*>(&extensionObjectBase);
    	return *const_cast<DeleteAtTimeDetails*>(this) == *dst;
    }
    
    void
    DeleteAtTimeDetails::out(std::ostream& os)
    {
        os << "ReqTimes="; reqTimes_.out(os);
    }

}
