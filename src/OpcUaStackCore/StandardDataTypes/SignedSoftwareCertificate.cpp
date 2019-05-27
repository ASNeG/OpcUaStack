/*
    DataTypeClass: SignedSoftwareCertificate

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SignedSoftwareCertificate.h"

namespace OpcUaStackCore
{
    
    /**
     * A software certificate with a digital signature.
     */
    SignedSoftwareCertificate::SignedSoftwareCertificate(void)
    : Object()
    , ExtensionObjectBase()
    , certificateData_()
    , signature_()
    {
    }
    
    /**
     * A software certificate with a digital signature.
     */
    SignedSoftwareCertificate::SignedSoftwareCertificate(const SignedSoftwareCertificate& value)
    : Object()
    , ExtensionObjectBase()
    , certificateData_()
    , signature_()
    {
        const_cast<SignedSoftwareCertificate*>(&value)->copyTo(*this);
    }
    
    SignedSoftwareCertificate::~SignedSoftwareCertificate(void)
    {
    }
    
    OpcUaByteString&
    SignedSoftwareCertificate::certificateData(void)
    {
        return certificateData_;
    }
    
    OpcUaByteString&
    SignedSoftwareCertificate::signature(void)
    {
        return signature_;
    }
    
    bool
    SignedSoftwareCertificate::operator==(const SignedSoftwareCertificate& value)
    {
        SignedSoftwareCertificate* dst = const_cast<SignedSoftwareCertificate*>(&value);
        if (certificateData_ != dst->certificateData()) return false;
        if (signature_ != dst->signature()) return false;
        return true;
    }
    
    bool
    SignedSoftwareCertificate::operator!=(const SignedSoftwareCertificate& value)
    {
        return !this->operator==(value);
    }
    
    void
    SignedSoftwareCertificate::copyTo(SignedSoftwareCertificate& value)
    {
        certificateData_.copyTo(value.certificateData());
        signature_.copyTo(value.signature());
    }
    
    SignedSoftwareCertificate&
    SignedSoftwareCertificate::operator=(const SignedSoftwareCertificate& value)
    {
        const_cast<SignedSoftwareCertificate*>(&value)->copyTo(*this);
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
    SignedSoftwareCertificate::factory(void)
    {
    	return constructSPtr<SignedSoftwareCertificate>();
    }
    
    std::string
    SignedSoftwareCertificate::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SignedSoftwareCertificate::typeName(void)
    {
    	return "SignedSoftwareCertificate";
    }
    
    OpcUaNodeId
    SignedSoftwareCertificate::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)344,0);
    }
    
    OpcUaNodeId
    SignedSoftwareCertificate::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)346, 0);
    }
    
    OpcUaNodeId
    SignedSoftwareCertificate::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)345, 0);
    }
    
    OpcUaNodeId
    SignedSoftwareCertificate::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15136, 0);
    }
    
    void
    SignedSoftwareCertificate::opcUaBinaryEncode(std::ostream& os) const
    {
        certificateData_.opcUaBinaryEncode(os);
        signature_.opcUaBinaryEncode(os);
    }
    
    void
    SignedSoftwareCertificate::opcUaBinaryDecode(std::istream& is)
    {
        certificateData_.opcUaBinaryDecode(is);
        signature_.opcUaBinaryDecode(is);
    }
    
    bool
    SignedSoftwareCertificate::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SignedSoftwareCertificate encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SignedSoftwareCertificate::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!certificateData_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SignedSoftwareCertificate encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CertificateData", elementTree));
    
        elementTree.clear();
        if (!signature_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SignedSoftwareCertificate encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Signature", elementTree));
    
        return true;
    }
    
    bool
    SignedSoftwareCertificate::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SignedSoftwareCertificate decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SignedSoftwareCertificate::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("CertificateData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SignedSoftwareCertificate decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!certificateData_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SignedSoftwareCertificate decode xml error - decode failed")
                .parameter("Element", "CertificateData");
            return false;
        }
    
        elementName = xmlns.addPrefix("Signature");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SignedSoftwareCertificate decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!signature_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SignedSoftwareCertificate decode xml error - decode failed")
                .parameter("Element", "Signature");
            return false;
        }
    
        return true;
    }
    
    bool
    SignedSoftwareCertificate::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!certificateData_.jsonEncode(elementTree))
        {
    	     Log(Error, "SignedSoftwareCertificate json encoder error")
    		     .parameter("Element", "certificateData_");
            return false;
        }
        pt.push_back(std::make_pair("CertificateData", elementTree));
    
        elementTree.clear();
        if (!signature_.jsonEncode(elementTree))
        {
    	     Log(Error, "SignedSoftwareCertificate json encoder error")
    		     .parameter("Element", "signature_");
            return false;
        }
        pt.push_back(std::make_pair("Signature", elementTree));
    
        return true;
    }
    
    bool
    SignedSoftwareCertificate::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "CertificateData";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SignedSoftwareCertificate decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!certificateData_.jsonDecode(*tree)) {
            Log(Error, "SignedSoftwareCertificate decode json error - decode failed")
                .parameter("Element", "CertificateData");
            return false;
        }
    
        elementName = "Signature";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SignedSoftwareCertificate decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!signature_.jsonDecode(*tree)) {
            Log(Error, "SignedSoftwareCertificate decode json error - decode failed")
                .parameter("Element", "Signature");
            return false;
        }
    
        return true;
    }
    
    void
    SignedSoftwareCertificate::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SignedSoftwareCertificate* dst = dynamic_cast<SignedSoftwareCertificate*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SignedSoftwareCertificate::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SignedSoftwareCertificate* dst = dynamic_cast<SignedSoftwareCertificate*>(&extensionObjectBase);
    	return *const_cast<SignedSoftwareCertificate*>(this) == *dst;
    }
    
    void
    SignedSoftwareCertificate::out(std::ostream& os)
    {
        os << "CertificateData="; certificateData_.out(os);
        os << ", Signature="; signature_.out(os);
    }

}
