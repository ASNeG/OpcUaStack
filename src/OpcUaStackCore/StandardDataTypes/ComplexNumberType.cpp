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
    ComplexNumberType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ComplexNumberType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if(!XmlNumber::xmlEncode(elementTree, real_)) return false;
        pt.push_back(std::make_pair("Real", elementTree));
    
        if(!XmlNumber::xmlEncode(elementTree, imaginary_)) return false;
        pt.push_back(std::make_pair("Imaginary", elementTree));
    
        return true;
    }
    
    bool
    ComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Real");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, real_)) return false;
    
        tree = pt.get_child_optional("Imaginary");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, imaginary_)) return false;
    
        return true;
    }
    
    bool
    ComplexNumberType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ComplexNumberType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ComplexNumberType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ComplexNumberType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
