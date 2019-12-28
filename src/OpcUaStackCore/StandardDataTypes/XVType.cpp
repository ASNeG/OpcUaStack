/*
    DataTypeClass: XVType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/XVType.h"

namespace OpcUaStackCore
{
    
    XVType::XVType(void)
    : Object()
    , ExtensionObjectBase()
    , x_()
    , value_()
    {
    }
    
    XVType::XVType(const XVType& value)
    : Object()
    , ExtensionObjectBase()
    , x_()
    , value_()
    {
        const_cast<XVType*>(&value)->copyTo(*this);
    }
    
    XVType::~XVType(void)
    {
    }
    
    OpcUaDouble&
    XVType::x(void)
    {
        return x_;
    }
    
    OpcUaFloat&
    XVType::value(void)
    {
        return value_;
    }
    
    bool
    XVType::operator==(const XVType& value)
    {
        XVType* dst = const_cast<XVType*>(&value);
        if (x_ != dst->x()) return false;
        if (value_ != dst->value()) return false;
        return true;
    }
    
    bool
    XVType::operator!=(const XVType& value)
    {
        return !this->operator==(value);
    }
    
    void
    XVType::copyTo(XVType& value)
    {
        value.x_ = x_;
        value.value_ = value_;
    }
    
    XVType&
    XVType::operator=(const XVType& value)
    {
        const_cast<XVType*>(&value)->copyTo(*this);
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
    XVType::factory(void)
    {
    	return boost::make_shared<XVType>();
    }
    
    std::string
    XVType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    XVType::typeName(void)
    {
    	return "XVType";
    }
    
    OpcUaNodeId
    XVType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12080,0);
    }
    
    OpcUaNodeId
    XVType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12090, 0);
    }
    
    OpcUaNodeId
    XVType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12082, 0);
    }
    
    OpcUaNodeId
    XVType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15380, 0);
    }
    
    bool
    XVType::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryEncode(os,x_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,value_);
        return rc;
    }
    
    bool
    XVType::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryDecode(is,x_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,value_);
        return rc;
    }
    
    bool
    XVType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "XVType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    XVType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, x_))
        {
            Log(Error, "XVType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("X", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, value_))
        {
            Log(Error, "XVType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    XVType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "XVType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    XVType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("X");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "XVType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, x_)) {
            Log(Error, "XVType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "XVType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, value_)) {
            Log(Error, "XVType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    XVType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonNumberEncode(pt, x_, "X");
        rc = rc & jsonNumberEncode(pt, value_, "Value");
    
        return rc;
    }
    
    bool
    XVType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonNumberDecode(pt, x_, "X");
        rc = rc & jsonNumberDecode(pt, value_, "Value");
    
        return rc;
    }
    
    void
    XVType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	XVType* dst = dynamic_cast<XVType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    XVType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	XVType* dst = dynamic_cast<XVType*>(&extensionObjectBase);
    	return *const_cast<XVType*>(this) == *dst;
    }
    
    void
    XVType::out(std::ostream& os)
    {
        os << "X=" << x_;
        os << ", Value=" << value_;
    }

}
