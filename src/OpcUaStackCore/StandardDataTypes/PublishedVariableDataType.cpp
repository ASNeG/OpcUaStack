/*
    DataTypeClass: PublishedVariableDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PublishedVariableDataType.h"

namespace OpcUaStackCore
{
    
    PublishedVariableDataType::PublishedVariableDataType(void)
    : Object()
    , ExtensionObjectBase()
    , publishedVariable_()
    , attributeId_()
    , samplingIntervalHint_()
    , deadbandType_()
    , deadbandValue_()
    , indexRange_()
    , substituteValue_()
    , metaDataProperties_()
    {
    }
    
    PublishedVariableDataType::PublishedVariableDataType(const PublishedVariableDataType& value)
    : Object()
    , ExtensionObjectBase()
    , publishedVariable_()
    , attributeId_()
    , samplingIntervalHint_()
    , deadbandType_()
    , deadbandValue_()
    , indexRange_()
    , substituteValue_()
    , metaDataProperties_()
    {
        const_cast<PublishedVariableDataType*>(&value)->copyTo(*this);
    }
    
    PublishedVariableDataType::~PublishedVariableDataType(void)
    {
    }
    
    OpcUaNodeId&
    PublishedVariableDataType::publishedVariable(void)
    {
        return publishedVariable_;
    }
    
    OpcUaIntegerId&
    PublishedVariableDataType::attributeId(void)
    {
        return attributeId_;
    }
    
    OpcUaDuration&
    PublishedVariableDataType::samplingIntervalHint(void)
    {
        return samplingIntervalHint_;
    }
    
    OpcUaUInt32&
    PublishedVariableDataType::deadbandType(void)
    {
        return deadbandType_;
    }
    
    OpcUaDouble&
    PublishedVariableDataType::deadbandValue(void)
    {
        return deadbandValue_;
    }
    
    OpcUaNumericRange&
    PublishedVariableDataType::indexRange(void)
    {
        return indexRange_;
    }
    
    OpcUaVariant&
    PublishedVariableDataType::substituteValue(void)
    {
        return substituteValue_;
    }
    
    OpcUaQualifiedNameArray&
    PublishedVariableDataType::metaDataProperties(void)
    {
        return metaDataProperties_;
    }
    
    bool
    PublishedVariableDataType::operator==(const PublishedVariableDataType& value)
    {
        PublishedVariableDataType* dst = const_cast<PublishedVariableDataType*>(&value);
        if (publishedVariable_ != dst->publishedVariable()) return false;
        if (attributeId_ != dst->attributeId()) return false;
        if (samplingIntervalHint_ != dst->samplingIntervalHint()) return false;
        if (deadbandType_ != dst->deadbandType()) return false;
        if (deadbandValue_ != dst->deadbandValue()) return false;
        if (indexRange_ != dst->indexRange()) return false;
        if (substituteValue_ != dst->substituteValue()) return false;
        if (metaDataProperties_ != dst->metaDataProperties()) return false;
        return true;
    }
    
    bool
    PublishedVariableDataType::operator!=(const PublishedVariableDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PublishedVariableDataType::copyTo(PublishedVariableDataType& value)
    {
        publishedVariable_.copyTo(value.publishedVariable());
        value.attributeId_ = attributeId_;
        value.samplingIntervalHint_ = samplingIntervalHint_;
        value.deadbandType_ = deadbandType_;
        value.deadbandValue_ = deadbandValue_;
        indexRange_.copyTo(value.indexRange());
        substituteValue_.copyTo(value.substituteValue());
        metaDataProperties_.copyTo(value.metaDataProperties());
    }
    
    PublishedVariableDataType&
    PublishedVariableDataType::operator=(const PublishedVariableDataType& value)
    {
        const_cast<PublishedVariableDataType*>(&value)->copyTo(*this);
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
    PublishedVariableDataType::factory(void)
    {
    	return constructSPtr<PublishedVariableDataType>();
    }
    
    std::string
    PublishedVariableDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PublishedVariableDataType::typeName(void)
    {
    	return "PublishedVariableDataType";
    }
    
    OpcUaNodeId
    PublishedVariableDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14273,0);
    }
    
    OpcUaNodeId
    PublishedVariableDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14323, 0);
    }
    
    OpcUaNodeId
    PublishedVariableDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14319, 0);
    }
    
    OpcUaNodeId
    PublishedVariableDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15060, 0);
    }
    
    void
    PublishedVariableDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        publishedVariable_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,attributeId_);
        OpcUaNumber::opcUaBinaryEncode(os,samplingIntervalHint_);
        OpcUaNumber::opcUaBinaryEncode(os,deadbandType_);
        OpcUaNumber::opcUaBinaryEncode(os,deadbandValue_);
        indexRange_.opcUaBinaryEncode(os);
        substituteValue_.opcUaBinaryEncode(os);
        metaDataProperties_.opcUaBinaryEncode(os);
    }
    
    void
    PublishedVariableDataType::opcUaBinaryDecode(std::istream& is)
    {
        publishedVariable_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,attributeId_);
        OpcUaNumber::opcUaBinaryDecode(is,samplingIntervalHint_);
        OpcUaNumber::opcUaBinaryDecode(is,deadbandType_);
        OpcUaNumber::opcUaBinaryDecode(is,deadbandValue_);
        indexRange_.opcUaBinaryDecode(is);
        substituteValue_.opcUaBinaryDecode(is);
        metaDataProperties_.opcUaBinaryDecode(is);
    }
    
    bool
    PublishedVariableDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedVariableDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedVariableDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedVariable_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishedVariable", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, attributeId_))
        {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, samplingIntervalHint_))
        {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SamplingIntervalHint", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deadbandType_))
        {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeadbandType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deadbandValue_))
        {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeadbandValue", elementTree));
    
        elementTree.clear();
        if (!indexRange_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        elementTree.clear();
        if (!substituteValue_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SubstituteValue", elementTree));
    
        elementTree.clear();
        if (!metaDataProperties_.xmlEncode(elementTree, "QualifiedName", xmlns)) {
            Log(Error, "PublishedVariableDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MetaDataProperties", elementTree));
    
        return true;
    }
    
    bool
    PublishedVariableDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedVariableDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PublishedVariable");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishedVariable_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", "PublishedVariable");
            return false;
        }
    
        elementName = xmlns.addPrefix("AttributeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, attributeId_)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SamplingIntervalHint");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, samplingIntervalHint_)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DeadbandType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, deadbandType_)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DeadbandValue");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, deadbandValue_)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IndexRange");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!indexRange_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", "IndexRange");
            return false;
        }
    
        elementName = xmlns.addPrefix("SubstituteValue");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!substituteValue_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", "SubstituteValue");
            return false;
        }
    
        elementName = xmlns.addPrefix("MetaDataProperties");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!metaDataProperties_.xmlDecode(*tree, "QualifiedName", xmlns)) {
            Log(Error, "PublishedVariableDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    PublishedVariableDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedVariable_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "publishedVariable_");
            return false;
        }
        pt.push_back(std::make_pair("PublishedVariable", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, attributeId_))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "attributeId_");
           return false;
        }
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, samplingIntervalHint_))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "samplingIntervalHint_");
           return false;
        }
        pt.push_back(std::make_pair("SamplingIntervalHint", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, deadbandType_))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "deadbandType_");
           return false;
        }
        pt.push_back(std::make_pair("DeadbandType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, deadbandValue_))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "deadbandValue_");
           return false;
        }
        pt.push_back(std::make_pair("DeadbandValue", elementTree));
    
        elementTree.clear();
        if (!indexRange_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "indexRange_");
            return false;
        }
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        elementTree.clear();
        if (!substituteValue_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "substituteValue_");
            return false;
        }
        pt.push_back(std::make_pair("SubstituteValue", elementTree));
    
        elementTree.clear();
        if (!metaDataProperties_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PublishedVariableDataType json encoder error")
    		     .parameter("Element", "metaDataProperties_");
            return false;
        }
        pt.push_back(std::make_pair("MetaDataProperties", elementTree));
    
        return true;
    }
    
    bool
    PublishedVariableDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "PublishedVariable";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishedVariable_.jsonDecode(*tree)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", "PublishedVariable");
            return false;
        }
    
        elementName = "AttributeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, attributeId_)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "SamplingIntervalHint";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, samplingIntervalHint_)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DeadbandType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, deadbandType_)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DeadbandValue";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, deadbandValue_)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IndexRange";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!indexRange_.jsonDecode(*tree)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", "IndexRange");
            return false;
        }
    
        elementName = "SubstituteValue";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!substituteValue_.jsonDecode(*tree)) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", "SubstituteValue");
            return false;
        }
    
        elementName = "MetaDataProperties";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedVariableDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!metaDataProperties_.jsonDecode(*tree, "")) {
            Log(Error, "PublishedVariableDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    PublishedVariableDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PublishedVariableDataType* dst = dynamic_cast<PublishedVariableDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PublishedVariableDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PublishedVariableDataType* dst = dynamic_cast<PublishedVariableDataType*>(&extensionObjectBase);
    	return *const_cast<PublishedVariableDataType*>(this) == *dst;
    }
    
    void
    PublishedVariableDataType::out(std::ostream& os)
    {
        os << "PublishedVariable="; publishedVariable_.out(os);
        os << ", AttributeId=" << attributeId_;
        os << ", SamplingIntervalHint=" << samplingIntervalHint_;
        os << ", DeadbandType=" << deadbandType_;
        os << ", DeadbandValue=" << deadbandValue_;
        os << ", IndexRange="; indexRange_.out(os);
        os << ", SubstituteValue="; substituteValue_.out(os);
        os << ", MetaDataProperties="; metaDataProperties_.out(os);
    }

}
