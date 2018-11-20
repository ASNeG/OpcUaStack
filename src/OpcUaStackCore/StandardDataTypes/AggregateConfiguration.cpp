/*
    DataTypeClass: AggregateConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AggregateConfiguration.h"

namespace OpcUaStackCore
{
    
    AggregateConfiguration::AggregateConfiguration(void)
    : Object()
    , ExtensionObjectBase()
    , useServerCapabilitiesDefaults_()
    , treatUncertainAsBad_()
    , percentDataBad_()
    , percentDataGood_()
    , useSlopedExtrapolation_()
    {
    }
    
    AggregateConfiguration::~AggregateConfiguration(void)
    {
    }
    
    OpcUaBoolean&
    AggregateConfiguration::useServerCapabilitiesDefaults(void)
    {
        return useServerCapabilitiesDefaults_;
    }
    
    OpcUaBoolean&
    AggregateConfiguration::treatUncertainAsBad(void)
    {
        return treatUncertainAsBad_;
    }
    
    OpcUaByte&
    AggregateConfiguration::percentDataBad(void)
    {
        return percentDataBad_;
    }
    
    OpcUaByte&
    AggregateConfiguration::percentDataGood(void)
    {
        return percentDataGood_;
    }
    
    OpcUaBoolean&
    AggregateConfiguration::useSlopedExtrapolation(void)
    {
        return useSlopedExtrapolation_;
    }
    
    bool
    AggregateConfiguration::operator==(const AggregateConfiguration& value)
    {
        AggregateConfiguration* dst = const_cast<AggregateConfiguration*>(&value);
        if (useServerCapabilitiesDefaults_ != dst->useServerCapabilitiesDefaults()) return false;
        if (treatUncertainAsBad_ != dst->treatUncertainAsBad()) return false;
        if (percentDataBad_ != dst->percentDataBad()) return false;
        if (percentDataGood_ != dst->percentDataGood()) return false;
        if (useSlopedExtrapolation_ != dst->useSlopedExtrapolation()) return false;
        return true;
    }
    
    bool
    AggregateConfiguration::operator!=(const AggregateConfiguration& value)
    {
        return !this->operator==(value);
    }
    
    void
    AggregateConfiguration::copyTo(AggregateConfiguration& value)
    {
        value.useServerCapabilitiesDefaults_ = useServerCapabilitiesDefaults_;
        value.treatUncertainAsBad_ = treatUncertainAsBad_;
        value.percentDataBad_ = percentDataBad_;
        value.percentDataGood_ = percentDataGood_;
        value.useSlopedExtrapolation_ = useSlopedExtrapolation_;
    }
    
    AggregateConfiguration&
    AggregateConfiguration::operator=(const AggregateConfiguration& value)
    {
        const_cast<AggregateConfiguration*>(&value)->copyTo(*this);
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
    AggregateConfiguration::factory(void)
    {
    	return constructSPtr<AggregateConfiguration>();
    }
    
    std::string
    AggregateConfiguration::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AggregateConfiguration::typeName(void)
    {
    	return "AggregateConfiguration";
    }
    
    OpcUaNodeId
    AggregateConfiguration::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)948,0);
    }
    
    OpcUaNodeId
    AggregateConfiguration::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)950, 0);
    }
    
    OpcUaNodeId
    AggregateConfiguration::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)949, 0);
    }
    
    OpcUaNodeId
    AggregateConfiguration::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15304, 0);
    }
    
    void
    AggregateConfiguration::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,useServerCapabilitiesDefaults_);
        OpcUaNumber::opcUaBinaryEncode(os,treatUncertainAsBad_);
        OpcUaNumber::opcUaBinaryEncode(os,percentDataBad_);
        OpcUaNumber::opcUaBinaryEncode(os,percentDataGood_);
        OpcUaNumber::opcUaBinaryEncode(os,useSlopedExtrapolation_);
    }
    
    void
    AggregateConfiguration::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,useServerCapabilitiesDefaults_);
        OpcUaNumber::opcUaBinaryDecode(is,treatUncertainAsBad_);
        OpcUaNumber::opcUaBinaryDecode(is,percentDataBad_);
        OpcUaNumber::opcUaBinaryDecode(is,percentDataGood_);
        OpcUaNumber::opcUaBinaryDecode(is,useSlopedExtrapolation_);
    }
    
    bool
    AggregateConfiguration::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    AggregateConfiguration::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    AggregateConfiguration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AggregateConfiguration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useServerCapabilitiesDefaults_)) return false;
        pt.push_back(std::make_pair("UseServerCapabilitiesDefaults", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, treatUncertainAsBad_)) return false;
        pt.push_back(std::make_pair("TreatUncertainAsBad", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, percentDataBad_)) return false;
        pt.push_back(std::make_pair("PercentDataBad", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, percentDataGood_)) return false;
        pt.push_back(std::make_pair("PercentDataGood", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useSlopedExtrapolation_)) return false;
        pt.push_back(std::make_pair("UseSlopedExtrapolation", elementTree));
    
        return true;
    }
    
    bool
    AggregateConfiguration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AggregateConfiguration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("UseServerCapabilitiesDefaults");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, useServerCapabilitiesDefaults_)) return false;
    
        tree = pt.get_child_optional("TreatUncertainAsBad");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, treatUncertainAsBad_)) return false;
    
        tree = pt.get_child_optional("PercentDataBad");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, percentDataBad_)) return false;
    
        tree = pt.get_child_optional("PercentDataGood");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, percentDataGood_)) return false;
    
        tree = pt.get_child_optional("UseSlopedExtrapolation");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, useSlopedExtrapolation_)) return false;
    
        return true;
    }
    
    bool
    AggregateConfiguration::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    AggregateConfiguration::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    AggregateConfiguration::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    AggregateConfiguration::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    AggregateConfiguration::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AggregateConfiguration* dst = dynamic_cast<AggregateConfiguration*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AggregateConfiguration::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AggregateConfiguration* dst = dynamic_cast<AggregateConfiguration*>(&extensionObjectBase);
    	return *const_cast<AggregateConfiguration*>(this) == *dst;
    }
    
    void
    AggregateConfiguration::out(std::ostream& os)
    {
        os << "UseServerCapabilitiesDefaults=" << useServerCapabilitiesDefaults_;
        os << ", TreatUncertainAsBad=" << treatUncertainAsBad_;
        os << ", PercentDataBad=" << percentDataBad_;
        os << ", PercentDataGood=" << percentDataGood_;
        os << ", UseSlopedExtrapolation=" << useSlopedExtrapolation_;
    }

}
