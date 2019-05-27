/*
    DataTypeClass: NotificationData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NotificationData.h"

namespace OpcUaStackCore
{
    
    NotificationData::NotificationData(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    NotificationData::NotificationData(const NotificationData& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<NotificationData*>(&value)->copyTo(*this);
    }
    
    NotificationData::~NotificationData(void)
    {
    }
    
    bool
    NotificationData::operator==(const NotificationData& value)
    {
        NotificationData* dst = const_cast<NotificationData*>(&value);
        return true;
    }
    
    bool
    NotificationData::operator!=(const NotificationData& value)
    {
        return !this->operator==(value);
    }
    
    void
    NotificationData::copyTo(NotificationData& value)
    {
    }
    
    NotificationData&
    NotificationData::operator=(const NotificationData& value)
    {
        const_cast<NotificationData*>(&value)->copyTo(*this);
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
    NotificationData::factory(void)
    {
    	return constructSPtr<NotificationData>();
    }
    
    std::string
    NotificationData::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NotificationData::typeName(void)
    {
    	return "NotificationData";
    }
    
    OpcUaNodeId
    NotificationData::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)945,0);
    }
    
    OpcUaNodeId
    NotificationData::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)947, 0);
    }
    
    OpcUaNodeId
    NotificationData::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)946, 0);
    }
    
    OpcUaNodeId
    NotificationData::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15344, 0);
    }
    
    void
    NotificationData::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    NotificationData::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    NotificationData::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "NotificationData encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NotificationData::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    NotificationData::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationData decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NotificationData::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    NotificationData::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    NotificationData::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    NotificationData::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NotificationData* dst = dynamic_cast<NotificationData*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NotificationData::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NotificationData* dst = dynamic_cast<NotificationData*>(&extensionObjectBase);
    	return *const_cast<NotificationData*>(this) == *dst;
    }
    
    void
    NotificationData::out(std::ostream& os)
    {
    }

}
