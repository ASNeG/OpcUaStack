/*
    DataTypeClass: HistoryUpdateDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateDetails.h"

namespace OpcUaStackCore
{
    
    HistoryUpdateDetails::HistoryUpdateDetails(void)
    : Object()
    , ExtensionObjectBase()
    , nodeId_()
    {
    }
    
    HistoryUpdateDetails::HistoryUpdateDetails(const HistoryUpdateDetails& value)
    : Object()
    , ExtensionObjectBase()
    , nodeId_()
    {
        const_cast<HistoryUpdateDetails*>(&value)->copyTo(*this);
    }
    
    HistoryUpdateDetails::~HistoryUpdateDetails(void)
    {
    }
    
    OpcUaNodeId&
    HistoryUpdateDetails::nodeId(void)
    {
        return nodeId_;
    }
    
    bool
    HistoryUpdateDetails::operator==(const HistoryUpdateDetails& value)
    {
        HistoryUpdateDetails* dst = const_cast<HistoryUpdateDetails*>(&value);
        if (nodeId_ != dst->nodeId()) return false;
        return true;
    }
    
    bool
    HistoryUpdateDetails::operator!=(const HistoryUpdateDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    HistoryUpdateDetails::copyTo(HistoryUpdateDetails& value)
    {
        nodeId_.copyTo(value.nodeId());
    }
    
    HistoryUpdateDetails&
    HistoryUpdateDetails::operator=(const HistoryUpdateDetails& value)
    {
        const_cast<HistoryUpdateDetails*>(&value)->copyTo(*this);
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
    HistoryUpdateDetails::factory(void)
    {
    	return constructSPtr<HistoryUpdateDetails>();
    }
    
    std::string
    HistoryUpdateDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryUpdateDetails::typeName(void)
    {
    	return "HistoryUpdateDetails";
    }
    
    OpcUaNodeId
    HistoryUpdateDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)677,0);
    }
    
    OpcUaNodeId
    HistoryUpdateDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)679, 0);
    }
    
    OpcUaNodeId
    HistoryUpdateDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)678, 0);
    }
    
    OpcUaNodeId
    HistoryUpdateDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15279, 0);
    }
    
    void
    HistoryUpdateDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        nodeId_.opcUaBinaryEncode(os);
    }
    
    void
    HistoryUpdateDetails::opcUaBinaryDecode(std::istream& is)
    {
        nodeId_.opcUaBinaryDecode(is);
    }
    
    bool
    HistoryUpdateDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryUpdateDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryUpdateDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!nodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryUpdateDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NodeId", elementTree));
    
        return true;
    }
    
    bool
    HistoryUpdateDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryUpdateDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryUpdateDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryUpdateDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!nodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "HistoryUpdateDetails decode xml error - decode failed")
                .parameter("Element", "NodeId");
            return false;
        }
    
        return true;
    }
    
    bool
    HistoryUpdateDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!nodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "HistoryUpdateDetails json encoder error")
    		     .parameter("Element", "nodeId_");
            return false;
        }
        pt.push_back(std::make_pair("NodeId", elementTree));
    
        return true;
    }
    
    bool
    HistoryUpdateDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryUpdateDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!nodeId_.jsonDecode(*tree)) {
            Log(Error, "HistoryUpdateDetails decode json error - decode failed")
                .parameter("Element", "NodeId");
            return false;
        }
    
        return true;
    }
    
    void
    HistoryUpdateDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryUpdateDetails* dst = dynamic_cast<HistoryUpdateDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryUpdateDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryUpdateDetails* dst = dynamic_cast<HistoryUpdateDetails*>(&extensionObjectBase);
    	return *const_cast<HistoryUpdateDetails*>(this) == *dst;
    }
    
    void
    HistoryUpdateDetails::out(std::ostream& os)
    {
        os << "NodeId="; nodeId_.out(os);
    }

}
