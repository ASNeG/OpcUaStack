/*
    EnumTypeClass: TrustListMasks

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/TrustListMasks.h"

namespace OpcUaStackCore
{
    
    TrustListMasks::TrustListMasks(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    TrustListMasks::TrustListMasks(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    TrustListMasks::TrustListMasks(TrustListMasks& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    TrustListMasks::~TrustListMasks(void)
    {
    }
    
    int32_t&
    TrustListMasks::value(void)
    {
        return value_;
    }
    
    void
    TrustListMasks::enumeration(TrustListMasks::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    TrustListMasks::Enum
    TrustListMasks::enumeration(void)
    {
        return (Enum)value_;
    }
    
    TrustListMasks::Enum
    TrustListMasks::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "None") return (Enum)0;
        if (enumerationString == "TrustedCertificates") return (Enum)1;
        if (enumerationString == "TrustedCrls") return (Enum)2;
        if (enumerationString == "IssuerCertificates") return (Enum)4;
        if (enumerationString == "IssuerCrls") return (Enum)8;
        if (enumerationString == "All") return (Enum)15;
        return (Enum)0;
    }
    
    std::string
    TrustListMasks::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "None";
        if (enumeration == 1) return "TrustedCertificates";
        if (enumeration == 2) return "TrustedCrls";
        if (enumeration == 4) return "IssuerCertificates";
        if (enumeration == 8) return "IssuerCrls";
        if (enumeration == 15) return "All";
        return "Unknown";
    }
    
    std::string
    TrustListMasks::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    TrustListMasks::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    TrustListMasks::exist(const std::string& enumerationString)
    {
        if (enumerationString == "None") return true;
        if (enumerationString == "TrustedCertificates") return true;
        if (enumerationString == "TrustedCrls") return true;
        if (enumerationString == "IssuerCertificates") return true;
        if (enumerationString == "IssuerCrls") return true;
        if (enumerationString == "All") return true;
        return false;
    }
    
    bool
    TrustListMasks::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 4) return true;
        if (enumeration == 8) return true;
        if (enumeration == 15) return true;
        return false;
    }
    
    bool
    TrustListMasks::operator==(const TrustListMasks& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    TrustListMasks::operator!=(const TrustListMasks& value) const
    {
        return !this->operator==(value);
    }
    
    TrustListMasks&
    TrustListMasks::operator=(const TrustListMasks& value)
    {
        value_ = const_cast<TrustListMasks&>(value).value();
        return *this;
    }
    
    TrustListMasks&
    TrustListMasks::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    TrustListMasks::copyTo(TrustListMasks& value)
    {
        value.value_ = value_;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    TrustListMasks::factory(void)
    {
    	return constructSPtr<TrustListMasks>();
    }
    
    OpcUaNodeId
    TrustListMasks::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    TrustListMasks::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    TrustListMasks::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    TrustListMasks::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    TrustListMasks::typeName(void)
    {
    	return "TrustListMasks";
    }
    
    OpcUaNodeId
    TrustListMasks::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12552,0);
    }
    
    void
    TrustListMasks::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    TrustListMasks::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    TrustListMasks::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "TrustListMasks json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    TrustListMasks::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "TrustListMasks json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    TrustListMasks::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "TrustListMasks json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    TrustListMasks::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "TrustListMasks json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    TrustListMasks::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "TrustListMasks json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    TrustListMasks::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "TrustListMasks decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    TrustListMasks::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	TrustListMasks* dst = dynamic_cast<TrustListMasks*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    TrustListMasks::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	TrustListMasks* dst = dynamic_cast<TrustListMasks*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    TrustListMasks::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
