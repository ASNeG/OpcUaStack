/*
    DataTypeClass: HistoryReadDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"

namespace OpcUaStackCore
{
    
    HistoryReadDetails::HistoryReadDetails(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    HistoryReadDetails::HistoryReadDetails(const HistoryReadDetails& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<HistoryReadDetails*>(&value)->copyTo(*this);
    }
    
    HistoryReadDetails::~HistoryReadDetails(void)
    {
    }
    
    bool
    HistoryReadDetails::operator==(const HistoryReadDetails& value)
    {
        HistoryReadDetails* dst = const_cast<HistoryReadDetails*>(&value);
        return true;
    }
    
    bool
    HistoryReadDetails::operator!=(const HistoryReadDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    HistoryReadDetails::copyTo(HistoryReadDetails& value)
    {
    }
    
    HistoryReadDetails&
    HistoryReadDetails::operator=(const HistoryReadDetails& value)
    {
        const_cast<HistoryReadDetails*>(&value)->copyTo(*this);
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
    HistoryReadDetails::factory(void)
    {
    	return constructSPtr<HistoryReadDetails>();
    }
    
    std::string
    HistoryReadDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryReadDetails::typeName(void)
    {
    	return "HistoryReadDetails";
    }
    
    OpcUaNodeId
    HistoryReadDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)641,0);
    }
    
    OpcUaNodeId
    HistoryReadDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)643, 0);
    }
    
    OpcUaNodeId
    HistoryReadDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)642, 0);
    }
    
    OpcUaNodeId
    HistoryReadDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15261, 0);
    }
    
    void
    HistoryReadDetails::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    HistoryReadDetails::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    HistoryReadDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryReadDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryReadDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    HistoryReadDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryReadDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryReadDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    HistoryReadDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    HistoryReadDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    HistoryReadDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryReadDetails* dst = dynamic_cast<HistoryReadDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryReadDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryReadDetails* dst = dynamic_cast<HistoryReadDetails*>(&extensionObjectBase);
    	return *const_cast<HistoryReadDetails*>(this) == *dst;
    }
    
    void
    HistoryReadDetails::out(std::ostream& os)
    {
    }

}
