/*
    DataTypeClass: Annotation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/Annotation.h"

namespace OpcUaStackCore
{
    
    Annotation::Annotation(void)
    : Object()
    , ExtensionObjectBase()
    , message_()
    , userName_()
    , annotationTime_()
    {
    }
    
    Annotation::~Annotation(void)
    {
    }
    
    OpcUaString&
    Annotation::message(void)
    {
        return message_;
    }
    
    OpcUaString&
    Annotation::userName(void)
    {
        return userName_;
    }
    
    OpcUaUtcTime&
    Annotation::annotationTime(void)
    {
        return annotationTime_;
    }
    
    bool
    Annotation::operator==(const Annotation& value) const
    {
        Annotation* dst = const_cast<Annotation*>(&value);
        if (message_ != dst->message()) return false;
        if (userName_ != dst->userName()) return false;
        if (annotationTime_ != dst->annotationTime()) return false;
        return true;
    }
    
    bool
    Annotation::operator!=(const Annotation& value) const
    {
        return !this->operator==(value);
    }
    
    void
    Annotation::copyTo(Annotation& value)
    {
        value.message_ = message_;
        value.userName_ = userName_;
        value.annotationTime_ = annotationTime_;
    }
    
    Annotation&
    Annotation::operator=(const Annotation& value)
    {
        const_cast<Annotation*>(&value)->copyTo(*this);
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
    Annotation::factory(void)
    {
    	return constructSPtr<Annotation>();
    }
    
    std::string
    Annotation::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    Annotation::typeName(void)
    {
    	return "Annotation";
    }
    
    OpcUaNodeId
    Annotation::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)891,0);
    }
    
    OpcUaNodeId
    Annotation::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)893, 0);
    }
    
    OpcUaNodeId
    Annotation::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)892, 0);
    }
    
    OpcUaNodeId
    Annotation::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15382, 0);
    }
    
    void
    Annotation::opcUaBinaryEncode(std::ostream& os) const
    {
        message_.opcUaBinaryEncode(os);
        userName_.opcUaBinaryEncode(os);
        annotationTime_.opcUaBinaryEncode(os);
    }
    
    void
    Annotation::opcUaBinaryDecode(std::istream& is)
    {
        message_.opcUaBinaryDecode(is);
        userName_.opcUaBinaryDecode(is);
        annotationTime_.opcUaBinaryDecode(is);
    }
    
    bool
    Annotation::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    Annotation::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    Annotation::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    Annotation::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if (!message_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Message", elementTree));
    
        if (!userName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("UserName", elementTree));
    
        if (!annotationTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AnnotationTime", elementTree));
    
        return true;
    }
    
    bool
    Annotation::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    Annotation::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Message");
        if (!tree) return false;
        if (!message_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("UserName");
        if (!tree) return false;
        if (!userName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("AnnotationTime");
        if (!tree) return false;
        if (!annotationTime_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    Annotation::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    Annotation::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    Annotation::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    Annotation::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    Annotation::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	Annotation* dst = dynamic_cast<Annotation*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    Annotation::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	Annotation* dst = dynamic_cast<Annotation*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    Annotation::out(std::ostream& os)
    {
        os << "Message="; message_.out(os);
        os << ", UserName="; userName_.out(os);
        os << ", AnnotationTime="; annotationTime_.out(os);
    }

}
