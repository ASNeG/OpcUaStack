/*
    DataTypeClass: TrustListDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/TrustListDataType.h"

namespace OpcUaStackCore
{
    
    TrustListDataType::TrustListDataType(void)
    : Object()
    , ExtensionObjectBase()
    , specifiedLists_()
    , trustedCertificates_()
    , trustedCrls_()
    , issuerCertificates_()
    , issuerCrls_()
    {
    }
    
    TrustListDataType::TrustListDataType(const TrustListDataType& value)
    : Object()
    , ExtensionObjectBase()
    , specifiedLists_()
    , trustedCertificates_()
    , trustedCrls_()
    , issuerCertificates_()
    , issuerCrls_()
    {
        const_cast<TrustListDataType*>(&value)->copyTo(*this);
    }
    
    TrustListDataType::~TrustListDataType(void)
    {
    }
    
    OpcUaUInt32&
    TrustListDataType::specifiedLists(void)
    {
        return specifiedLists_;
    }
    
    OpcUaByteStringArray&
    TrustListDataType::trustedCertificates(void)
    {
        return trustedCertificates_;
    }
    
    OpcUaByteStringArray&
    TrustListDataType::trustedCrls(void)
    {
        return trustedCrls_;
    }
    
    OpcUaByteStringArray&
    TrustListDataType::issuerCertificates(void)
    {
        return issuerCertificates_;
    }
    
    OpcUaByteStringArray&
    TrustListDataType::issuerCrls(void)
    {
        return issuerCrls_;
    }
    
    bool
    TrustListDataType::operator==(const TrustListDataType& value)
    {
        TrustListDataType* dst = const_cast<TrustListDataType*>(&value);
        if (specifiedLists_ != dst->specifiedLists()) return false;
        if (trustedCertificates_ != dst->trustedCertificates()) return false;
        if (trustedCrls_ != dst->trustedCrls()) return false;
        if (issuerCertificates_ != dst->issuerCertificates()) return false;
        if (issuerCrls_ != dst->issuerCrls()) return false;
        return true;
    }
    
    bool
    TrustListDataType::operator!=(const TrustListDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    TrustListDataType::copyTo(TrustListDataType& value)
    {
        value.specifiedLists_ = specifiedLists_;
        trustedCertificates_.copyTo(value.trustedCertificates());
        trustedCrls_.copyTo(value.trustedCrls());
        issuerCertificates_.copyTo(value.issuerCertificates());
        issuerCrls_.copyTo(value.issuerCrls());
    }
    
    TrustListDataType&
    TrustListDataType::operator=(const TrustListDataType& value)
    {
        const_cast<TrustListDataType*>(&value)->copyTo(*this);
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
    TrustListDataType::factory(void)
    {
    	return constructSPtr<TrustListDataType>();
    }
    
    std::string
    TrustListDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    TrustListDataType::typeName(void)
    {
    	return "TrustListDataType";
    }
    
    OpcUaNodeId
    TrustListDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12554,0);
    }
    
    OpcUaNodeId
    TrustListDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12680, 0);
    }
    
    OpcUaNodeId
    TrustListDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12676, 0);
    }
    
    OpcUaNodeId
    TrustListDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15044, 0);
    }
    
    void
    TrustListDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,specifiedLists_);
        trustedCertificates_.opcUaBinaryEncode(os);
        trustedCrls_.opcUaBinaryEncode(os);
        issuerCertificates_.opcUaBinaryEncode(os);
        issuerCrls_.opcUaBinaryEncode(os);
    }
    
    void
    TrustListDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,specifiedLists_);
        trustedCertificates_.opcUaBinaryDecode(is);
        trustedCrls_.opcUaBinaryDecode(is);
        issuerCertificates_.opcUaBinaryDecode(is);
        issuerCrls_.opcUaBinaryDecode(is);
    }
    
    bool
    TrustListDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "TrustListDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    TrustListDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, specifiedLists_))
        {
            Log(Error, "TrustListDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SpecifiedLists", elementTree));
    
        elementTree.clear();
        if (!trustedCertificates_.xmlEncode(elementTree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TrustedCertificates", elementTree));
    
        elementTree.clear();
        if (!trustedCrls_.xmlEncode(elementTree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TrustedCrls", elementTree));
    
        elementTree.clear();
        if (!issuerCertificates_.xmlEncode(elementTree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IssuerCertificates", elementTree));
    
        elementTree.clear();
        if (!issuerCrls_.xmlEncode(elementTree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IssuerCrls", elementTree));
    
        return true;
    }
    
    bool
    TrustListDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    TrustListDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SpecifiedLists");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, specifiedLists_)) {
            Log(Error, "TrustListDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TrustedCertificates");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!trustedCertificates_.xmlDecode(*tree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TrustedCrls");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!trustedCrls_.xmlDecode(*tree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IssuerCertificates");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!issuerCertificates_.xmlDecode(*tree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IssuerCrls");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!issuerCrls_.xmlDecode(*tree, "ByteString", xmlns)) {
            Log(Error, "TrustListDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    TrustListDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, specifiedLists_))
        {
    	     Log(Error, "TrustListDataType json encoder error")
    		     .parameter("Element", "specifiedLists_");
           return false;
        }
        pt.push_back(std::make_pair("SpecifiedLists", elementTree));
    
        elementTree.clear();
        if (!trustedCertificates_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "TrustListDataType json encoder error")
    		     .parameter("Element", "trustedCertificates_");
            return false;
        }
        pt.push_back(std::make_pair("TrustedCertificates", elementTree));
    
        elementTree.clear();
        if (!trustedCrls_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "TrustListDataType json encoder error")
    		     .parameter("Element", "trustedCrls_");
            return false;
        }
        pt.push_back(std::make_pair("TrustedCrls", elementTree));
    
        elementTree.clear();
        if (!issuerCertificates_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "TrustListDataType json encoder error")
    		     .parameter("Element", "issuerCertificates_");
            return false;
        }
        pt.push_back(std::make_pair("IssuerCertificates", elementTree));
    
        elementTree.clear();
        if (!issuerCrls_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "TrustListDataType json encoder error")
    		     .parameter("Element", "issuerCrls_");
            return false;
        }
        pt.push_back(std::make_pair("IssuerCrls", elementTree));
    
        return true;
    }
    
    bool
    TrustListDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SpecifiedLists";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, specifiedLists_)) {
            Log(Error, "TrustListDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TrustedCertificates";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!trustedCertificates_.jsonDecode(*tree, "")) {
            Log(Error, "TrustListDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TrustedCrls";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!trustedCrls_.jsonDecode(*tree, "")) {
            Log(Error, "TrustListDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IssuerCertificates";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!issuerCertificates_.jsonDecode(*tree, "")) {
            Log(Error, "TrustListDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IssuerCrls";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TrustListDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!issuerCrls_.jsonDecode(*tree, "")) {
            Log(Error, "TrustListDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    TrustListDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	TrustListDataType* dst = dynamic_cast<TrustListDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    TrustListDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	TrustListDataType* dst = dynamic_cast<TrustListDataType*>(&extensionObjectBase);
    	return *const_cast<TrustListDataType*>(this) == *dst;
    }
    
    void
    TrustListDataType::out(std::ostream& os)
    {
        os << "SpecifiedLists=" << specifiedLists_;
        os << ", TrustedCertificates="; trustedCertificates_.out(os);
        os << ", TrustedCrls="; trustedCrls_.out(os);
        os << ", IssuerCertificates="; issuerCertificates_.out(os);
        os << ", IssuerCrls="; issuerCrls_.out(os);
    }

}
