/*
    DataTypeClass: EUInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
    	return boost::make_shared<EUInformation>();
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
    
    bool
    EUInformation::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= namespaceUri_.opcUaBinaryEncode(os);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,unitId_);
        rc &= displayName_.opcUaBinaryEncode(os);
        rc &= description_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    EUInformation::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= namespaceUri_.opcUaBinaryDecode(is);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,unitId_);
        rc &= displayName_.opcUaBinaryDecode(is);
        rc &= description_.opcUaBinaryDecode(is);
        return rc;
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
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, namespaceUri_, "NamespaceUri", true);
        rc = rc & jsonNumberEncode(pt, unitId_, "UnitId");
        rc = rc & jsonObjectEncode(pt, displayName_, "DisplayName", true);
        rc = rc & jsonObjectEncode(pt, description_, "Description", true);
    
        return rc;
    }
    
    bool
    EUInformation::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, namespaceUri_, "NamespaceUri", true);
        rc = rc & jsonNumberDecode(pt, unitId_, "UnitId");
        rc = rc & jsonObjectDecode(pt, displayName_, "DisplayName", true);
        rc = rc & jsonObjectDecode(pt, description_, "Description", true);
    
        return rc;
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
