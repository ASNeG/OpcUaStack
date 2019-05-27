/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <boost/lexical_cast.hpp>
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
    OpcUaStatus::enum2Str(OpcUaStatusCode enumeration) const
    {
    	return OpcUaStatusCodeMap::shortString((OpcUaStatusCode)enumeration);
    }
    
    std::string
    OpcUaStatus::enum2Str(void) const
    {
        return enum2Str((OpcUaStatusCode)value_);
    }
    
    std::string
    OpcUaStatus::toString(void) const
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
    OpcUaStatus::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    	boost::property_tree::ptree treeElement;
        if(!xmlEncode(treeElement, xmlns)) return false;
        pt.add_child(xmlns.addPrefix(element), treeElement);
        return true;
    }
    
    bool
    OpcUaStatus::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    	std::stringstream ss;
    	ss << value_;
    	pt.put(xmlns.addPrefix("Code"), ss.str());
        return true;
    }
    
    bool
    OpcUaStatus::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(xmlns.addPrefix(element));
        if (!tree) {
        	Log(Error, "xml element not exist")
        		.parameter("XmlElement", element);
        	return false;
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    OpcUaStatus::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    	boost::optional<std::string> codeString = pt.get_optional<std::string>(xmlns.addPrefix("Code"));
    	if (!codeString) {
    		codeString = pt.get_optional<std::string>(xmlns.addPrefix("Code"));
    		if (!codeString) {
    			Log(Error, "xml element not exist")
        			.parameter("XmlElement", "Code");
    			return false;
    		}
    	}

		try {
			uint32_t code = boost::lexical_cast<uint32_t>(*codeString);
			value_ = code;
		} catch (boost::bad_lexical_cast&)
		{
	       	Log(Error, "xml element format invalid")
	        	.parameter("XmlElement", "Code")
				.parameter("Content", *codeString);
			return false;
		}

        return true;
    }
    
    
    bool
    OpcUaStatus::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
		// added status
    	pt.put_value(toString());
		return true;
    }
    
    bool
    OpcUaStatus::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
		// get source pico seconds
    	auto sourceValue = pt.get_value<std::string>();
    	enumeration(str2Enum(sourceValue));
		return true;
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
