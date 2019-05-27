/*
    DataTypeClass: MonitoringFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MonitoringFilter.h"

namespace OpcUaStackCore
{
    
    MonitoringFilter::MonitoringFilter(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    MonitoringFilter::MonitoringFilter(const MonitoringFilter& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<MonitoringFilter*>(&value)->copyTo(*this);
    }
    
    MonitoringFilter::~MonitoringFilter(void)
    {
    }
    
    bool
    MonitoringFilter::operator==(const MonitoringFilter& value)
    {
        MonitoringFilter* dst = const_cast<MonitoringFilter*>(&value);
        return true;
    }
    
    bool
    MonitoringFilter::operator!=(const MonitoringFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    MonitoringFilter::copyTo(MonitoringFilter& value)
    {
    }
    
    MonitoringFilter&
    MonitoringFilter::operator=(const MonitoringFilter& value)
    {
        const_cast<MonitoringFilter*>(&value)->copyTo(*this);
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
    MonitoringFilter::factory(void)
    {
    	return constructSPtr<MonitoringFilter>();
    }
    
    std::string
    MonitoringFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MonitoringFilter::typeName(void)
    {
    	return "MonitoringFilter";
    }
    
    OpcUaNodeId
    MonitoringFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)719,0);
    }
    
    OpcUaNodeId
    MonitoringFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)721, 0);
    }
    
    OpcUaNodeId
    MonitoringFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)720, 0);
    }
    
    OpcUaNodeId
    MonitoringFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15293, 0);
    }
    
    void
    MonitoringFilter::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    MonitoringFilter::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    MonitoringFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "MonitoringFilter encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MonitoringFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    MonitoringFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MonitoringFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MonitoringFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    MonitoringFilter::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    MonitoringFilter::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    MonitoringFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MonitoringFilter* dst = dynamic_cast<MonitoringFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MonitoringFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MonitoringFilter* dst = dynamic_cast<MonitoringFilter*>(&extensionObjectBase);
    	return *const_cast<MonitoringFilter*>(this) == *dst;
    }
    
    void
    MonitoringFilter::out(std::ostream& os)
    {
    }

}
