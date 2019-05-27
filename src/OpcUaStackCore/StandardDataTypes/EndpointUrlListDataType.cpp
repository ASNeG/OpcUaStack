/*
    DataTypeClass: EndpointUrlListDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EndpointUrlListDataType.h"

namespace OpcUaStackCore
{
    
    EndpointUrlListDataType::EndpointUrlListDataType(void)
    : Object()
    , ExtensionObjectBase()
    , endpointUrlList_()
    {
    }
    
    EndpointUrlListDataType::EndpointUrlListDataType(const EndpointUrlListDataType& value)
    : Object()
    , ExtensionObjectBase()
    , endpointUrlList_()
    {
        const_cast<EndpointUrlListDataType*>(&value)->copyTo(*this);
    }
    
    EndpointUrlListDataType::~EndpointUrlListDataType(void)
    {
    }
    
    OpcUaStringArray&
    EndpointUrlListDataType::endpointUrlList(void)
    {
        return endpointUrlList_;
    }
    
    bool
    EndpointUrlListDataType::operator==(const EndpointUrlListDataType& value)
    {
        EndpointUrlListDataType* dst = const_cast<EndpointUrlListDataType*>(&value);
        if (endpointUrlList_ != dst->endpointUrlList()) return false;
        return true;
    }
    
    bool
    EndpointUrlListDataType::operator!=(const EndpointUrlListDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    EndpointUrlListDataType::copyTo(EndpointUrlListDataType& value)
    {
        endpointUrlList_.copyTo(value.endpointUrlList());
    }
    
    EndpointUrlListDataType&
    EndpointUrlListDataType::operator=(const EndpointUrlListDataType& value)
    {
        const_cast<EndpointUrlListDataType*>(&value)->copyTo(*this);
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
    EndpointUrlListDataType::factory(void)
    {
    	return constructSPtr<EndpointUrlListDataType>();
    }
    
    std::string
    EndpointUrlListDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EndpointUrlListDataType::typeName(void)
    {
    	return "EndpointUrlListDataType";
    }
    
    OpcUaNodeId
    EndpointUrlListDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11943,0);
    }
    
    OpcUaNodeId
    EndpointUrlListDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11957, 0);
    }
    
    OpcUaNodeId
    EndpointUrlListDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11949, 0);
    }
    
    OpcUaNodeId
    EndpointUrlListDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15363, 0);
    }
    
    void
    EndpointUrlListDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        endpointUrlList_.opcUaBinaryEncode(os);
    }
    
    void
    EndpointUrlListDataType::opcUaBinaryDecode(std::istream& is)
    {
        endpointUrlList_.opcUaBinaryDecode(is);
    }
    
    bool
    EndpointUrlListDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointUrlListDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EndpointUrlListDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrlList_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "EndpointUrlListDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrlList", elementTree));
    
        return true;
    }
    
    bool
    EndpointUrlListDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointUrlListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EndpointUrlListDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EndpointUrlList");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointUrlListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrlList_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "EndpointUrlListDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    EndpointUrlListDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrlList_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "EndpointUrlListDataType json encoder error")
    		     .parameter("Element", "endpointUrlList_");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrlList", elementTree));
    
        return true;
    }
    
    bool
    EndpointUrlListDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "EndpointUrlList";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointUrlListDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrlList_.jsonDecode(*tree, "")) {
            Log(Error, "EndpointUrlListDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    EndpointUrlListDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EndpointUrlListDataType* dst = dynamic_cast<EndpointUrlListDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EndpointUrlListDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EndpointUrlListDataType* dst = dynamic_cast<EndpointUrlListDataType*>(&extensionObjectBase);
    	return *const_cast<EndpointUrlListDataType*>(this) == *dst;
    }
    
    void
    EndpointUrlListDataType::out(std::ostream& os)
    {
        os << "EndpointUrlList="; endpointUrlList_.out(os);
    }

}
