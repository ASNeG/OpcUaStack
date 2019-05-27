/*
    DataTypeClass: Union

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/Union.h"

namespace OpcUaStackCore
{
    
    /**
     * This abstract DataType is the base DataType for all union DataTypes.
     */
    Union::Union(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    /**
     * This abstract DataType is the base DataType for all union DataTypes.
     */
    Union::Union(const Union& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<Union*>(&value)->copyTo(*this);
    }
    
    Union::~Union(void)
    {
    }
    
    bool
    Union::operator==(const Union& value)
    {
        Union* dst = const_cast<Union*>(&value);
        return true;
    }
    
    bool
    Union::operator!=(const Union& value)
    {
        return !this->operator==(value);
    }
    
    void
    Union::copyTo(Union& value)
    {
    }
    
    Union&
    Union::operator=(const Union& value)
    {
        const_cast<Union*>(&value)->copyTo(*this);
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
    Union::factory(void)
    {
    	return constructSPtr<Union>();
    }
    
    std::string
    Union::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    Union::typeName(void)
    {
    	return "Union";
    }
    
    OpcUaNodeId
    Union::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12756,0);
    }
    
    OpcUaNodeId
    Union::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12766, 0);
    }
    
    OpcUaNodeId
    Union::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12758, 0);
    }
    
    OpcUaNodeId
    Union::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15085, 0);
    }
    
    void
    Union::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    Union::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    Union::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "Union encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    Union::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    Union::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Union decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    Union::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    Union::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    Union::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    Union::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	Union* dst = dynamic_cast<Union*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    Union::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	Union* dst = dynamic_cast<Union*>(&extensionObjectBase);
    	return *const_cast<Union*>(this) == *dst;
    }
    
    void
    Union::out(std::ostream& os)
    {
    }

}
