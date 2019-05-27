/*
    DataTypeClass: DoubleComplexNumberType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DoubleComplexNumberType.h"

namespace OpcUaStackCore
{
    
    DoubleComplexNumberType::DoubleComplexNumberType(void)
    : Object()
    , ExtensionObjectBase()
    , real_()
    , imaginary_()
    {
    }
    
    DoubleComplexNumberType::DoubleComplexNumberType(const DoubleComplexNumberType& value)
    : Object()
    , ExtensionObjectBase()
    , real_()
    , imaginary_()
    {
        const_cast<DoubleComplexNumberType*>(&value)->copyTo(*this);
    }
    
    DoubleComplexNumberType::~DoubleComplexNumberType(void)
    {
    }
    
    OpcUaDouble&
    DoubleComplexNumberType::real(void)
    {
        return real_;
    }
    
    OpcUaDouble&
    DoubleComplexNumberType::imaginary(void)
    {
        return imaginary_;
    }
    
    bool
    DoubleComplexNumberType::operator==(const DoubleComplexNumberType& value)
    {
        DoubleComplexNumberType* dst = const_cast<DoubleComplexNumberType*>(&value);
        if (real_ != dst->real()) return false;
        if (imaginary_ != dst->imaginary()) return false;
        return true;
    }
    
    bool
    DoubleComplexNumberType::operator!=(const DoubleComplexNumberType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DoubleComplexNumberType::copyTo(DoubleComplexNumberType& value)
    {
        value.real_ = real_;
        value.imaginary_ = imaginary_;
    }
    
    DoubleComplexNumberType&
    DoubleComplexNumberType::operator=(const DoubleComplexNumberType& value)
    {
        const_cast<DoubleComplexNumberType*>(&value)->copyTo(*this);
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
    DoubleComplexNumberType::factory(void)
    {
    	return constructSPtr<DoubleComplexNumberType>();
    }
    
    std::string
    DoubleComplexNumberType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DoubleComplexNumberType::typeName(void)
    {
    	return "DoubleComplexNumberType";
    }
    
    OpcUaNodeId
    DoubleComplexNumberType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12172,0);
    }
    
    OpcUaNodeId
    DoubleComplexNumberType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12182, 0);
    }
    
    OpcUaNodeId
    DoubleComplexNumberType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12174, 0);
    }
    
    OpcUaNodeId
    DoubleComplexNumberType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15378, 0);
    }
    
    void
    DoubleComplexNumberType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,real_);
        OpcUaNumber::opcUaBinaryEncode(os,imaginary_);
    }
    
    void
    DoubleComplexNumberType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,real_);
        OpcUaNumber::opcUaBinaryDecode(is,imaginary_);
    }
    
    bool
    DoubleComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DoubleComplexNumberType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DoubleComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, real_))
        {
            Log(Error, "DoubleComplexNumberType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Real", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, imaginary_))
        {
            Log(Error, "DoubleComplexNumberType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Imaginary", elementTree));
    
        return true;
    }
    
    bool
    DoubleComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DoubleComplexNumberType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DoubleComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Real");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DoubleComplexNumberType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, real_)) {
            Log(Error, "DoubleComplexNumberType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Imaginary");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DoubleComplexNumberType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, imaginary_)) {
            Log(Error, "DoubleComplexNumberType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DoubleComplexNumberType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, real_))
        {
    	     Log(Error, "DoubleComplexNumberType json encoder error")
    		     .parameter("Element", "real_");
           return false;
        }
        pt.push_back(std::make_pair("Real", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, imaginary_))
        {
    	     Log(Error, "DoubleComplexNumberType json encoder error")
    		     .parameter("Element", "imaginary_");
           return false;
        }
        pt.push_back(std::make_pair("Imaginary", elementTree));
    
        return true;
    }
    
    bool
    DoubleComplexNumberType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Real";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DoubleComplexNumberType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, real_)) {
            Log(Error, "DoubleComplexNumberType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Imaginary";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DoubleComplexNumberType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, imaginary_)) {
            Log(Error, "DoubleComplexNumberType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DoubleComplexNumberType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DoubleComplexNumberType* dst = dynamic_cast<DoubleComplexNumberType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DoubleComplexNumberType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DoubleComplexNumberType* dst = dynamic_cast<DoubleComplexNumberType*>(&extensionObjectBase);
    	return *const_cast<DoubleComplexNumberType*>(this) == *dst;
    }
    
    void
    DoubleComplexNumberType::out(std::ostream& os)
    {
        os << "Real=" << real_;
        os << ", Imaginary=" << imaginary_;
    }

}
