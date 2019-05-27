/*
    DataTypeClass: HistoryModifiedData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryModifiedData.h"

namespace OpcUaStackCore
{
    
    HistoryModifiedData::HistoryModifiedData(void)
    : HistoryData()
    , modificationInfos_()
    {
    }
    
    HistoryModifiedData::HistoryModifiedData(const HistoryModifiedData& value)
    : HistoryData()
    , modificationInfos_()
    {
        const_cast<HistoryModifiedData*>(&value)->copyTo(*this);
    }
    
    HistoryModifiedData::~HistoryModifiedData(void)
    {
    }
    
    ModificationInfoArray&
    HistoryModifiedData::modificationInfos(void)
    {
        return modificationInfos_;
    }
    
    bool
    HistoryModifiedData::operator==(const HistoryModifiedData& value)
    {
        HistoryModifiedData* dst = const_cast<HistoryModifiedData*>(&value);
        if (modificationInfos_ != dst->modificationInfos()) return false;
        return true;
    }
    
    bool
    HistoryModifiedData::operator!=(const HistoryModifiedData& value)
    {
        return !this->operator==(value);
    }
    
    void
    HistoryModifiedData::copyTo(HistoryModifiedData& value)
    {
        modificationInfos_.copyTo(value.modificationInfos());
    }
    
    HistoryModifiedData&
    HistoryModifiedData::operator=(const HistoryModifiedData& value)
    {
        const_cast<HistoryModifiedData*>(&value)->copyTo(*this);
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
    HistoryModifiedData::factory(void)
    {
    	return constructSPtr<HistoryModifiedData>();
    }
    
    std::string
    HistoryModifiedData::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryModifiedData::typeName(void)
    {
    	return "HistoryModifiedData";
    }
    
    OpcUaNodeId
    HistoryModifiedData::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11217,0);
    }
    
    OpcUaNodeId
    HistoryModifiedData::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11227, 0);
    }
    
    OpcUaNodeId
    HistoryModifiedData::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11219, 0);
    }
    
    OpcUaNodeId
    HistoryModifiedData::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15272, 0);
    }
    
    void
    HistoryModifiedData::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryData::opcUaBinaryEncode(os);
        modificationInfos_.opcUaBinaryEncode(os);
    }
    
    void
    HistoryModifiedData::opcUaBinaryDecode(std::istream& is)
    {
        HistoryData::opcUaBinaryDecode(is);
        modificationInfos_.opcUaBinaryDecode(is);
    }
    
    bool
    HistoryModifiedData::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryModifiedData encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryModifiedData::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!modificationInfos_.xmlEncode(elementTree, "ModificationInfo", xmlns)) {
            Log(Error, "HistoryModifiedData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ModificationInfos", elementTree));
    
        return true;
    }
    
    bool
    HistoryModifiedData::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryModifiedData decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryModifiedData::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ModificationInfos");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryModifiedData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modificationInfos_.xmlDecode(*tree, "ModificationInfo", xmlns)) {
            Log(Error, "HistoryModifiedData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    HistoryModifiedData::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!modificationInfos_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "HistoryModifiedData json encoder error")
    		     .parameter("Element", "modificationInfos_");
            return false;
        }
        pt.push_back(std::make_pair("ModificationInfos", elementTree));
    
        return true;
    }
    
    bool
    HistoryModifiedData::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ModificationInfos";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryModifiedData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modificationInfos_.jsonDecode(*tree, "")) {
            Log(Error, "HistoryModifiedData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    HistoryModifiedData::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryModifiedData* dst = dynamic_cast<HistoryModifiedData*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryModifiedData::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryModifiedData* dst = dynamic_cast<HistoryModifiedData*>(&extensionObjectBase);
    	return *const_cast<HistoryModifiedData*>(this) == *dst;
    }
    
    void
    HistoryModifiedData::out(std::ostream& os)
    {
        os << "ModificationInfos="; modificationInfos_.out(os);
    }

}
