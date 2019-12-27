/*
    DataTypeClass: RelativePathElement

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/RelativePathElement.h"

namespace OpcUaStackCore
{
    
    /**
     * An element in a relative path.
     */
    RelativePathElement::RelativePathElement(void)
    : Object()
    , ExtensionObjectBase()
    , referenceTypeId_()
    , isInverse_()
    , includeSubtypes_()
    , targetName_()
    {
    }
    
    /**
     * An element in a relative path.
     */
    RelativePathElement::RelativePathElement(const RelativePathElement& value)
    : Object()
    , ExtensionObjectBase()
    , referenceTypeId_()
    , isInverse_()
    , includeSubtypes_()
    , targetName_()
    {
        const_cast<RelativePathElement*>(&value)->copyTo(*this);
    }
    
    RelativePathElement::~RelativePathElement(void)
    {
    }
    
    OpcUaNodeId&
    RelativePathElement::referenceTypeId(void)
    {
        return referenceTypeId_;
    }
    
    OpcUaBoolean&
    RelativePathElement::isInverse(void)
    {
        return isInverse_;
    }
    
    OpcUaBoolean&
    RelativePathElement::includeSubtypes(void)
    {
        return includeSubtypes_;
    }
    
    OpcUaQualifiedName&
    RelativePathElement::targetName(void)
    {
        return targetName_;
    }
    
    bool
    RelativePathElement::operator==(const RelativePathElement& value)
    {
        RelativePathElement* dst = const_cast<RelativePathElement*>(&value);
        if (referenceTypeId_ != dst->referenceTypeId()) return false;
        if (isInverse_ != dst->isInverse()) return false;
        if (includeSubtypes_ != dst->includeSubtypes()) return false;
        if (targetName_ != dst->targetName()) return false;
        return true;
    }
    
    bool
    RelativePathElement::operator!=(const RelativePathElement& value)
    {
        return !this->operator==(value);
    }
    
    void
    RelativePathElement::copyTo(RelativePathElement& value)
    {
        referenceTypeId_.copyTo(value.referenceTypeId());
        value.isInverse_ = isInverse_;
        value.includeSubtypes_ = includeSubtypes_;
        targetName_.copyTo(value.targetName());
    }
    
    RelativePathElement&
    RelativePathElement::operator=(const RelativePathElement& value)
    {
        const_cast<RelativePathElement*>(&value)->copyTo(*this);
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
    RelativePathElement::factory(void)
    {
    	return boost::make_shared<RelativePathElement>();
    }
    
    std::string
    RelativePathElement::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    RelativePathElement::typeName(void)
    {
    	return "RelativePathElement";
    }
    
    OpcUaNodeId
    RelativePathElement::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)537,0);
    }
    
    OpcUaNodeId
    RelativePathElement::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)539, 0);
    }
    
    OpcUaNodeId
    RelativePathElement::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)538, 0);
    }
    
    OpcUaNodeId
    RelativePathElement::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15188, 0);
    }
    
    bool
    RelativePathElement::opcUaBinaryEncode(std::ostream& os) const
    {
        referenceTypeId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isInverse_);
        OpcUaNumber::opcUaBinaryEncode(os,includeSubtypes_);
        targetName_.opcUaBinaryEncode(os);
        return true;
    }
    
    bool
    RelativePathElement::opcUaBinaryDecode(std::istream& is)
    {
        referenceTypeId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isInverse_);
        OpcUaNumber::opcUaBinaryDecode(is,includeSubtypes_);
        targetName_.opcUaBinaryDecode(is);
        return true;
    }
    
    bool
    RelativePathElement::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "RelativePathElement encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    RelativePathElement::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!referenceTypeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RelativePathElement encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isInverse_))
        {
            Log(Error, "RelativePathElement encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsInverse", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, includeSubtypes_))
        {
            Log(Error, "RelativePathElement encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IncludeSubtypes", elementTree));
    
        elementTree.clear();
        if (!targetName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RelativePathElement encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TargetName", elementTree));
    
        return true;
    }
    
    bool
    RelativePathElement::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePathElement decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RelativePathElement::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ReferenceTypeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePathElement decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!referenceTypeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RelativePathElement decode xml error - decode failed")
                .parameter("Element", "ReferenceTypeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("IsInverse");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePathElement decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isInverse_)) {
            Log(Error, "RelativePathElement decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IncludeSubtypes");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePathElement decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, includeSubtypes_)) {
            Log(Error, "RelativePathElement decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TargetName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePathElement decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RelativePathElement decode xml error - decode failed")
                .parameter("Element", "TargetName");
            return false;
        }
    
        return true;
    }
    
    bool
    RelativePathElement::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, referenceTypeId_, "ReferenceTypeId", true);
        rc = rc & jsonNumberEncode(pt, isInverse_, "IsInverse");
        rc = rc & jsonNumberEncode(pt, includeSubtypes_, "IncludeSubtypes");
        rc = rc & jsonObjectEncode(pt, targetName_, "TargetName", true);
    
        return rc;
    }
    
    bool
    RelativePathElement::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, referenceTypeId_, "ReferenceTypeId", true);
        rc = rc & jsonNumberDecode(pt, isInverse_, "IsInverse");
        rc = rc & jsonNumberDecode(pt, includeSubtypes_, "IncludeSubtypes");
        rc = rc & jsonObjectDecode(pt, targetName_, "TargetName", true);
    
        return rc;
    }
    
    void
    RelativePathElement::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	RelativePathElement* dst = dynamic_cast<RelativePathElement*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    RelativePathElement::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	RelativePathElement* dst = dynamic_cast<RelativePathElement*>(&extensionObjectBase);
    	return *const_cast<RelativePathElement*>(this) == *dst;
    }
    
    void
    RelativePathElement::out(std::ostream& os)
    {
        os << "ReferenceTypeId="; referenceTypeId_.out(os);
        os << ", IsInverse=" << isInverse_;
        os << ", IncludeSubtypes=" << includeSubtypes_;
        os << ", TargetName="; targetName_.out(os);
    }

}
