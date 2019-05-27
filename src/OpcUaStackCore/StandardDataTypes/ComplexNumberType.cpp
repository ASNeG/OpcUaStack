/*
    DataTypeClass: ComplexNumberType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ComplexNumberType.h"

namespace OpcUaStackCore
{
    
    ComplexNumberType::ComplexNumberType(void)
    : Object()
    , ExtensionObjectBase()
    , real_()
    , imaginary_()
    {
    }
    
    ComplexNumberType::ComplexNumberType(const ComplexNumberType& value)
    : Object()
    , ExtensionObjectBase()
    , real_()
    , imaginary_()
    {
        const_cast<ComplexNumberType*>(&value)->copyTo(*this);
    }
    
    ComplexNumberType::~ComplexNumberType(void)
    {
    }
    
    OpcUaFloat&
    ComplexNumberType::real(void)
    {
        return real_;
    }
    
    OpcUaFloat&
    ComplexNumberType::imaginary(void)
    {
        return imaginary_;
    }
    
    bool
    ComplexNumberType::operator==(const ComplexNumberType& value)
    {
        ComplexNumberType* dst = const_cast<ComplexNumberType*>(&value);
        if (real_ != dst->real()) return false;
        if (imaginary_ != dst->imaginary()) return false;
        return true;
    }
    
    bool
    ComplexNumberType::operator!=(const ComplexNumberType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ComplexNumberType::copyTo(ComplexNumberType& value)
    {
        value.real_ = real_;
        value.imaginary_ = imaginary_;
    }
    
    ComplexNumberType&
    ComplexNumberType::operator=(const ComplexNumberType& value)
    {
        const_cast<ComplexNumberType*>(&value)->copyTo(*this);
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
    ComplexNumberType::factory(void)
    {
    	return constructSPtr<ComplexNumberType>();
    }
    
    std::string
    ComplexNumberType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ComplexNumberType::typeName(void)
    {
    	return "ComplexNumberType";
    }
    
    OpcUaNodeId
    ComplexNumberType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12171,0);
    }
    
    OpcUaNodeId
    ComplexNumberType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12181, 0);
    }
    
    OpcUaNodeId
    ComplexNumberType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12173, 0);
    }
    
    OpcUaNodeId
    ComplexNumberType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15377, 0);
    }
    
    void
    ComplexNumberType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,real_);
        OpcUaNumber::opcUaBinaryEncode(os,imaginary_);
    }
    
    void
    ComplexNumberType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,real_);
        OpcUaNumber::opcUaBinaryDecode(is,imaginary_);
    }
    
    bool
    ComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ComplexNumberType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, real_))
        {
            Log(Error, "ComplexNumberType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Real", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, imaginary_))
        {
            Log(Error, "ComplexNumberType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Imaginary", elementTree));
    
        return true;
    }
    
    bool
    ComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ComplexNumberType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Real");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ComplexNumberType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, real_)) {
            Log(Error, "ComplexNumberType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Imaginary");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ComplexNumberType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, imaginary_)) {
            Log(Error, "ComplexNumberType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ComplexNumberType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, real_))
        {
    	     Log(Error, "ComplexNumberType json encoder error")
    		     .parameter("Element", "real_");
           return false;
        }
        pt.push_back(std::make_pair("Real", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, imaginary_))
        {
    	     Log(Error, "ComplexNumberType json encoder error")
    		     .parameter("Element", "imaginary_");
           return false;
        }
        pt.push_back(std::make_pair("Imaginary", elementTree));
    
        return true;
    }
    
    bool
    ComplexNumberType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Real";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ComplexNumberType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, real_)) {
            Log(Error, "ComplexNumberType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Imaginary";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ComplexNumberType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, imaginary_)) {
            Log(Error, "ComplexNumberType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ComplexNumberType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ComplexNumberType* dst = dynamic_cast<ComplexNumberType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ComplexNumberType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ComplexNumberType* dst = dynamic_cast<ComplexNumberType*>(&extensionObjectBase);
    	return *const_cast<ComplexNumberType*>(this) == *dst;
    }
    
    void
    ComplexNumberType::out(std::ostream& os)
    {
        os << "Real=" << real_;
        os << ", Imaginary=" << imaginary_;
    }

}
