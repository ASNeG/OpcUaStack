/*
    DataTypeClass: BuildInfo

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{
    
    BuildInfo::BuildInfo(void)
    : Object()
    , ExtensionObjectBase()
    , productUri_()
    , manufacturerName_()
    , productName_()
    , softwareVersion_()
    , buildNumber_()
    , buildDate_()
    {
    }
    
    BuildInfo::BuildInfo(const BuildInfo& value)
    : Object()
    , ExtensionObjectBase()
    , productUri_()
    , manufacturerName_()
    , productName_()
    , softwareVersion_()
    , buildNumber_()
    , buildDate_()
    {
        const_cast<BuildInfo*>(&value)->copyTo(*this);
    }
    
    BuildInfo::~BuildInfo(void)
    {
    }
    
    OpcUaString&
    BuildInfo::productUri(void)
    {
        return productUri_;
    }
    
    OpcUaString&
    BuildInfo::manufacturerName(void)
    {
        return manufacturerName_;
    }
    
    OpcUaString&
    BuildInfo::productName(void)
    {
        return productName_;
    }
    
    OpcUaString&
    BuildInfo::softwareVersion(void)
    {
        return softwareVersion_;
    }
    
    OpcUaString&
    BuildInfo::buildNumber(void)
    {
        return buildNumber_;
    }
    
    OpcUaUtcTime&
    BuildInfo::buildDate(void)
    {
        return buildDate_;
    }
    
    bool
    BuildInfo::operator==(const BuildInfo& value)
    {
        BuildInfo* dst = const_cast<BuildInfo*>(&value);
        if (productUri_ != dst->productUri()) return false;
        if (manufacturerName_ != dst->manufacturerName()) return false;
        if (productName_ != dst->productName()) return false;
        if (softwareVersion_ != dst->softwareVersion()) return false;
        if (buildNumber_ != dst->buildNumber()) return false;
        if (buildDate_ != dst->buildDate()) return false;
        return true;
    }
    
    bool
    BuildInfo::operator!=(const BuildInfo& value)
    {
        return !this->operator==(value);
    }
    
    void
    BuildInfo::copyTo(BuildInfo& value)
    {
        productUri_.copyTo(value.productUri());
        manufacturerName_.copyTo(value.manufacturerName());
        productName_.copyTo(value.productName());
        softwareVersion_.copyTo(value.softwareVersion());
        buildNumber_.copyTo(value.buildNumber());
        buildDate_.copyTo(value.buildDate());
    }
    
    BuildInfo&
    BuildInfo::operator=(const BuildInfo& value)
    {
        const_cast<BuildInfo*>(&value)->copyTo(*this);
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
    BuildInfo::factory(void)
    {
    	return boost::make_shared<BuildInfo>();
    }
    
    std::string
    BuildInfo::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    BuildInfo::typeName(void)
    {
    	return "BuildInfo";
    }
    
    OpcUaNodeId
    BuildInfo::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)338,0);
    }
    
    OpcUaNodeId
    BuildInfo::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)340, 0);
    }
    
    OpcUaNodeId
    BuildInfo::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)339, 0);
    }
    
    OpcUaNodeId
    BuildInfo::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15361, 0);
    }
    
    bool
    BuildInfo::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= productUri_.opcUaBinaryEncode(os);
        rc &= manufacturerName_.opcUaBinaryEncode(os);
        rc &= productName_.opcUaBinaryEncode(os);
        rc &= softwareVersion_.opcUaBinaryEncode(os);
        rc &= buildNumber_.opcUaBinaryEncode(os);
        rc &= buildDate_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    BuildInfo::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= productUri_.opcUaBinaryDecode(is);
        rc &= manufacturerName_.opcUaBinaryDecode(is);
        rc &= productName_.opcUaBinaryDecode(is);
        rc &= softwareVersion_.opcUaBinaryDecode(is);
        rc &= buildNumber_.opcUaBinaryDecode(is);
        rc &= buildDate_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    BuildInfo::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    BuildInfo::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!productUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        elementTree.clear();
        if (!manufacturerName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ManufacturerName", elementTree));
    
        elementTree.clear();
        if (!productName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProductName", elementTree));
    
        elementTree.clear();
        if (!softwareVersion_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SoftwareVersion", elementTree));
    
        elementTree.clear();
        if (!buildNumber_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BuildNumber", elementTree));
    
        elementTree.clear();
        if (!buildDate_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BuildInfo encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BuildDate", elementTree));
    
        return true;
    }
    
    bool
    BuildInfo::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BuildInfo::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ProductUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!productUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BuildInfo decode xml error - decode failed")
                .parameter("Element", "ProductUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("ManufacturerName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!manufacturerName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BuildInfo decode xml error - decode failed")
                .parameter("Element", "ManufacturerName");
            return false;
        }
    
        elementName = xmlns.addPrefix("ProductName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!productName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BuildInfo decode xml error - decode failed")
                .parameter("Element", "ProductName");
            return false;
        }
    
        elementName = xmlns.addPrefix("SoftwareVersion");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!softwareVersion_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BuildInfo decode xml error - decode failed")
                .parameter("Element", "SoftwareVersion");
            return false;
        }
    
        elementName = xmlns.addPrefix("BuildNumber");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!buildNumber_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BuildInfo decode xml error - decode failed")
                .parameter("Element", "BuildNumber");
            return false;
        }
    
        elementName = xmlns.addPrefix("BuildDate");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BuildInfo decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!buildDate_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BuildInfo decode xml error - decode failed")
                .parameter("Element", "BuildDate");
            return false;
        }
    
        return true;
    }
    
    bool
    BuildInfo::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, productUri_, "ProductUri", true);
        rc = rc & jsonObjectEncode(pt, manufacturerName_, "ManufacturerName", true);
        rc = rc & jsonObjectEncode(pt, productName_, "ProductName", true);
        rc = rc & jsonObjectEncode(pt, softwareVersion_, "SoftwareVersion", true);
        rc = rc & jsonObjectEncode(pt, buildNumber_, "BuildNumber", true);
        rc = rc & jsonObjectEncode(pt, buildDate_, "BuildDate", true);
    
        return rc;
    }
    
    bool
    BuildInfo::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, productUri_, "ProductUri", true);
        rc = rc & jsonObjectDecode(pt, manufacturerName_, "ManufacturerName", true);
        rc = rc & jsonObjectDecode(pt, productName_, "ProductName", true);
        rc = rc & jsonObjectDecode(pt, softwareVersion_, "SoftwareVersion", true);
        rc = rc & jsonObjectDecode(pt, buildNumber_, "BuildNumber", true);
        rc = rc & jsonObjectDecode(pt, buildDate_, "BuildDate", true);
    
        return rc;
    }
    
    void
    BuildInfo::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    BuildInfo::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
    	return *const_cast<BuildInfo*>(this) == *dst;
    }
    
    void
    BuildInfo::out(std::ostream& os)
    {
        os << "ProductUri="; productUri_.out(os);
        os << ", ManufacturerName="; manufacturerName_.out(os);
        os << ", ProductName="; productName_.out(os);
        os << ", SoftwareVersion="; softwareVersion_.out(os);
        os << ", BuildNumber="; buildNumber_.out(os);
        os << ", BuildDate="; buildDate_.out(os);
    }

}
