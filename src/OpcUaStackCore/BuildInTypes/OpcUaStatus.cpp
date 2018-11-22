/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"

namespace OpcUaStackCore
{
    
    OpcUaStatus::OpcUaStatus(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    OpcUaStatus::OpcUaStatus(OpcUaStatusCode enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    OpcUaStatus::OpcUaStatus(OpcUaStatus& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    OpcUaStatus::~OpcUaStatus(void)
    {
    }
    
    int32_t&
    OpcUaStatus::value(void)
    {
        return value_;
    }
    
    void
    OpcUaStatus::enumeration(OpcUaStatusCode enumeration)
    {
        value_ = enumeration;
    }
    
    OpcUaStatusCode
    OpcUaStatus::enumeration(void)
    {
        return (OpcUaStatusCode)value_;
    }
    
    OpcUaStatusCode
    OpcUaStatus::str2Enum(const std::string& enumerationString)
    {
    	return (OpcUaStatusCode)OpcUaStatusCodeMap::statusCode(enumerationString);
    }
    
    std::string
    OpcUaStatus::enum2Str(OpcUaStatusCode enumeration)
    {
    	return OpcUaStatusCodeMap::shortString((OpcUaStatusCode)enumeration);
    }
    
    std::string
    OpcUaStatus::enum2Str(void)
    {
        return enum2Str((OpcUaStatusCode)value_);
    }
    
    std::string
    OpcUaStatus::toString(void)
    {
        return enum2Str((OpcUaStatusCode)value_);
    }
    
    bool
    OpcUaStatus::exist(const std::string& enumerationString)
    {
    	return OpcUaStatusCodeMap::exist(enumerationString);
    }
    
    bool
    OpcUaStatus::exist(OpcUaStatusCode enumeration)
    {
    	return OpcUaStatusCodeMap::exist(enumeration);
    }
    
    bool
    OpcUaStatus::operator==(const OpcUaStatus& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    OpcUaStatus::operator!=(const OpcUaStatus& value) const
    {
        return !this->operator==(value);
    }
    
    OpcUaStatus&
    OpcUaStatus::operator=(const OpcUaStatus& value)
    {
        value_ = const_cast<OpcUaStatus&>(value).value();
        return *this;
    }
    
    OpcUaStatus&
    OpcUaStatus::operator=(const OpcUaStatusCode& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    OpcUaStatus::copyTo(OpcUaStatus& value)
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
    OpcUaStatus::factory(void)
    {
    	return constructSPtr<OpcUaStatus>();
    }
    
    OpcUaNodeId
    OpcUaStatus::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    OpcUaStatus::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    OpcUaStatus::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    OpcUaStatus::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    OpcUaStatus::typeName(void)
    {
    	return "OpcUaStatus";
    }
    
    OpcUaNodeId
    OpcUaStatus::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)852,0);
    }
    
    void
    OpcUaStatus::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    OpcUaStatus::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    OpcUaStatus::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    OpcUaStatus::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    OpcUaStatus::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element)) return false;
        return true;
    }
    
    bool
    OpcUaStatus::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, "Int32")) return false;
        return true;
    }
    
    bool
    OpcUaStatus::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    OpcUaStatus::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) return false;
        return true;
    }
    
    bool
    OpcUaStatus::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    OpcUaStatus::jsonEncode(boost::property_tree::ptree& pt)
    {
    }
    
    bool
    OpcUaStatus::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    OpcUaStatus::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    OpcUaStatus::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	OpcUaStatus* dst = dynamic_cast<OpcUaStatus*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    OpcUaStatus::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	OpcUaStatus* dst = dynamic_cast<OpcUaStatus*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    OpcUaStatus::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
