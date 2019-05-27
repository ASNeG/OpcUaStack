/*
    DataTypeClass: AxisInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AxisInformation.h"

namespace OpcUaStackCore
{
    
    AxisInformation::AxisInformation(void)
    : Object()
    , ExtensionObjectBase()
    , engineeringUnits_()
    , eURange_()
    , title_()
    , axisScaleType_()
    , axisSteps_()
    {
    }
    
    AxisInformation::AxisInformation(const AxisInformation& value)
    : Object()
    , ExtensionObjectBase()
    , engineeringUnits_()
    , eURange_()
    , title_()
    , axisScaleType_()
    , axisSteps_()
    {
        const_cast<AxisInformation*>(&value)->copyTo(*this);
    }
    
    AxisInformation::~AxisInformation(void)
    {
    }
    
    EUInformation&
    AxisInformation::engineeringUnits(void)
    {
        return engineeringUnits_;
    }
    
    Range&
    AxisInformation::eURange(void)
    {
        return eURange_;
    }
    
    OpcUaLocalizedText&
    AxisInformation::title(void)
    {
        return title_;
    }
    
    AxisScaleEnumeration&
    AxisInformation::axisScaleType(void)
    {
        return axisScaleType_;
    }
    
    OpcUaDoubleArray&
    AxisInformation::axisSteps(void)
    {
        return axisSteps_;
    }
    
    bool
    AxisInformation::operator==(const AxisInformation& value)
    {
        AxisInformation* dst = const_cast<AxisInformation*>(&value);
        if (engineeringUnits_ != dst->engineeringUnits()) return false;
        if (eURange_ != dst->eURange()) return false;
        if (title_ != dst->title()) return false;
        if (axisScaleType_ != dst->axisScaleType()) return false;
        if (axisSteps_ != dst->axisSteps()) return false;
        return true;
    }
    
    bool
    AxisInformation::operator!=(const AxisInformation& value)
    {
        return !this->operator==(value);
    }
    
    void
    AxisInformation::copyTo(AxisInformation& value)
    {
        engineeringUnits_.copyTo(value.engineeringUnits());
        eURange_.copyTo(value.eURange());
        title_.copyTo(value.title());
        axisScaleType_.copyTo(value.axisScaleType());
        axisSteps_.copyTo(value.axisSteps());
    }
    
    AxisInformation&
    AxisInformation::operator=(const AxisInformation& value)
    {
        const_cast<AxisInformation*>(&value)->copyTo(*this);
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
    AxisInformation::factory(void)
    {
    	return constructSPtr<AxisInformation>();
    }
    
    std::string
    AxisInformation::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AxisInformation::typeName(void)
    {
    	return "AxisInformation";
    }
    
    OpcUaNodeId
    AxisInformation::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12079,0);
    }
    
    OpcUaNodeId
    AxisInformation::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12089, 0);
    }
    
    OpcUaNodeId
    AxisInformation::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12081, 0);
    }
    
    OpcUaNodeId
    AxisInformation::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15379, 0);
    }
    
    void
    AxisInformation::opcUaBinaryEncode(std::ostream& os) const
    {
        engineeringUnits_.opcUaBinaryEncode(os);
        eURange_.opcUaBinaryEncode(os);
        title_.opcUaBinaryEncode(os);
        axisScaleType_.opcUaBinaryEncode(os);
        axisSteps_.opcUaBinaryEncode(os);
    }
    
    void
    AxisInformation::opcUaBinaryDecode(std::istream& is)
    {
        engineeringUnits_.opcUaBinaryDecode(is);
        eURange_.opcUaBinaryDecode(is);
        title_.opcUaBinaryDecode(is);
        axisScaleType_.opcUaBinaryDecode(is);
        axisSteps_.opcUaBinaryDecode(is);
    }
    
    bool
    AxisInformation::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AxisInformation encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AxisInformation::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!engineeringUnits_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AxisInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EngineeringUnits", elementTree));
    
        elementTree.clear();
        if (!eURange_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AxisInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EURange", elementTree));
    
        elementTree.clear();
        if (!title_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AxisInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Title", elementTree));
    
        elementTree.clear();
        if (!axisScaleType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AxisInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AxisScaleType", elementTree));
    
        elementTree.clear();
        if (!axisSteps_.xmlEncode(elementTree, "Double", xmlns)) {
            Log(Error, "AxisInformation encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AxisSteps", elementTree));
    
        return true;
    }
    
    bool
    AxisInformation::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AxisInformation::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EngineeringUnits");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!engineeringUnits_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AxisInformation decode xml error - decode failed")
                .parameter("Element", "EngineeringUnits");
            return false;
        }
    
        elementName = xmlns.addPrefix("EURange");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eURange_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AxisInformation decode xml error - decode failed")
                .parameter("Element", "EURange");
            return false;
        }
    
        elementName = xmlns.addPrefix("Title");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!title_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AxisInformation decode xml error - decode failed")
                .parameter("Element", "Title");
            return false;
        }
    
        elementName = xmlns.addPrefix("AxisScaleType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!axisScaleType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AxisInformation decode xml error - decode failed")
                .parameter("Element", "AxisScaleType");
            return false;
        }
    
        elementName = xmlns.addPrefix("AxisSteps");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!axisSteps_.xmlDecode(*tree, "Double", xmlns)) {
            Log(Error, "AxisInformation decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    AxisInformation::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!engineeringUnits_.jsonEncode(elementTree))
        {
    	     Log(Error, "AxisInformation json encoder error")
    		     .parameter("Element", "engineeringUnits_");
            return false;
        }
        pt.push_back(std::make_pair("EngineeringUnits", elementTree));
    
        elementTree.clear();
        if (!eURange_.jsonEncode(elementTree))
        {
    	     Log(Error, "AxisInformation json encoder error")
    		     .parameter("Element", "eURange_");
            return false;
        }
        pt.push_back(std::make_pair("EURange", elementTree));
    
        elementTree.clear();
        if (!title_.jsonEncode(elementTree))
        {
    	     Log(Error, "AxisInformation json encoder error")
    		     .parameter("Element", "title_");
            return false;
        }
        pt.push_back(std::make_pair("Title", elementTree));
    
        elementTree.clear();
        if (!axisScaleType_.jsonEncode(elementTree))
        {
    	     Log(Error, "AxisInformation json encoder error")
    		     .parameter("Element", "axisScaleType_");
            return false;
        }
        pt.push_back(std::make_pair("AxisScaleType", elementTree));
    
        elementTree.clear();
        if (!axisSteps_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "AxisInformation json encoder error")
    		     .parameter("Element", "axisSteps_");
            return false;
        }
        pt.push_back(std::make_pair("AxisSteps", elementTree));
    
        return true;
    }
    
    bool
    AxisInformation::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "EngineeringUnits";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!engineeringUnits_.jsonDecode(*tree)) {
            Log(Error, "AxisInformation decode json error - decode failed")
                .parameter("Element", "EngineeringUnits");
            return false;
        }
    
        elementName = "EURange";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eURange_.jsonDecode(*tree)) {
            Log(Error, "AxisInformation decode json error - decode failed")
                .parameter("Element", "EURange");
            return false;
        }
    
        elementName = "Title";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!title_.jsonDecode(*tree)) {
            Log(Error, "AxisInformation decode json error - decode failed")
                .parameter("Element", "Title");
            return false;
        }
    
        elementName = "AxisScaleType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!axisScaleType_.jsonDecode(*tree)) {
            Log(Error, "AxisInformation decode json error - decode failed")
                .parameter("Element", "AxisScaleType");
            return false;
        }
    
        elementName = "AxisSteps";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AxisInformation decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!axisSteps_.jsonDecode(*tree, "")) {
            Log(Error, "AxisInformation decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    AxisInformation::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AxisInformation* dst = dynamic_cast<AxisInformation*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AxisInformation::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AxisInformation* dst = dynamic_cast<AxisInformation*>(&extensionObjectBase);
    	return *const_cast<AxisInformation*>(this) == *dst;
    }
    
    void
    AxisInformation::out(std::ostream& os)
    {
        os << "EngineeringUnits="; engineeringUnits_.out(os);
        os << ", EURange="; eURange_.out(os);
        os << ", Title="; title_.out(os);
        os << ", AxisScaleType="; axisScaleType_.out(os);
        os << ", AxisSteps="; axisSteps_.out(os);
    }

}
