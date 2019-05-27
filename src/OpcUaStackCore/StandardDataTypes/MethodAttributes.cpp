/*
    DataTypeClass: MethodAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MethodAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a method node.
     */
    MethodAttributes::MethodAttributes(void)
    : NodeAttributes()
    , executable_()
    , userExecutable_()
    {
    }
    
    /**
     * The attributes for a method node.
     */
    MethodAttributes::MethodAttributes(const MethodAttributes& value)
    : NodeAttributes()
    , executable_()
    , userExecutable_()
    {
        const_cast<MethodAttributes*>(&value)->copyTo(*this);
    }
    
    MethodAttributes::~MethodAttributes(void)
    {
    }
    
    OpcUaBoolean&
    MethodAttributes::executable(void)
    {
        return executable_;
    }
    
    OpcUaBoolean&
    MethodAttributes::userExecutable(void)
    {
        return userExecutable_;
    }
    
    bool
    MethodAttributes::operator==(const MethodAttributes& value)
    {
        MethodAttributes* dst = const_cast<MethodAttributes*>(&value);
        if (executable_ != dst->executable()) return false;
        if (userExecutable_ != dst->userExecutable()) return false;
        return true;
    }
    
    bool
    MethodAttributes::operator!=(const MethodAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    MethodAttributes::copyTo(MethodAttributes& value)
    {
        value.executable_ = executable_;
        value.userExecutable_ = userExecutable_;
    }
    
    MethodAttributes&
    MethodAttributes::operator=(const MethodAttributes& value)
    {
        const_cast<MethodAttributes*>(&value)->copyTo(*this);
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
    MethodAttributes::factory(void)
    {
    	return constructSPtr<MethodAttributes>();
    }
    
    std::string
    MethodAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MethodAttributes::typeName(void)
    {
    	return "MethodAttributes";
    }
    
    OpcUaNodeId
    MethodAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)358,0);
    }
    
    OpcUaNodeId
    MethodAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)360, 0);
    }
    
    OpcUaNodeId
    MethodAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)359, 0);
    }
    
    OpcUaNodeId
    MethodAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15157, 0);
    }
    
    void
    MethodAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,executable_);
        OpcUaNumber::opcUaBinaryEncode(os,userExecutable_);
    }
    
    void
    MethodAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,executable_);
        OpcUaNumber::opcUaBinaryDecode(is,userExecutable_);
    }
    
    bool
    MethodAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "MethodAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MethodAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, executable_))
        {
            Log(Error, "MethodAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Executable", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, userExecutable_))
        {
            Log(Error, "MethodAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserExecutable", elementTree));
    
        return true;
    }
    
    bool
    MethodAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MethodAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MethodAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Executable");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MethodAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, executable_)) {
            Log(Error, "MethodAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UserExecutable");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MethodAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, userExecutable_)) {
            Log(Error, "MethodAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    MethodAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, executable_))
        {
    	     Log(Error, "MethodAttributes json encoder error")
    		     .parameter("Element", "executable_");
           return false;
        }
        pt.push_back(std::make_pair("Executable", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, userExecutable_))
        {
    	     Log(Error, "MethodAttributes json encoder error")
    		     .parameter("Element", "userExecutable_");
           return false;
        }
        pt.push_back(std::make_pair("UserExecutable", elementTree));
    
        return true;
    }
    
    bool
    MethodAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Executable";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MethodAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, executable_)) {
            Log(Error, "MethodAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "UserExecutable";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MethodAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, userExecutable_)) {
            Log(Error, "MethodAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    MethodAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MethodAttributes* dst = dynamic_cast<MethodAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MethodAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MethodAttributes* dst = dynamic_cast<MethodAttributes*>(&extensionObjectBase);
    	return *const_cast<MethodAttributes*>(this) == *dst;
    }
    
    void
    MethodAttributes::out(std::ostream& os)
    {
        os << "Executable=" << executable_;
        os << ", UserExecutable=" << userExecutable_;
    }

}
