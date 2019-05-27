/*
    DataTypeClass: DataTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataTypeAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a data type node.
     */
    DataTypeAttributes::DataTypeAttributes(void)
    : NodeAttributes()
    , isAbstract_()
    {
    }
    
    /**
     * The attributes for a data type node.
     */
    DataTypeAttributes::DataTypeAttributes(const DataTypeAttributes& value)
    : NodeAttributes()
    , isAbstract_()
    {
        const_cast<DataTypeAttributes*>(&value)->copyTo(*this);
    }
    
    DataTypeAttributes::~DataTypeAttributes(void)
    {
    }
    
    OpcUaBoolean&
    DataTypeAttributes::isAbstract(void)
    {
        return isAbstract_;
    }
    
    bool
    DataTypeAttributes::operator==(const DataTypeAttributes& value)
    {
        DataTypeAttributes* dst = const_cast<DataTypeAttributes*>(&value);
        if (isAbstract_ != dst->isAbstract()) return false;
        return true;
    }
    
    bool
    DataTypeAttributes::operator!=(const DataTypeAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataTypeAttributes::copyTo(DataTypeAttributes& value)
    {
        value.isAbstract_ = isAbstract_;
    }
    
    DataTypeAttributes&
    DataTypeAttributes::operator=(const DataTypeAttributes& value)
    {
        const_cast<DataTypeAttributes*>(&value)->copyTo(*this);
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
    DataTypeAttributes::factory(void)
    {
    	return constructSPtr<DataTypeAttributes>();
    }
    
    std::string
    DataTypeAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataTypeAttributes::typeName(void)
    {
    	return "DataTypeAttributes";
    }
    
    OpcUaNodeId
    DataTypeAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)370,0);
    }
    
    OpcUaNodeId
    DataTypeAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)372, 0);
    }
    
    OpcUaNodeId
    DataTypeAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)371, 0);
    }
    
    OpcUaNodeId
    DataTypeAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15161, 0);
    }
    
    void
    DataTypeAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isAbstract_);
    }
    
    void
    DataTypeAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isAbstract_);
    }
    
    bool
    DataTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataTypeAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isAbstract_))
        {
            Log(Error, "DataTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    DataTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("IsAbstract");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isAbstract_)) {
            Log(Error, "DataTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DataTypeAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isAbstract_))
        {
    	     Log(Error, "DataTypeAttributes json encoder error")
    		     .parameter("Element", "isAbstract_");
           return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    DataTypeAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "IsAbstract";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isAbstract_)) {
            Log(Error, "DataTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DataTypeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataTypeAttributes* dst = dynamic_cast<DataTypeAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataTypeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataTypeAttributes* dst = dynamic_cast<DataTypeAttributes*>(&extensionObjectBase);
    	return *const_cast<DataTypeAttributes*>(this) == *dst;
    }
    
    void
    DataTypeAttributes::out(std::ostream& os)
    {
        os << "IsAbstract=" << isAbstract_;
    }

}
