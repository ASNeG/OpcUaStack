/*
    DataTypeClass: UpdateStructureDataDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UpdateStructureDataDetails.h"

namespace OpcUaStackCore
{
    
    UpdateStructureDataDetails::UpdateStructureDataDetails(void)
    : HistoryUpdateDetails()
    , performInsertReplace_()
    , updateValues_()
    {
    }
    
    UpdateStructureDataDetails::UpdateStructureDataDetails(const UpdateStructureDataDetails& value)
    : HistoryUpdateDetails()
    , performInsertReplace_()
    , updateValues_()
    {
        const_cast<UpdateStructureDataDetails*>(&value)->copyTo(*this);
    }
    
    UpdateStructureDataDetails::~UpdateStructureDataDetails(void)
    {
    }
    
    PerformUpdateType&
    UpdateStructureDataDetails::performInsertReplace(void)
    {
        return performInsertReplace_;
    }
    
    OpcUaDataValueArray&
    UpdateStructureDataDetails::updateValues(void)
    {
        return updateValues_;
    }
    
    bool
    UpdateStructureDataDetails::operator==(const UpdateStructureDataDetails& value)
    {
        UpdateStructureDataDetails* dst = const_cast<UpdateStructureDataDetails*>(&value);
        if (performInsertReplace_ != dst->performInsertReplace()) return false;
        if (updateValues_ != dst->updateValues()) return false;
        return true;
    }
    
    bool
    UpdateStructureDataDetails::operator!=(const UpdateStructureDataDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    UpdateStructureDataDetails::copyTo(UpdateStructureDataDetails& value)
    {
        performInsertReplace_.copyTo(value.performInsertReplace());
        updateValues_.copyTo(value.updateValues());
    }
    
    UpdateStructureDataDetails&
    UpdateStructureDataDetails::operator=(const UpdateStructureDataDetails& value)
    {
        const_cast<UpdateStructureDataDetails*>(&value)->copyTo(*this);
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
    UpdateStructureDataDetails::factory(void)
    {
    	return constructSPtr<UpdateStructureDataDetails>();
    }
    
    std::string
    UpdateStructureDataDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UpdateStructureDataDetails::typeName(void)
    {
    	return "UpdateStructureDataDetails";
    }
    
    OpcUaNodeId
    UpdateStructureDataDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11295,0);
    }
    
    OpcUaNodeId
    UpdateStructureDataDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11300, 0);
    }
    
    OpcUaNodeId
    UpdateStructureDataDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11296, 0);
    }
    
    OpcUaNodeId
    UpdateStructureDataDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15281, 0);
    }
    
    void
    UpdateStructureDataDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryUpdateDetails::opcUaBinaryEncode(os);
        performInsertReplace_.opcUaBinaryEncode(os);
        updateValues_.opcUaBinaryEncode(os);
    }
    
    void
    UpdateStructureDataDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryUpdateDetails::opcUaBinaryDecode(is);
        performInsertReplace_.opcUaBinaryDecode(is);
        updateValues_.opcUaBinaryDecode(is);
    }
    
    bool
    UpdateStructureDataDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateStructureDataDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UpdateStructureDataDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateStructureDataDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!updateValues_.xmlEncode(elementTree, "DataValue", xmlns)) {
            Log(Error, "UpdateStructureDataDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UpdateValues", elementTree));
    
        return true;
    }
    
    bool
    UpdateStructureDataDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateStructureDataDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UpdateStructureDataDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PerformInsertReplace");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateStructureDataDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!performInsertReplace_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UpdateStructureDataDetails decode xml error - decode failed")
                .parameter("Element", "PerformInsertReplace");
            return false;
        }
    
        elementName = xmlns.addPrefix("UpdateValues");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateStructureDataDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!updateValues_.xmlDecode(*tree, "DataValue", xmlns)) {
            Log(Error, "UpdateStructureDataDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    UpdateStructureDataDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.jsonEncode(elementTree))
        {
    	     Log(Error, "UpdateStructureDataDetails json encoder error")
    		     .parameter("Element", "performInsertReplace_");
            return false;
        }
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!updateValues_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "UpdateStructureDataDetails json encoder error")
    		     .parameter("Element", "updateValues_");
            return false;
        }
        pt.push_back(std::make_pair("UpdateValues", elementTree));
    
        return true;
    }
    
    bool
    UpdateStructureDataDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "PerformInsertReplace";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateStructureDataDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!performInsertReplace_.jsonDecode(*tree)) {
            Log(Error, "UpdateStructureDataDetails decode json error - decode failed")
                .parameter("Element", "PerformInsertReplace");
            return false;
        }
    
        elementName = "UpdateValues";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateStructureDataDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!updateValues_.jsonDecode(*tree, "")) {
            Log(Error, "UpdateStructureDataDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    UpdateStructureDataDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UpdateStructureDataDetails* dst = dynamic_cast<UpdateStructureDataDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UpdateStructureDataDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UpdateStructureDataDetails* dst = dynamic_cast<UpdateStructureDataDetails*>(&extensionObjectBase);
    	return *const_cast<UpdateStructureDataDetails*>(this) == *dst;
    }
    
    void
    UpdateStructureDataDetails::out(std::ostream& os)
    {
        os << "PerformInsertReplace="; performInsertReplace_.out(os);
        os << ", UpdateValues="; updateValues_.out(os);
    }

}
