/*
    DataTypeClass: ModelChangeStructureDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ModelChangeStructureDataType.h"

namespace OpcUaStackCore
{
    
    ModelChangeStructureDataType::ModelChangeStructureDataType(void)
    : Object()
    , ExtensionObjectBase()
    , affected_()
    , affectedType_()
    , verb_()
    {
    }
    
    ModelChangeStructureDataType::ModelChangeStructureDataType(const ModelChangeStructureDataType& value)
    : Object()
    , ExtensionObjectBase()
    , affected_()
    , affectedType_()
    , verb_()
    {
        const_cast<ModelChangeStructureDataType*>(&value)->copyTo(*this);
    }
    
    ModelChangeStructureDataType::~ModelChangeStructureDataType(void)
    {
    }
    
    OpcUaNodeId&
    ModelChangeStructureDataType::affected(void)
    {
        return affected_;
    }
    
    OpcUaNodeId&
    ModelChangeStructureDataType::affectedType(void)
    {
        return affectedType_;
    }
    
    OpcUaByte&
    ModelChangeStructureDataType::verb(void)
    {
        return verb_;
    }
    
    bool
    ModelChangeStructureDataType::operator==(const ModelChangeStructureDataType& value)
    {
        ModelChangeStructureDataType* dst = const_cast<ModelChangeStructureDataType*>(&value);
        if (affected_ != dst->affected()) return false;
        if (affectedType_ != dst->affectedType()) return false;
        if (verb_ != dst->verb()) return false;
        return true;
    }
    
    bool
    ModelChangeStructureDataType::operator!=(const ModelChangeStructureDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ModelChangeStructureDataType::copyTo(ModelChangeStructureDataType& value)
    {
        affected_.copyTo(value.affected());
        affectedType_.copyTo(value.affectedType());
        value.verb_ = verb_;
    }
    
    ModelChangeStructureDataType&
    ModelChangeStructureDataType::operator=(const ModelChangeStructureDataType& value)
    {
        const_cast<ModelChangeStructureDataType*>(&value)->copyTo(*this);
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
    ModelChangeStructureDataType::factory(void)
    {
    	return constructSPtr<ModelChangeStructureDataType>();
    }
    
    std::string
    ModelChangeStructureDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ModelChangeStructureDataType::typeName(void)
    {
    	return "ModelChangeStructureDataType";
    }
    
    OpcUaNodeId
    ModelChangeStructureDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)877,0);
    }
    
    OpcUaNodeId
    ModelChangeStructureDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)879, 0);
    }
    
    OpcUaNodeId
    ModelChangeStructureDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)878, 0);
    }
    
    OpcUaNodeId
    ModelChangeStructureDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15373, 0);
    }
    
    void
    ModelChangeStructureDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        affected_.opcUaBinaryEncode(os);
        affectedType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,verb_);
    }
    
    void
    ModelChangeStructureDataType::opcUaBinaryDecode(std::istream& is)
    {
        affected_.opcUaBinaryDecode(is);
        affectedType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,verb_);
    }
    
    bool
    ModelChangeStructureDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModelChangeStructureDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ModelChangeStructureDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!affected_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModelChangeStructureDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Affected", elementTree));
    
        elementTree.clear();
        if (!affectedType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ModelChangeStructureDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AffectedType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, verb_))
        {
            Log(Error, "ModelChangeStructureDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Verb", elementTree));
    
        return true;
    }
    
    bool
    ModelChangeStructureDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ModelChangeStructureDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Affected");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!affected_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ModelChangeStructureDataType decode xml error - decode failed")
                .parameter("Element", "Affected");
            return false;
        }
    
        elementName = xmlns.addPrefix("AffectedType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!affectedType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ModelChangeStructureDataType decode xml error - decode failed")
                .parameter("Element", "AffectedType");
            return false;
        }
    
        elementName = xmlns.addPrefix("Verb");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, verb_)) {
            Log(Error, "ModelChangeStructureDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ModelChangeStructureDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!affected_.jsonEncode(elementTree))
        {
    	     Log(Error, "ModelChangeStructureDataType json encoder error")
    		     .parameter("Element", "affected_");
            return false;
        }
        pt.push_back(std::make_pair("Affected", elementTree));
    
        elementTree.clear();
        if (!affectedType_.jsonEncode(elementTree))
        {
    	     Log(Error, "ModelChangeStructureDataType json encoder error")
    		     .parameter("Element", "affectedType_");
            return false;
        }
        pt.push_back(std::make_pair("AffectedType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, verb_))
        {
    	     Log(Error, "ModelChangeStructureDataType json encoder error")
    		     .parameter("Element", "verb_");
           return false;
        }
        pt.push_back(std::make_pair("Verb", elementTree));
    
        return true;
    }
    
    bool
    ModelChangeStructureDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Affected";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!affected_.jsonDecode(*tree)) {
            Log(Error, "ModelChangeStructureDataType decode json error - decode failed")
                .parameter("Element", "Affected");
            return false;
        }
    
        elementName = "AffectedType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!affectedType_.jsonDecode(*tree)) {
            Log(Error, "ModelChangeStructureDataType decode json error - decode failed")
                .parameter("Element", "AffectedType");
            return false;
        }
    
        elementName = "Verb";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ModelChangeStructureDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, verb_)) {
            Log(Error, "ModelChangeStructureDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ModelChangeStructureDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ModelChangeStructureDataType* dst = dynamic_cast<ModelChangeStructureDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ModelChangeStructureDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ModelChangeStructureDataType* dst = dynamic_cast<ModelChangeStructureDataType*>(&extensionObjectBase);
    	return *const_cast<ModelChangeStructureDataType*>(this) == *dst;
    }
    
    void
    ModelChangeStructureDataType::out(std::ostream& os)
    {
        os << "Affected="; affected_.out(os);
        os << ", AffectedType="; affectedType_.out(os);
        os << ", Verb=" << verb_;
    }

}
