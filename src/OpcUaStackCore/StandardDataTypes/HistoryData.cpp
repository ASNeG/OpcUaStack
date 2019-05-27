/*
    DataTypeClass: HistoryData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"

namespace OpcUaStackCore
{
    
    HistoryData::HistoryData(void)
    : Object()
    , ExtensionObjectBase()
    , dataValues_()
    {
    }
    
    HistoryData::HistoryData(const HistoryData& value)
    : Object()
    , ExtensionObjectBase()
    , dataValues_()
    {
        const_cast<HistoryData*>(&value)->copyTo(*this);
    }
    
    HistoryData::~HistoryData(void)
    {
    }
    
    OpcUaDataValueArray&
    HistoryData::dataValues(void)
    {
        return dataValues_;
    }
    
    bool
    HistoryData::operator==(const HistoryData& value)
    {
        HistoryData* dst = const_cast<HistoryData*>(&value);
        if (dataValues_ != dst->dataValues()) return false;
        return true;
    }
    
    bool
    HistoryData::operator!=(const HistoryData& value)
    {
        return !this->operator==(value);
    }
    
    void
    HistoryData::copyTo(HistoryData& value)
    {
        dataValues_.copyTo(value.dataValues());
    }
    
    HistoryData&
    HistoryData::operator=(const HistoryData& value)
    {
        const_cast<HistoryData*>(&value)->copyTo(*this);
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
    HistoryData::factory(void)
    {
    	return constructSPtr<HistoryData>();
    }
    
    std::string
    HistoryData::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryData::typeName(void)
    {
    	return "HistoryData";
    }
    
    OpcUaNodeId
    HistoryData::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)656,0);
    }
    
    OpcUaNodeId
    HistoryData::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)658, 0);
    }
    
    OpcUaNodeId
    HistoryData::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)657, 0);
    }
    
    OpcUaNodeId
    HistoryData::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15270, 0);
    }
    
    void
    HistoryData::opcUaBinaryEncode(std::ostream& os) const
    {
        dataValues_.opcUaBinaryEncode(os);
    }
    
    void
    HistoryData::opcUaBinaryDecode(std::istream& is)
    {
        dataValues_.opcUaBinaryDecode(is);
    }
    
    bool
    HistoryData::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryData encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryData::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!dataValues_.xmlEncode(elementTree, "DataValue", xmlns)) {
            Log(Error, "HistoryData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataValues", elementTree));
    
        return true;
    }
    
    bool
    HistoryData::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryData decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryData::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("DataValues");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataValues_.xmlDecode(*tree, "DataValue", xmlns)) {
            Log(Error, "HistoryData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    HistoryData::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!dataValues_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "HistoryData json encoder error")
    		     .parameter("Element", "dataValues_");
            return false;
        }
        pt.push_back(std::make_pair("DataValues", elementTree));
    
        return true;
    }
    
    bool
    HistoryData::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "DataValues";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataValues_.jsonDecode(*tree, "")) {
            Log(Error, "HistoryData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    HistoryData::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryData* dst = dynamic_cast<HistoryData*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryData::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryData* dst = dynamic_cast<HistoryData*>(&extensionObjectBase);
    	return *const_cast<HistoryData*>(this) == *dst;
    }
    
    void
    HistoryData::out(std::ostream& os)
    {
        os << "DataValues="; dataValues_.out(os);
    }

}
