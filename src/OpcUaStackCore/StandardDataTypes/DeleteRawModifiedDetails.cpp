/*
    DataTypeClass: DeleteRawModifiedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DeleteRawModifiedDetails.h"

namespace OpcUaStackCore
{
    
    DeleteRawModifiedDetails::DeleteRawModifiedDetails(void)
    : HistoryUpdateDetails()
    , isDeleteModified_()
    , startTime_()
    , endTime_()
    {
    }
    
    DeleteRawModifiedDetails::~DeleteRawModifiedDetails(void)
    {
    }
    
    OpcUaBoolean&
    DeleteRawModifiedDetails::isDeleteModified(void)
    {
        return isDeleteModified_;
    }
    
    OpcUaUtcTime&
    DeleteRawModifiedDetails::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    DeleteRawModifiedDetails::endTime(void)
    {
        return endTime_;
    }
    
    bool
    DeleteRawModifiedDetails::operator==(const DeleteRawModifiedDetails& value)
    {
        DeleteRawModifiedDetails* dst = const_cast<DeleteRawModifiedDetails*>(&value);
        if (isDeleteModified_ != dst->isDeleteModified()) return false;
        if (startTime_ != dst->startTime()) return false;
        if (endTime_ != dst->endTime()) return false;
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::operator!=(const DeleteRawModifiedDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    DeleteRawModifiedDetails::copyTo(DeleteRawModifiedDetails& value)
    {
        value.isDeleteModified_ = isDeleteModified_;
        startTime_.copyTo(value.startTime());
        endTime_.copyTo(value.endTime());
    }
    
    DeleteRawModifiedDetails&
    DeleteRawModifiedDetails::operator=(const DeleteRawModifiedDetails& value)
    {
        const_cast<DeleteRawModifiedDetails*>(&value)->copyTo(*this);
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
    DeleteRawModifiedDetails::factory(void)
    {
    	return constructSPtr<DeleteRawModifiedDetails>();
    }
    
    std::string
    DeleteRawModifiedDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DeleteRawModifiedDetails::typeName(void)
    {
    	return "DeleteRawModifiedDetails";
    }
    
    OpcUaNodeId
    DeleteRawModifiedDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)686,0);
    }
    
    OpcUaNodeId
    DeleteRawModifiedDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)688, 0);
    }
    
    OpcUaNodeId
    DeleteRawModifiedDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)687, 0);
    }
    
    OpcUaNodeId
    DeleteRawModifiedDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15283, 0);
    }
    
    void
    DeleteRawModifiedDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryUpdateDetails::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isDeleteModified_);
        startTime_.opcUaBinaryEncode(os);
        endTime_.opcUaBinaryEncode(os);
    }
    
    void
    DeleteRawModifiedDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryUpdateDetails::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isDeleteModified_);
        startTime_.opcUaBinaryDecode(is);
        endTime_.opcUaBinaryDecode(is);
    }
    
    bool
    DeleteRawModifiedDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DeleteRawModifiedDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DeleteRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isDeleteModified_)) return false;
        pt.push_back(std::make_pair("IsDeleteModified", elementTree));
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DeleteRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("IsDeleteModified");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, isDeleteModified_)) return false;
    
        tree = pt.get_child_optional("StartTime");
        if (!tree) return false;
        if (!startTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EndTime");
        if (!tree) return false;
        if (!endTime_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DeleteRawModifiedDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DeleteRawModifiedDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DeleteRawModifiedDetails* dst = dynamic_cast<DeleteRawModifiedDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DeleteRawModifiedDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DeleteRawModifiedDetails* dst = dynamic_cast<DeleteRawModifiedDetails*>(&extensionObjectBase);
    	return *const_cast<DeleteRawModifiedDetails*>(this) == *dst;
    }
    
    void
    DeleteRawModifiedDetails::out(std::ostream& os)
    {
        os << "IsDeleteModified=" << isDeleteModified_;
        os << ", StartTime="; startTime_.out(os);
        os << ", EndTime="; endTime_.out(os);
    }

}
