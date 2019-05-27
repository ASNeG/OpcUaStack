/*
    DataTypeClass: PublishedDataSetSourceDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PublishedDataSetSourceDataType.h"

namespace OpcUaStackCore
{
    
    PublishedDataSetSourceDataType::PublishedDataSetSourceDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    PublishedDataSetSourceDataType::PublishedDataSetSourceDataType(const PublishedDataSetSourceDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<PublishedDataSetSourceDataType*>(&value)->copyTo(*this);
    }
    
    PublishedDataSetSourceDataType::~PublishedDataSetSourceDataType(void)
    {
    }
    
    bool
    PublishedDataSetSourceDataType::operator==(const PublishedDataSetSourceDataType& value)
    {
        PublishedDataSetSourceDataType* dst = const_cast<PublishedDataSetSourceDataType*>(&value);
        return true;
    }
    
    bool
    PublishedDataSetSourceDataType::operator!=(const PublishedDataSetSourceDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PublishedDataSetSourceDataType::copyTo(PublishedDataSetSourceDataType& value)
    {
    }
    
    PublishedDataSetSourceDataType&
    PublishedDataSetSourceDataType::operator=(const PublishedDataSetSourceDataType& value)
    {
        const_cast<PublishedDataSetSourceDataType*>(&value)->copyTo(*this);
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
    PublishedDataSetSourceDataType::factory(void)
    {
    	return constructSPtr<PublishedDataSetSourceDataType>();
    }
    
    std::string
    PublishedDataSetSourceDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PublishedDataSetSourceDataType::typeName(void)
    {
    	return "PublishedDataSetSourceDataType";
    }
    
    OpcUaNodeId
    PublishedDataSetSourceDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15580,0);
    }
    
    OpcUaNodeId
    PublishedDataSetSourceDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15678, 0);
    }
    
    OpcUaNodeId
    PublishedDataSetSourceDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15952, 0);
    }
    
    OpcUaNodeId
    PublishedDataSetSourceDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16153, 0);
    }
    
    void
    PublishedDataSetSourceDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    PublishedDataSetSourceDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    PublishedDataSetSourceDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedDataSetSourceDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedDataSetSourceDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    PublishedDataSetSourceDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetSourceDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedDataSetSourceDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    PublishedDataSetSourceDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    PublishedDataSetSourceDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    PublishedDataSetSourceDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PublishedDataSetSourceDataType* dst = dynamic_cast<PublishedDataSetSourceDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PublishedDataSetSourceDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PublishedDataSetSourceDataType* dst = dynamic_cast<PublishedDataSetSourceDataType*>(&extensionObjectBase);
    	return *const_cast<PublishedDataSetSourceDataType*>(this) == *dst;
    }
    
    void
    PublishedDataSetSourceDataType::out(std::ostream& os)
    {
    }

}
