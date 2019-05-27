/*
    DataTypeClass: SubscribedDataSetMirrorDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SubscribedDataSetMirrorDataType.h"

namespace OpcUaStackCore
{
    
    SubscribedDataSetMirrorDataType::SubscribedDataSetMirrorDataType(void)
    : SubscribedDataSetDataType()
    , parentNodeName_()
    , rolePermissions_()
    {
    }
    
    SubscribedDataSetMirrorDataType::SubscribedDataSetMirrorDataType(const SubscribedDataSetMirrorDataType& value)
    : SubscribedDataSetDataType()
    , parentNodeName_()
    , rolePermissions_()
    {
        const_cast<SubscribedDataSetMirrorDataType*>(&value)->copyTo(*this);
    }
    
    SubscribedDataSetMirrorDataType::~SubscribedDataSetMirrorDataType(void)
    {
    }
    
    OpcUaString&
    SubscribedDataSetMirrorDataType::parentNodeName(void)
    {
        return parentNodeName_;
    }
    
    RolePermissionTypeArray&
    SubscribedDataSetMirrorDataType::rolePermissions(void)
    {
        return rolePermissions_;
    }
    
    bool
    SubscribedDataSetMirrorDataType::operator==(const SubscribedDataSetMirrorDataType& value)
    {
        SubscribedDataSetMirrorDataType* dst = const_cast<SubscribedDataSetMirrorDataType*>(&value);
        if (parentNodeName_ != dst->parentNodeName()) return false;
        if (rolePermissions_ != dst->rolePermissions()) return false;
        return true;
    }
    
    bool
    SubscribedDataSetMirrorDataType::operator!=(const SubscribedDataSetMirrorDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    SubscribedDataSetMirrorDataType::copyTo(SubscribedDataSetMirrorDataType& value)
    {
        parentNodeName_.copyTo(value.parentNodeName());
        rolePermissions_.copyTo(value.rolePermissions());
    }
    
    SubscribedDataSetMirrorDataType&
    SubscribedDataSetMirrorDataType::operator=(const SubscribedDataSetMirrorDataType& value)
    {
        const_cast<SubscribedDataSetMirrorDataType*>(&value)->copyTo(*this);
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
    SubscribedDataSetMirrorDataType::factory(void)
    {
    	return constructSPtr<SubscribedDataSetMirrorDataType>();
    }
    
    std::string
    SubscribedDataSetMirrorDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SubscribedDataSetMirrorDataType::typeName(void)
    {
    	return "SubscribedDataSetMirrorDataType";
    }
    
    OpcUaNodeId
    SubscribedDataSetMirrorDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15635,0);
    }
    
    OpcUaNodeId
    SubscribedDataSetMirrorDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15713, 0);
    }
    
    OpcUaNodeId
    SubscribedDataSetMirrorDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16012, 0);
    }
    
    OpcUaNodeId
    SubscribedDataSetMirrorDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16311, 0);
    }
    
    void
    SubscribedDataSetMirrorDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        SubscribedDataSetDataType::opcUaBinaryEncode(os);
        parentNodeName_.opcUaBinaryEncode(os);
        rolePermissions_.opcUaBinaryEncode(os);
    }
    
    void
    SubscribedDataSetMirrorDataType::opcUaBinaryDecode(std::istream& is)
    {
        SubscribedDataSetDataType::opcUaBinaryDecode(is);
        parentNodeName_.opcUaBinaryDecode(is);
        rolePermissions_.opcUaBinaryDecode(is);
    }
    
    bool
    SubscribedDataSetMirrorDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SubscribedDataSetMirrorDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SubscribedDataSetMirrorDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!parentNodeName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SubscribedDataSetMirrorDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ParentNodeName", elementTree));
    
        elementTree.clear();
        if (!rolePermissions_.xmlEncode(elementTree, "RolePermissionType", xmlns)) {
            Log(Error, "SubscribedDataSetMirrorDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RolePermissions", elementTree));
    
        return true;
    }
    
    bool
    SubscribedDataSetMirrorDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscribedDataSetMirrorDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SubscribedDataSetMirrorDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ParentNodeName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscribedDataSetMirrorDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!parentNodeName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SubscribedDataSetMirrorDataType decode xml error - decode failed")
                .parameter("Element", "ParentNodeName");
            return false;
        }
    
        elementName = xmlns.addPrefix("RolePermissions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscribedDataSetMirrorDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!rolePermissions_.xmlDecode(*tree, "RolePermissionType", xmlns)) {
            Log(Error, "SubscribedDataSetMirrorDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    SubscribedDataSetMirrorDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!parentNodeName_.jsonEncode(elementTree))
        {
    	     Log(Error, "SubscribedDataSetMirrorDataType json encoder error")
    		     .parameter("Element", "parentNodeName_");
            return false;
        }
        pt.push_back(std::make_pair("ParentNodeName", elementTree));
    
        elementTree.clear();
        if (!rolePermissions_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "SubscribedDataSetMirrorDataType json encoder error")
    		     .parameter("Element", "rolePermissions_");
            return false;
        }
        pt.push_back(std::make_pair("RolePermissions", elementTree));
    
        return true;
    }
    
    bool
    SubscribedDataSetMirrorDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ParentNodeName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscribedDataSetMirrorDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!parentNodeName_.jsonDecode(*tree)) {
            Log(Error, "SubscribedDataSetMirrorDataType decode json error - decode failed")
                .parameter("Element", "ParentNodeName");
            return false;
        }
    
        elementName = "RolePermissions";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscribedDataSetMirrorDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!rolePermissions_.jsonDecode(*tree, "")) {
            Log(Error, "SubscribedDataSetMirrorDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    SubscribedDataSetMirrorDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SubscribedDataSetMirrorDataType* dst = dynamic_cast<SubscribedDataSetMirrorDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SubscribedDataSetMirrorDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SubscribedDataSetMirrorDataType* dst = dynamic_cast<SubscribedDataSetMirrorDataType*>(&extensionObjectBase);
    	return *const_cast<SubscribedDataSetMirrorDataType*>(this) == *dst;
    }
    
    void
    SubscribedDataSetMirrorDataType::out(std::ostream& os)
    {
        os << "ParentNodeName="; parentNodeName_.out(os);
        os << ", RolePermissions="; rolePermissions_.out(os);
    }

}
