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
    
    Annotation::Annotation(const Annotation& value)
    : Object()
    , ExtensionObjectBase()
    , message_()
    , userName_()
    , annotationTime_()
    {
        const_cast<Annotation*>(&value)->copyTo(*this);
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
    Annotation::operator==(const Annotation& value)
    {
        Annotation* dst = const_cast<Annotation*>(&value);
        if (message_ != dst->message()) return false;
        if (userName_ != dst->userName()) return false;
        if (annotationTime_ != dst->annotationTime()) return false;
        return true;
    }
    
    bool
    Annotation::operator!=(const Annotation& value)
    {
        return !this->operator==(value);
    }
    
    void
    Annotation::copyTo(Annotation& value)
    {
        message_.copyTo(value.message());
        userName_.copyTo(value.userName());
        annotationTime_.copyTo(value.annotationTime());
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
    Annotation::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "Annotation encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    Annotation::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!message_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "Annotation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Message", elementTree));
    
        elementTree.clear();
        if (!userName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "Annotation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserName", elementTree));
    
        elementTree.clear();
        if (!annotationTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "Annotation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AnnotationTime", elementTree));
    
        return true;
    }
    
    bool
    Annotation::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    Annotation::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Message");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!message_.xmlDecode(*tree, xmlns)) {
            Log(Error, "Annotation decode xml error - decode failed")
                .parameter("Element", "Message");
            return false;
        }
    
        elementName = xmlns.addPrefix("UserName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "Annotation decode xml error - decode failed")
                .parameter("Element", "UserName");
            return false;
        }
    
        elementName = xmlns.addPrefix("AnnotationTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!annotationTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "Annotation decode xml error - decode failed")
                .parameter("Element", "AnnotationTime");
            return false;
        }
    
        return true;
    }
    
    bool
    Annotation::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!message_.jsonEncode(elementTree))
        {
    	     Log(Error, "Annotation json encoder error")
    		     .parameter("Element", "message_");
            return false;
        }
        pt.push_back(std::make_pair("Message", elementTree));
    
        elementTree.clear();
        if (!userName_.jsonEncode(elementTree))
        {
    	     Log(Error, "Annotation json encoder error")
    		     .parameter("Element", "userName_");
            return false;
        }
        pt.push_back(std::make_pair("UserName", elementTree));
    
        elementTree.clear();
        if (!annotationTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "Annotation json encoder error")
    		     .parameter("Element", "annotationTime_");
            return false;
        }
        pt.push_back(std::make_pair("AnnotationTime", elementTree));
    
        return true;
    }
    
    bool
    Annotation::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Message";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!message_.jsonDecode(*tree)) {
            Log(Error, "Annotation decode json error - decode failed")
                .parameter("Element", "Message");
            return false;
        }
    
        elementName = "UserName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userName_.jsonDecode(*tree)) {
            Log(Error, "Annotation decode json error - decode failed")
                .parameter("Element", "UserName");
            return false;
        }
    
        elementName = "AnnotationTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Annotation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!annotationTime_.jsonDecode(*tree)) {
            Log(Error, "Annotation decode json error - decode failed")
                .parameter("Element", "AnnotationTime");
            return false;
        }
    
        return true;
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
    	return *const_cast<Annotation*>(this) == *dst;
    }
    
    void
    Annotation::out(std::ostream& os)
    {
        os << "Message="; message_.out(os);
        os << ", UserName="; userName_.out(os);
        os << ", AnnotationTime="; annotationTime_.out(os);
    }

}
