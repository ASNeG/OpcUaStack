/*
    DataTypeClass: X509IdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/X509IdentityToken.h"

namespace OpcUaStackCore
{
    
    /**
     * A token representing a user identified by an X509 certificate.
     */
    X509IdentityToken::X509IdentityToken(void)
    : UserIdentityToken()
    , certificateData_()
    {
    }
    
    /**
     * A token representing a user identified by an X509 certificate.
     */
    X509IdentityToken::X509IdentityToken(const X509IdentityToken& value)
    : UserIdentityToken()
    , certificateData_()
    {
        const_cast<X509IdentityToken*>(&value)->copyTo(*this);
    }
    
    X509IdentityToken::~X509IdentityToken(void)
    {
    }
    
    OpcUaByteString&
    X509IdentityToken::certificateData(void)
    {
        return certificateData_;
    }
    
    bool
    X509IdentityToken::operator==(const X509IdentityToken& value)
    {
        X509IdentityToken* dst = const_cast<X509IdentityToken*>(&value);
        if (certificateData_ != dst->certificateData()) return false;
        return true;
    }
    
    bool
    X509IdentityToken::operator!=(const X509IdentityToken& value)
    {
        return !this->operator==(value);
    }
    
    void
    X509IdentityToken::copyTo(X509IdentityToken& value)
    {
        certificateData_.copyTo(value.certificateData());
    }
    
    X509IdentityToken&
    X509IdentityToken::operator=(const X509IdentityToken& value)
    {
        const_cast<X509IdentityToken*>(&value)->copyTo(*this);
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
    X509IdentityToken::factory(void)
    {
    	return constructSPtr<X509IdentityToken>();
    }
    
    std::string
    X509IdentityToken::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    X509IdentityToken::typeName(void)
    {
    	return "X509IdentityToken";
    }
    
    OpcUaNodeId
    X509IdentityToken::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)325,0);
    }
    
    OpcUaNodeId
    X509IdentityToken::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)327, 0);
    }
    
    OpcUaNodeId
    X509IdentityToken::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)326, 0);
    }
    
    OpcUaNodeId
    X509IdentityToken::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15143, 0);
    }
    
    void
    X509IdentityToken::opcUaBinaryEncode(std::ostream& os) const
    {
        UserIdentityToken::opcUaBinaryEncode(os);
        certificateData_.opcUaBinaryEncode(os);
    }
    
    void
    X509IdentityToken::opcUaBinaryDecode(std::istream& is)
    {
        UserIdentityToken::opcUaBinaryDecode(is);
        certificateData_.opcUaBinaryDecode(is);
    }
    
    bool
    X509IdentityToken::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "X509IdentityToken encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    X509IdentityToken::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!certificateData_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "X509IdentityToken encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CertificateData", elementTree));
    
        return true;
    }
    
    bool
    X509IdentityToken::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "X509IdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    X509IdentityToken::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("CertificateData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "X509IdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!certificateData_.xmlDecode(*tree, xmlns)) {
            Log(Error, "X509IdentityToken decode xml error - decode failed")
                .parameter("Element", "CertificateData");
            return false;
        }
    
        return true;
    }
    
    bool
    X509IdentityToken::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!certificateData_.jsonEncode(elementTree))
        {
    	     Log(Error, "X509IdentityToken json encoder error")
    		     .parameter("Element", "certificateData_");
            return false;
        }
        pt.push_back(std::make_pair("CertificateData", elementTree));
    
        return true;
    }
    
    bool
    X509IdentityToken::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "CertificateData";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "X509IdentityToken decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!certificateData_.jsonDecode(*tree)) {
            Log(Error, "X509IdentityToken decode json error - decode failed")
                .parameter("Element", "CertificateData");
            return false;
        }
    
        return true;
    }
    
    void
    X509IdentityToken::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	X509IdentityToken* dst = dynamic_cast<X509IdentityToken*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    X509IdentityToken::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	X509IdentityToken* dst = dynamic_cast<X509IdentityToken*>(&extensionObjectBase);
    	return *const_cast<X509IdentityToken*>(this) == *dst;
    }
    
    void
    X509IdentityToken::out(std::ostream& os)
    {
        os << "CertificateData="; certificateData_.out(os);
    }

}
