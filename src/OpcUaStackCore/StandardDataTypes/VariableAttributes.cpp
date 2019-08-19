/*
    DataTypeClass: VariableAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a variable node.
     */
    VariableAttributes::VariableAttributes(void)
    : NodeAttributes()
    , value_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , accessLevel_()
    , userAccessLevel_()
    , minimumSamplingInterval_()
    , historizing_()
    {
    }
    
    /**
     * The attributes for a variable node.
     */
    VariableAttributes::VariableAttributes(const VariableAttributes& value)
    : NodeAttributes()
    , value_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , accessLevel_()
    , userAccessLevel_()
    , minimumSamplingInterval_()
    , historizing_()
    {
        const_cast<VariableAttributes*>(&value)->copyTo(*this);
    }
    
    VariableAttributes::~VariableAttributes(void)
    {
    }
    
    OpcUaVariant&
    VariableAttributes::value(void)
    {
        return value_;
    }
    
    OpcUaNodeId&
    VariableAttributes::dataType(void)
    {
        return dataType_;
    }
    
    OpcUaInt32&
    VariableAttributes::valueRank(void)
    {
        return valueRank_;
    }
    
    OpcUaUInt32Array&
    VariableAttributes::arrayDimensions(void)
    {
        return arrayDimensions_;
    }
    
    OpcUaByte&
    VariableAttributes::accessLevel(void)
    {
        return accessLevel_;
    }
    
    OpcUaByte&
    VariableAttributes::userAccessLevel(void)
    {
        return userAccessLevel_;
    }
    
    OpcUaDuration&
    VariableAttributes::minimumSamplingInterval(void)
    {
        return minimumSamplingInterval_;
    }
    
    OpcUaBoolean&
    VariableAttributes::historizing(void)
    {
        return historizing_;
    }
    
    bool
    VariableAttributes::operator==(const VariableAttributes& value)
    {
        VariableAttributes* dst = const_cast<VariableAttributes*>(&value);
        if (value_ != dst->value()) return false;
        if (dataType_ != dst->dataType()) return false;
        if (valueRank_ != dst->valueRank()) return false;
        if (arrayDimensions_ != dst->arrayDimensions()) return false;
        if (accessLevel_ != dst->accessLevel()) return false;
        if (userAccessLevel_ != dst->userAccessLevel()) return false;
        if (minimumSamplingInterval_ != dst->minimumSamplingInterval()) return false;
        if (historizing_ != dst->historizing()) return false;
        return true;
    }
    
    bool
    VariableAttributes::operator!=(const VariableAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    VariableAttributes::copyTo(VariableAttributes& value)
    {
        value_.copyTo(value.value());
        dataType_.copyTo(value.dataType());
        value.valueRank_ = valueRank_;
        arrayDimensions_.copyTo(value.arrayDimensions());
        value.accessLevel_ = accessLevel_;
        value.userAccessLevel_ = userAccessLevel_;
        value.minimumSamplingInterval_ = minimumSamplingInterval_;
        value.historizing_ = historizing_;
    }
    
    VariableAttributes&
    VariableAttributes::operator=(const VariableAttributes& value)
    {
        const_cast<VariableAttributes*>(&value)->copyTo(*this);
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
    VariableAttributes::factory(void)
    {
    	return boost::make_shared<VariableAttributes>();
    }
    
    std::string
    VariableAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    VariableAttributes::typeName(void)
    {
    	return "VariableAttributes";
    }
    
    OpcUaNodeId
    VariableAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)355,0);
    }
    
    OpcUaNodeId
    VariableAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)357, 0);
    }
    
    OpcUaNodeId
    VariableAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)356, 0);
    }
    
    OpcUaNodeId
    VariableAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15153, 0);
    }
    
    void
    VariableAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        value_.opcUaBinaryEncode(os);
        dataType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,valueRank_);
        arrayDimensions_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,accessLevel_);
        OpcUaNumber::opcUaBinaryEncode(os,userAccessLevel_);
        OpcUaNumber::opcUaBinaryEncode(os,minimumSamplingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,historizing_);
    }
    
    void
    VariableAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        value_.opcUaBinaryDecode(is);
        dataType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,valueRank_);
        arrayDimensions_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,accessLevel_);
        OpcUaNumber::opcUaBinaryDecode(is,userAccessLevel_);
        OpcUaNumber::opcUaBinaryDecode(is,minimumSamplingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,historizing_);
    }
    
    bool
    VariableAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "VariableAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    VariableAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_))
        {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, accessLevel_))
        {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AccessLevel", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, userAccessLevel_))
        {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserAccessLevel", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, minimumSamplingInterval_))
        {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MinimumSamplingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, historizing_))
        {
            Log(Error, "VariableAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Historizing", elementTree));
    
        return true;
    }
    
    bool
    VariableAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    VariableAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.xmlDecode(*tree, xmlns)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("ValueRank");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ArrayDimensions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("AccessLevel");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, accessLevel_)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UserAccessLevel");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, userAccessLevel_)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MinimumSamplingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, minimumSamplingInterval_)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Historizing");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, historizing_)) {
            Log(Error, "VariableAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    VariableAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, value_, "Value", true);
        rc = rc & jsonObjectEncode(pt, dataType_, "DataType", true);
        rc = rc & jsonNumberEncode(pt, valueRank_, "ValueRank");
        rc = rc & jsonArrayEncode(pt, arrayDimensions_, "ArrayDimensions", true);
        rc = rc & jsonNumberEncode(pt, accessLevel_, "AccessLevel");
        rc = rc & jsonNumberEncode(pt, userAccessLevel_, "UserAccessLevel");
        rc = rc & jsonNumberEncode(pt, minimumSamplingInterval_, "MinimumSamplingInterval");
        rc = rc & jsonNumberEncode(pt, historizing_, "Historizing");
    
        return rc;
    }
    
    bool
    VariableAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, value_, "Value", true);
        rc = rc & jsonObjectDecode(pt, dataType_, "DataType", true);
        rc = rc & jsonNumberDecode(pt, valueRank_, "ValueRank");
        rc = rc & jsonArrayDecode(pt, arrayDimensions_, "ArrayDimensions", true);
        rc = rc & jsonNumberDecode(pt, accessLevel_, "AccessLevel");
        rc = rc & jsonNumberDecode(pt, userAccessLevel_, "UserAccessLevel");
        rc = rc & jsonNumberDecode(pt, minimumSamplingInterval_, "MinimumSamplingInterval");
        rc = rc & jsonNumberDecode(pt, historizing_, "Historizing");
    
        return rc;
    }
    
    void
    VariableAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	VariableAttributes* dst = dynamic_cast<VariableAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    VariableAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	VariableAttributes* dst = dynamic_cast<VariableAttributes*>(&extensionObjectBase);
    	return *const_cast<VariableAttributes*>(this) == *dst;
    }
    
    void
    VariableAttributes::out(std::ostream& os)
    {
        os << "Value="; value_.out(os);
        os << ", DataType="; dataType_.out(os);
        os << ", ValueRank=" << valueRank_;
        os << ", ArrayDimensions="; arrayDimensions_.out(os);
        os << ", AccessLevel=" << accessLevel_;
        os << ", UserAccessLevel=" << userAccessLevel_;
        os << ", MinimumSamplingInterval=" << minimumSamplingInterval_;
        os << ", Historizing=" << historizing_;
    }

}
