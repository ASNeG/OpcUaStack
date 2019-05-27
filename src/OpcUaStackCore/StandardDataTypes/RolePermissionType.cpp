/*
    DataTypeClass: RolePermissionType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/RolePermissionType.h"

namespace OpcUaStackCore
{
    
    RolePermissionType::RolePermissionType(void)
    : Object()
    , ExtensionObjectBase()
    , roleId_()
    , permissions_()
    {
    }
    
    RolePermissionType::RolePermissionType(const RolePermissionType& value)
    : Object()
    , ExtensionObjectBase()
    , roleId_()
    , permissions_()
    {
        const_cast<RolePermissionType*>(&value)->copyTo(*this);
    }
    
    RolePermissionType::~RolePermissionType(void)
    {
    }
    
    OpcUaNodeId&
    RolePermissionType::roleId(void)
    {
        return roleId_;
    }
    
    OpcUaPermissionType&
    RolePermissionType::permissions(void)
    {
        return permissions_;
    }
    
    bool
    RolePermissionType::operator==(const RolePermissionType& value)
    {
        RolePermissionType* dst = const_cast<RolePermissionType*>(&value);
        if (roleId_ != dst->roleId()) return false;
        if (permissions_ != dst->permissions()) return false;
        return true;
    }
    
    bool
    RolePermissionType::operator!=(const RolePermissionType& value)
    {
        return !this->operator==(value);
    }
    
    void
    RolePermissionType::copyTo(RolePermissionType& value)
    {
        roleId_.copyTo(value.roleId());
        value.permissions_ = permissions_;
    }
    
    RolePermissionType&
    RolePermissionType::operator=(const RolePermissionType& value)
    {
        const_cast<RolePermissionType*>(&value)->copyTo(*this);
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
    RolePermissionType::factory(void)
    {
    	return constructSPtr<RolePermissionType>();
    }
    
    std::string
    RolePermissionType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    RolePermissionType::typeName(void)
    {
    	return "RolePermissionType";
    }
    
    OpcUaNodeId
    RolePermissionType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)96,0);
    }
    
    OpcUaNodeId
    RolePermissionType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)128, 0);
    }
    
    OpcUaNodeId
    RolePermissionType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16126, 0);
    }
    
    OpcUaNodeId
    RolePermissionType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15062, 0);
    }
    
    void
    RolePermissionType::opcUaBinaryEncode(std::ostream& os) const
    {
        roleId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,permissions_);
    }
    
    void
    RolePermissionType::opcUaBinaryDecode(std::istream& is)
    {
        roleId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,permissions_);
    }
    
    bool
    RolePermissionType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "RolePermissionType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    RolePermissionType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!roleId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RolePermissionType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RoleId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, permissions_))
        {
            Log(Error, "RolePermissionType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Permissions", elementTree));
    
        return true;
    }
    
    bool
    RolePermissionType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RolePermissionType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RolePermissionType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("RoleId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RolePermissionType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!roleId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RolePermissionType decode xml error - decode failed")
                .parameter("Element", "RoleId");
            return false;
        }
    
        elementName = xmlns.addPrefix("Permissions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RolePermissionType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, permissions_)) {
            Log(Error, "RolePermissionType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    RolePermissionType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!roleId_.jsonEncode(elementTree))
        {
    	     Log(Error, "RolePermissionType json encoder error")
    		     .parameter("Element", "roleId_");
            return false;
        }
        pt.push_back(std::make_pair("RoleId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, permissions_))
        {
    	     Log(Error, "RolePermissionType json encoder error")
    		     .parameter("Element", "permissions_");
           return false;
        }
        pt.push_back(std::make_pair("Permissions", elementTree));
    
        return true;
    }
    
    bool
    RolePermissionType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "RoleId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RolePermissionType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!roleId_.jsonDecode(*tree)) {
            Log(Error, "RolePermissionType decode json error - decode failed")
                .parameter("Element", "RoleId");
            return false;
        }
    
        elementName = "Permissions";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RolePermissionType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, permissions_)) {
            Log(Error, "RolePermissionType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    RolePermissionType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	RolePermissionType* dst = dynamic_cast<RolePermissionType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    RolePermissionType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	RolePermissionType* dst = dynamic_cast<RolePermissionType*>(&extensionObjectBase);
    	return *const_cast<RolePermissionType*>(this) == *dst;
    }
    
    void
    RolePermissionType::out(std::ostream& os)
    {
        os << "RoleId="; roleId_.out(os);
        os << ", Permissions=" << permissions_;
    }

}
