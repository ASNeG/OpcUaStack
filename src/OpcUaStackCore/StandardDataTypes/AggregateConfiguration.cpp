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
    
    AggregateConfiguration::AggregateConfiguration(const AggregateConfiguration& value)
    : Object()
    , ExtensionObjectBase()
    , useServerCapabilitiesDefaults_()
    , treatUncertainAsBad_()
    , percentDataBad_()
    , percentDataGood_()
    , useSlopedExtrapolation_()
    {
        const_cast<AggregateConfiguration*>(&value)->copyTo(*this);
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
    AggregateConfiguration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateConfiguration encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AggregateConfiguration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useServerCapabilitiesDefaults_))
        {
            Log(Error, "AggregateConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UseServerCapabilitiesDefaults", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, treatUncertainAsBad_))
        {
            Log(Error, "AggregateConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TreatUncertainAsBad", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, percentDataBad_))
        {
            Log(Error, "AggregateConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PercentDataBad", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, percentDataGood_))
        {
            Log(Error, "AggregateConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PercentDataGood", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useSlopedExtrapolation_))
        {
            Log(Error, "AggregateConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UseSlopedExtrapolation", elementTree));
    
        return true;
    }
    
    bool
    AggregateConfiguration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AggregateConfiguration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("UseServerCapabilitiesDefaults");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, useServerCapabilitiesDefaults_)) {
            Log(Error, "AggregateConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TreatUncertainAsBad");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, treatUncertainAsBad_)) {
            Log(Error, "AggregateConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PercentDataBad");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, percentDataBad_)) {
            Log(Error, "AggregateConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PercentDataGood");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, percentDataGood_)) {
            Log(Error, "AggregateConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UseSlopedExtrapolation");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, useSlopedExtrapolation_)) {
            Log(Error, "AggregateConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    AggregateConfiguration::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, useServerCapabilitiesDefaults_))
        {
    	     Log(Error, "AggregateConfiguration json encoder error")
    		     .parameter("Element", "useServerCapabilitiesDefaults_");
           return false;
        }
        pt.push_back(std::make_pair("UseServerCapabilitiesDefaults", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, treatUncertainAsBad_))
        {
    	     Log(Error, "AggregateConfiguration json encoder error")
    		     .parameter("Element", "treatUncertainAsBad_");
           return false;
        }
        pt.push_back(std::make_pair("TreatUncertainAsBad", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, percentDataBad_))
        {
    	     Log(Error, "AggregateConfiguration json encoder error")
    		     .parameter("Element", "percentDataBad_");
           return false;
        }
        pt.push_back(std::make_pair("PercentDataBad", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, percentDataGood_))
        {
    	     Log(Error, "AggregateConfiguration json encoder error")
    		     .parameter("Element", "percentDataGood_");
           return false;
        }
        pt.push_back(std::make_pair("PercentDataGood", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, useSlopedExtrapolation_))
        {
    	     Log(Error, "AggregateConfiguration json encoder error")
    		     .parameter("Element", "useSlopedExtrapolation_");
           return false;
        }
        pt.push_back(std::make_pair("UseSlopedExtrapolation", elementTree));
    
        return true;
    }
    
    bool
    AggregateConfiguration::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "UseServerCapabilitiesDefaults";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, useServerCapabilitiesDefaults_)) {
            Log(Error, "AggregateConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TreatUncertainAsBad";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, treatUncertainAsBad_)) {
            Log(Error, "AggregateConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PercentDataBad";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, percentDataBad_)) {
            Log(Error, "AggregateConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PercentDataGood";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, percentDataGood_)) {
            Log(Error, "AggregateConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "UseSlopedExtrapolation";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, useSlopedExtrapolation_)) {
            Log(Error, "AggregateConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
