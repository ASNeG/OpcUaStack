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
    PublishedVariableDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PublishedVariableDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PublishedVariableDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedVariableDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedVariable_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("PublishedVariable", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, attributeId_)) return false;
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, samplingIntervalHint_)) return false;
        pt.push_back(std::make_pair("SamplingIntervalHint", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deadbandType_)) return false;
        pt.push_back(std::make_pair("DeadbandType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deadbandValue_)) return false;
        pt.push_back(std::make_pair("DeadbandValue", elementTree));
    
        elementTree.clear();
        if (!indexRange_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        elementTree.clear();
        if (!substituteValue_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SubstituteValue", elementTree));
    
        elementTree.clear();
        if (!metaDataProperties_.xmlEncode(elementTree, "QualifiedName", xmlns)) return false;
        pt.push_back(std::make_pair("MetaDataProperties", elementTree));
    
        return true;
    }
    
    bool
    PublishedVariableDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedVariableDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("PublishedVariable");
        if (!tree) return false;
        if (!publishedVariable_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("AttributeId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, attributeId_)) return false;
    
        tree = pt.get_child_optional("SamplingIntervalHint");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, samplingIntervalHint_)) return false;
    
        tree = pt.get_child_optional("DeadbandType");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, deadbandType_)) return false;
    
        tree = pt.get_child_optional("DeadbandValue");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, deadbandValue_)) return false;
    
        tree = pt.get_child_optional("IndexRange");
        if (!tree) return false;
        if (!indexRange_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SubstituteValue");
        if (!tree) return false;
        if (!substituteValue_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("MetaDataProperties");
        if (!tree) return false;
        if (!metaDataProperties_.xmlDecode(*tree, "QualifiedName", xmlns)) return false;
    
        return true;
    }
    
    bool
    PublishedVariableDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    PublishedVariableDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    PublishedVariableDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    PublishedVariableDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
