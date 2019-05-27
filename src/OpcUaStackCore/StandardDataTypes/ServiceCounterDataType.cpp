/*
    DataTypeClass: ServiceCounterDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ServiceCounterDataType.h"

namespace OpcUaStackCore
{
    
    ServiceCounterDataType::ServiceCounterDataType(void)
    : Object()
    , ExtensionObjectBase()
    , totalCount_()
    , errorCount_()
    {
    }
    
    ServiceCounterDataType::ServiceCounterDataType(const ServiceCounterDataType& value)
    : Object()
    , ExtensionObjectBase()
    , totalCount_()
    , errorCount_()
    {
        const_cast<ServiceCounterDataType*>(&value)->copyTo(*this);
    }
    
    ServiceCounterDataType::~ServiceCounterDataType(void)
    {
    }
    
    OpcUaUInt32&
    ServiceCounterDataType::totalCount(void)
    {
        return totalCount_;
    }
    
    OpcUaUInt32&
    ServiceCounterDataType::errorCount(void)
    {
        return errorCount_;
    }
    
    bool
    ServiceCounterDataType::operator==(const ServiceCounterDataType& value)
    {
        ServiceCounterDataType* dst = const_cast<ServiceCounterDataType*>(&value);
        if (totalCount_ != dst->totalCount()) return false;
        if (errorCount_ != dst->errorCount()) return false;
        return true;
    }
    
    bool
    ServiceCounterDataType::operator!=(const ServiceCounterDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ServiceCounterDataType::copyTo(ServiceCounterDataType& value)
    {
        value.totalCount_ = totalCount_;
        value.errorCount_ = errorCount_;
    }
    
    ServiceCounterDataType&
    ServiceCounterDataType::operator=(const ServiceCounterDataType& value)
    {
        const_cast<ServiceCounterDataType*>(&value)->copyTo(*this);
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
    ServiceCounterDataType::factory(void)
    {
    	return constructSPtr<ServiceCounterDataType>();
    }
    
    std::string
    ServiceCounterDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ServiceCounterDataType::typeName(void)
    {
    	return "ServiceCounterDataType";
    }
    
    OpcUaNodeId
    ServiceCounterDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)871,0);
    }
    
    OpcUaNodeId
    ServiceCounterDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)873, 0);
    }
    
    OpcUaNodeId
    ServiceCounterDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)872, 0);
    }
    
    OpcUaNodeId
    ServiceCounterDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15370, 0);
    }
    
    void
    ServiceCounterDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,totalCount_);
        OpcUaNumber::opcUaBinaryEncode(os,errorCount_);
    }
    
    void
    ServiceCounterDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,totalCount_);
        OpcUaNumber::opcUaBinaryDecode(is,errorCount_);
    }
    
    bool
    ServiceCounterDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServiceCounterDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ServiceCounterDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, totalCount_))
        {
            Log(Error, "ServiceCounterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TotalCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, errorCount_))
        {
            Log(Error, "ServiceCounterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ErrorCount", elementTree));
    
        return true;
    }
    
    bool
    ServiceCounterDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServiceCounterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ServiceCounterDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("TotalCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServiceCounterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, totalCount_)) {
            Log(Error, "ServiceCounterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ErrorCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServiceCounterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, errorCount_)) {
            Log(Error, "ServiceCounterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ServiceCounterDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, totalCount_))
        {
    	     Log(Error, "ServiceCounterDataType json encoder error")
    		     .parameter("Element", "totalCount_");
           return false;
        }
        pt.push_back(std::make_pair("TotalCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, errorCount_))
        {
    	     Log(Error, "ServiceCounterDataType json encoder error")
    		     .parameter("Element", "errorCount_");
           return false;
        }
        pt.push_back(std::make_pair("ErrorCount", elementTree));
    
        return true;
    }
    
    bool
    ServiceCounterDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "TotalCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServiceCounterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, totalCount_)) {
            Log(Error, "ServiceCounterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ErrorCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServiceCounterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, errorCount_)) {
            Log(Error, "ServiceCounterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ServiceCounterDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ServiceCounterDataType* dst = dynamic_cast<ServiceCounterDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ServiceCounterDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ServiceCounterDataType* dst = dynamic_cast<ServiceCounterDataType*>(&extensionObjectBase);
    	return *const_cast<ServiceCounterDataType*>(this) == *dst;
    }
    
    void
    ServiceCounterDataType::out(std::ostream& os)
    {
        os << "TotalCount=" << totalCount_;
        os << ", ErrorCount=" << errorCount_;
    }

}
