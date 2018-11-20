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
    DoubleComplexNumberType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DoubleComplexNumberType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DoubleComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DoubleComplexNumberType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, real_)) return false;
        pt.push_back(std::make_pair("Real", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, imaginary_)) return false;
        pt.push_back(std::make_pair("Imaginary", elementTree));
    
        return true;
    }
    
    bool
    DoubleComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DoubleComplexNumberType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
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
    DoubleComplexNumberType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DoubleComplexNumberType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DoubleComplexNumberType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DoubleComplexNumberType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
