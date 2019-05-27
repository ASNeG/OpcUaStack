/*
    DataTypeClass: ModificationInfo

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ModificationInfo.h"

namespace OpcUaStackCore
{
    
    ModificationInfo::ModificationInfo(void)
    : Object()
    , ExtensionObjectBase()
    , modificationTime_()
    , updateType_()
    , userName_()
    {
    }
    
    ModificationInfo::ModificationInfo(const ModificationInfo& value)
    : Object()
    , ExtensionObjectBase()
    , modificationTime_()
    , updateType_()
    , userName_()
    {
        const_cast<ModificationInfo*>(&value)->copyTo(*this);
    }
    
    ModificationInfo::~ModificationInfo(void)
    {
    }
    
    OpcUaUtcTime&
    ModificationInfo::modificationTime(void)
    {
        return modificationTime_;
    }
    
    HistoryUpdateType&
    ModificationInfo::updateType(void)
    {
        return updateType_;
    }
    
    OpcUaString&
    ModificationInfo::userName(void)
    {
        return userName_;
    }
    
    bool
    ModificationInfo::operator==(const ModificationInfo& value)
    {
        ModificationInfo* dst = const_cast<ModificationInfo*>(&value);
        if (modificationTime_ != dst->modificationTime()) return false;
        if (updateType_ != dst->updateType()) return false;
        if (userName_ != dst->userName()) return false;
        return true;
    }
    
    bool
    ModificationInfo::operator!=(const ModificationInfo& value)
    {
        return !this->operator==(value);
    }
    
    void
    ModificationInfo::copyTo(ModificationInfo& value)
    {
        modificationTime_.copyTo(value.modificationTime());
        updateType_.copyTo(value.updateType());
        userName_.copyTo(value.userName());
    }
    
    ModificationInfo&
    ModificationInfo::operator=(const ModificationInfo& value)
    {
        const_cast<ModificationInfo*>(&value)->copyTo(*this);
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
    ModificationInfo::factory(void)
    {
    	return constructSPtr<ModificationInfo>();
    }
    
    std::string
    ModificationInfo::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ModificationInfo::typeName(void)
    {
    	return "ModificationInfo";
    }
    
    OpcUaNodeId
    ModificationInfo::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11216,0);
    }
    
    OpcUaNodeId
    ModificationInfo::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11226, 0);
    }
    
    OpcUaNodeId
    ModificationInfo::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11218, 0);
    }
    
    OpcUaNodeId
    ModificationInfo::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15271, 0);
    }
    
    void
    ModificationInfo::opcUaBinaryEncode(std::ostream& os) const
    {
        modificationTime_.opcUaBinaryEncode(os);
        updateType_.opcUaBinaryEncode(os);
        userName_.opcUaBinaryEncode(os);
    }
    
    void
    ModificationInfo::opcUaBinaryDecode(std::istream& is)
    {
        modificationTime_.opcUaBinaryDecode(is);
        updateType_.opcUaBinaryDecode(is);
        userName_.opcUaBinaryDecode(is);
    }
    
    bool
    ModificationInfo::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModificationInfo encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ModificationInfo::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!modificationTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModificationInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ModificationTime", elementTree));
    
        elementTree.clear();
        if (!updateType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModificationInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UpdateType", elementTree));
    
        elementTree.clear();
        if (!userName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModificationInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserName", elementTree));
    
        return true;
    }
    
    bool
    ModificationInfo::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ModificationInfo::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ModificationTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modificationTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ModificationInfo decode xml error - decode failed")
                .parameter("Element", "ModificationTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("UpdateType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!updateType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ModificationInfo decode xml error - decode failed")
                .parameter("Element", "UpdateType");
            return false;
        }
    
        elementName = xmlns.addPrefix("UserName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ModificationInfo decode xml error - decode failed")
                .parameter("Element", "UserName");
            return false;
        }
    
        return true;
    }
    
    bool
    ModificationInfo::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!modificationTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ModificationInfo json encoder error")
    		     .parameter("Element", "modificationTime_");
            return false;
        }
        pt.push_back(std::make_pair("ModificationTime", elementTree));
    
        elementTree.clear();
        if (!updateType_.jsonEncode(elementTree))
        {
    	     Log(Error, "ModificationInfo json encoder error")
    		     .parameter("Element", "updateType_");
            return false;
        }
        pt.push_back(std::make_pair("UpdateType", elementTree));
    
        elementTree.clear();
        if (!userName_.jsonEncode(elementTree))
        {
    	     Log(Error, "ModificationInfo json encoder error")
    		     .parameter("Element", "userName_");
            return false;
        }
        pt.push_back(std::make_pair("UserName", elementTree));
    
        return true;
    }
    
    bool
    ModificationInfo::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ModificationTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modificationTime_.jsonDecode(*tree)) {
            Log(Error, "ModificationInfo decode json error - decode failed")
                .parameter("Element", "ModificationTime");
            return false;
        }
    
        elementName = "UpdateType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!updateType_.jsonDecode(*tree)) {
            Log(Error, "ModificationInfo decode json error - decode failed")
                .parameter("Element", "UpdateType");
            return false;
        }
    
        elementName = "UserName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModificationInfo decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userName_.jsonDecode(*tree)) {
            Log(Error, "ModificationInfo decode json error - decode failed")
                .parameter("Element", "UserName");
            return false;
        }
    
        return true;
    }
    
    void
    ModificationInfo::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ModificationInfo* dst = dynamic_cast<ModificationInfo*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ModificationInfo::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ModificationInfo* dst = dynamic_cast<ModificationInfo*>(&extensionObjectBase);
    	return *const_cast<ModificationInfo*>(this) == *dst;
    }
    
    void
    ModificationInfo::out(std::ostream& os)
    {
        os << "ModificationTime="; modificationTime_.out(os);
        os << ", UpdateType="; updateType_.out(os);
        os << ", UserName="; userName_.out(os);
    }

}
