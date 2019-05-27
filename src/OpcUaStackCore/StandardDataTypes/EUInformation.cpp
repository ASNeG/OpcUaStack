/*
    DataTypeClass: EUInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EUInformation.h"

namespace OpcUaStackCore
{
    
    EUInformation::EUInformation(void)
    : Object()
    , ExtensionObjectBase()
    , namespaceUri_()
    , unitId_()
    , displayName_()
    , description_()
    {
    }
    
    EUInformation::EUInformation(const EUInformation& value)
    : Object()
    , ExtensionObjectBase()
    , namespaceUri_()
    , unitId_()
    , displayName_()
    , description_()
    {
        const_cast<EUInformation*>(&value)->copyTo(*this);
    }
    
    EUInformation::~EUInformation(void)
    {
    }
    
    OpcUaString&
    EUInformation::namespaceUri(void)
    {
        return namespaceUri_;
    }
    
    OpcUaInt32&
    EUInformation::unitId(void)
    {
        return unitId_;
    }
    
    OpcUaLocalizedText&
    EUInformation::displayName(void)
    {
        return displayName_;
    }
    
    OpcUaLocalizedText&
    EUInformation::description(void)
    {
        return description_;
    }
    
    bool
    EUInformation::operator==(const EUInformation& value)
    {
        EUInformation* dst = const_cast<EUInformation*>(&value);
        if (namespaceUri_ != dst->namespaceUri()) return false;
        if (unitId_ != dst->unitId()) return false;
        if (displayName_ != dst->displayName()) return false;
        if (description_ != dst->description()) return false;
        return true;
    }
    
    bool
    EUInformation::operator!=(const EUInformation& value)
    {
        return !this->operator==(value);
    }
    
    void
    EUInformation::copyTo(EUInformation& value)
    {
        namespaceUri_.copyTo(value.namespaceUri());
        value.unitId_ = unitId_;
        displayName_.copyTo(value.displayName());
        description_.copyTo(value.description());
    }
    
    EUInformation&
    EUInformation::operator=(const EUInformation& value)
    {
        const_cast<EUInformation*>(&value)->copyTo(*this);
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
    EUInformation::factory(void)
    {
    	return constructSPtr<EUInformation>();
    }
    
    std::string
    EUInformation::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EUInformation::typeName(void)
    {
    	return "EUInformation";
    }
    
    OpcUaNodeId
    EUInformation::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)887,0);
    }
    
    OpcUaNodeId
    EUInformation::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)889, 0);
    }
    
    OpcUaNodeId
    EUInformation::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)888, 0);
    }
    
    OpcUaNodeId
    EUInformation::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15376, 0);
    }
    
    void
    EUInformation::opcUaBinaryEncode(std::ostream& os) const
    {
        namespaceUri_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,unitId_);
        displayName_.opcUaBinaryEncode(os);
        description_.opcUaBinaryEncode(os);
    }
    
    void
    EUInformation::opcUaBinaryDecode(std::istream& is)
    {
        namespaceUri_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,unitId_);
        displayName_.opcUaBinaryDecode(is);
        description_.opcUaBinaryDecode(is);
    }
    
    bool
    EUInformation::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EUInformation encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EUInformation::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!namespaceUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EUInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NamespaceUri", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, unitId_))
        {
            Log(Error, "EUInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UnitId", elementTree));
    
        elementTree.clear();
        if (!displayName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EUInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EUInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    EUInformation::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EUInformation::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NamespaceUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!namespaceUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EUInformation decode xml error - decode failed")
                .parameter("Element", "NamespaceUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("UnitId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, unitId_)) {
            Log(Error, "EUInformation decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DisplayName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!displayName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EUInformation decode xml error - decode failed")
                .parameter("Element", "DisplayName");
            return false;
        }
    
        elementName = xmlns.addPrefix("Description");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EUInformation decode xml error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        return true;
    }
    
    bool
    EUInformation::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!namespaceUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "EUInformation json encoder error")
    		     .parameter("Element", "namespaceUri_");
            return false;
        }
        pt.push_back(std::make_pair("NamespaceUri", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, unitId_))
        {
    	     Log(Error, "EUInformation json encoder error")
    		     .parameter("Element", "unitId_");
           return false;
        }
        pt.push_back(std::make_pair("UnitId", elementTree));
    
        elementTree.clear();
        if (!displayName_.jsonEncode(elementTree))
        {
    	     Log(Error, "EUInformation json encoder error")
    		     .parameter("Element", "displayName_");
            return false;
        }
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.jsonEncode(elementTree))
        {
    	     Log(Error, "EUInformation json encoder error")
    		     .parameter("Element", "description_");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    EUInformation::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NamespaceUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!namespaceUri_.jsonDecode(*tree)) {
            Log(Error, "EUInformation decode json error - decode failed")
                .parameter("Element", "NamespaceUri");
            return false;
        }
    
        elementName = "UnitId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, unitId_)) {
            Log(Error, "EUInformation decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DisplayName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!displayName_.jsonDecode(*tree)) {
            Log(Error, "EUInformation decode json error - decode failed")
                .parameter("Element", "DisplayName");
            return false;
        }
    
        elementName = "Description";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EUInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.jsonDecode(*tree)) {
            Log(Error, "EUInformation decode json error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        return true;
    }
    
    void
    EUInformation::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EUInformation* dst = dynamic_cast<EUInformation*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EUInformation::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EUInformation* dst = dynamic_cast<EUInformation*>(&extensionObjectBase);
    	return *const_cast<EUInformation*>(this) == *dst;
    }
    
    void
    EUInformation::out(std::ostream& os)
    {
        os << "NamespaceUri="; namespaceUri_.out(os);
        os << ", UnitId=" << unitId_;
        os << ", DisplayName="; displayName_.out(os);
        os << ", Description="; description_.out(os);
    }

}
