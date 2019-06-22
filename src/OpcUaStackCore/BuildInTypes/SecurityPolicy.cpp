/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/BuildInTypes/SecurityPolicy.h"

namespace OpcUaStackCore
{
    
    SecurityPolicy::SecurityPolicy(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    SecurityPolicy::SecurityPolicy(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    SecurityPolicy::SecurityPolicy(SecurityPolicy& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    SecurityPolicy::~SecurityPolicy(void)
    {
    }
    
    int32_t&
    SecurityPolicy::value(void)
    {
        return value_;
    }
    
    void
    SecurityPolicy::enumeration(SecurityPolicy::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    SecurityPolicy::Enum
    SecurityPolicy::enumeration(void)
    {
        return (Enum)value_;
    }
    
    SecurityPolicy::Enum
    SecurityPolicy::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#None") return (Enum)0;
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15") return (Enum)1;
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#Basic256") return (Enum)2;
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256") return (Enum)3;
        return (Enum)0;
    }

    std::string
    SecurityPolicy::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "http://opcfoundation.org/UA/SecurityPolicy#None";
        if (enumeration == 1) return "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15";
        if (enumeration == 2) return "http://opcfoundation.org/UA/SecurityPolicy#Basic256";
        if (enumeration == 3) return "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256";
        return "Unknown";
    }
    
    std::string
    SecurityPolicy::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    SecurityPolicy::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    SecurityPolicy::exist(const std::string& enumerationString)
    {
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#None") return true;
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15") return true;
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#Basic256") return true;
        if (enumerationString == "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256") return true;
        return false;
    }
    
    bool
    SecurityPolicy::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    SecurityPolicy::operator==(const SecurityPolicy& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    SecurityPolicy::operator!=(const SecurityPolicy& value) const
    {
        return !this->operator==(value);
    }
    
    SecurityPolicy&
    SecurityPolicy::operator=(const SecurityPolicy& value)
    {
        value_ = const_cast<SecurityPolicy&>(value).value();
        return *this;
    }
    
    SecurityPolicy&
    SecurityPolicy::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    SecurityPolicy::copyTo(SecurityPolicy& value)
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
    SecurityPolicy::factory(void)
    {
    	return constructSPtr<SecurityPolicy>();
    }
    
    OpcUaNodeId
    SecurityPolicy::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    SecurityPolicy::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    SecurityPolicy::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    SecurityPolicy::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SecurityPolicy::typeName(void)
    {
    	return "SecurityPolicy";
    }
    
    OpcUaNodeId
    SecurityPolicy::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)302,0);
    }
    
    void
    SecurityPolicy::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    SecurityPolicy::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    SecurityPolicy::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "SecurityPolicy json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    SecurityPolicy::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "SecurityPolicy json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    SecurityPolicy::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "SecurityPolicy json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SecurityPolicy::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "SecurityPolicy json decoder error");
            return false;
        }
        return true;
    }

    bool
    SecurityPolicy::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "SecurityPolicy json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    SecurityPolicy::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "SecurityPolicy decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    SecurityPolicy::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SecurityPolicy* dst = dynamic_cast<SecurityPolicy*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SecurityPolicy::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SecurityPolicy* dst = dynamic_cast<SecurityPolicy*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    SecurityPolicy::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
