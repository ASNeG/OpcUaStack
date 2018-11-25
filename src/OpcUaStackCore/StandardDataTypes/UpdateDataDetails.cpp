/*
    DataTypeClass: UpdateDataDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UpdateDataDetails.h"

namespace OpcUaStackCore
{
    
    UpdateDataDetails::UpdateDataDetails(void)
    : HistoryUpdateDetails()
    , performInsertReplace_()
    , updateValues_()
    {
    }
    
    UpdateDataDetails::~UpdateDataDetails(void)
    {
    }
    
    PerformUpdateType&
    UpdateDataDetails::performInsertReplace(void)
    {
        return performInsertReplace_;
    }
    
    OpcUaDataValueArray&
    UpdateDataDetails::updateValues(void)
    {
        return updateValues_;
    }
    
    bool
    UpdateDataDetails::operator==(const UpdateDataDetails& value)
    {
        UpdateDataDetails* dst = const_cast<UpdateDataDetails*>(&value);
        if (performInsertReplace_ != dst->performInsertReplace()) return false;
        if (updateValues_ != dst->updateValues()) return false;
        return true;
    }
    
    bool
    UpdateDataDetails::operator!=(const UpdateDataDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    UpdateDataDetails::copyTo(UpdateDataDetails& value)
    {
        performInsertReplace_.copyTo(value.performInsertReplace());
        updateValues_.copyTo(value.updateValues());
    }
    
    UpdateDataDetails&
    UpdateDataDetails::operator=(const UpdateDataDetails& value)
    {
        const_cast<UpdateDataDetails*>(&value)->copyTo(*this);
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
    UpdateDataDetails::factory(void)
    {
    	return constructSPtr<UpdateDataDetails>();
    }
    
    std::string
    UpdateDataDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UpdateDataDetails::typeName(void)
    {
    	return "UpdateDataDetails";
    }
    
    OpcUaNodeId
    UpdateDataDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)680,0);
    }
    
    OpcUaNodeId
    UpdateDataDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)682, 0);
    }
    
    OpcUaNodeId
    UpdateDataDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)681, 0);
    }
    
    OpcUaNodeId
    UpdateDataDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15280, 0);
    }
    
    void
    UpdateDataDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryUpdateDetails::opcUaBinaryEncode(os);
        performInsertReplace_.opcUaBinaryEncode(os);
        updateValues_.opcUaBinaryEncode(os);
    }
    
    void
    UpdateDataDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryUpdateDetails::opcUaBinaryDecode(is);
        performInsertReplace_.opcUaBinaryDecode(is);
        updateValues_.opcUaBinaryDecode(is);
    }
    
    bool
    UpdateDataDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UpdateDataDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UpdateDataDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UpdateDataDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!updateValues_.xmlEncode(elementTree, "DataValue", xmlns)) return false;
        pt.push_back(std::make_pair("UpdateValues", elementTree));
    
        return true;
    }
    
    bool
    UpdateDataDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UpdateDataDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("PerformInsertReplace");
        if (!tree) return false;
        if (!performInsertReplace_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("UpdateValues");
        if (!tree) return false;
        if (!updateValues_.xmlDecode(*tree, "DataValue", xmlns)) return false;
    
        return true;
    }
    
    bool
    UpdateDataDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UpdateDataDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UpdateDataDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UpdateDataDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    UpdateDataDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UpdateDataDetails* dst = dynamic_cast<UpdateDataDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UpdateDataDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UpdateDataDetails* dst = dynamic_cast<UpdateDataDetails*>(&extensionObjectBase);
    	return *const_cast<UpdateDataDetails*>(this) == *dst;
    }
    
    void
    UpdateDataDetails::out(std::ostream& os)
    {
        os << "PerformInsertReplace="; performInsertReplace_.out(os);
        os << ", UpdateValues="; updateValues_.out(os);
    }

}