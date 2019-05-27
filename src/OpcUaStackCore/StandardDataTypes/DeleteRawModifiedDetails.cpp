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
    
    DeleteRawModifiedDetails::DeleteRawModifiedDetails(const DeleteRawModifiedDetails& value)
    : HistoryUpdateDetails()
    , isDeleteModified_()
    , startTime_()
    , endTime_()
    {
        const_cast<DeleteRawModifiedDetails*>(&value)->copyTo(*this);
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
    DeleteRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteRawModifiedDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isDeleteModified_))
        {
            Log(Error, "DeleteRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsDeleteModified", elementTree));
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DeleteRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("IsDeleteModified");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isDeleteModified_)) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("StartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("EndTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DeleteRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isDeleteModified_))
        {
    	     Log(Error, "DeleteRawModifiedDetails json encoder error")
    		     .parameter("Element", "isDeleteModified_");
           return false;
        }
        pt.push_back(std::make_pair("IsDeleteModified", elementTree));
    
        elementTree.clear();
        if (!startTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "DeleteRawModifiedDetails json encoder error")
    		     .parameter("Element", "startTime_");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "DeleteRawModifiedDetails json encoder error")
    		     .parameter("Element", "endTime_");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        return true;
    }
    
    bool
    DeleteRawModifiedDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "IsDeleteModified";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isDeleteModified_)) {
            Log(Error, "DeleteRawModifiedDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "StartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.jsonDecode(*tree)) {
            Log(Error, "DeleteRawModifiedDetails decode json error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = "EndTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.jsonDecode(*tree)) {
            Log(Error, "DeleteRawModifiedDetails decode json error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        return true;
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
