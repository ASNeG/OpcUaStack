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
    
    UpdateDataDetails::UpdateDataDetails(const UpdateDataDetails& value)
    : HistoryUpdateDetails()
    , performInsertReplace_()
    , updateValues_()
    {
        const_cast<UpdateDataDetails*>(&value)->copyTo(*this);
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
    UpdateDataDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateDataDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UpdateDataDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateDataDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!updateValues_.xmlEncode(elementTree, "DataValue", xmlns)) {
            Log(Error, "UpdateDataDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UpdateValues", elementTree));
    
        return true;
    }
    
    bool
    UpdateDataDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateDataDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UpdateDataDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PerformInsertReplace");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateDataDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!performInsertReplace_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UpdateDataDetails decode xml error - decode failed")
                .parameter("Element", "PerformInsertReplace");
            return false;
        }
    
        elementName = xmlns.addPrefix("UpdateValues");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateDataDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!updateValues_.xmlDecode(*tree, "DataValue", xmlns)) {
            Log(Error, "UpdateDataDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    UpdateDataDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.jsonEncode(elementTree))
        {
    	     Log(Error, "UpdateDataDetails json encoder error")
    		     .parameter("Element", "performInsertReplace_");
            return false;
        }
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!updateValues_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "UpdateDataDetails json encoder error")
    		     .parameter("Element", "updateValues_");
            return false;
        }
        pt.push_back(std::make_pair("UpdateValues", elementTree));
    
        return true;
    }
    
    bool
    UpdateDataDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "PerformInsertReplace";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateDataDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!performInsertReplace_.jsonDecode(*tree)) {
            Log(Error, "UpdateDataDetails decode json error - decode failed")
                .parameter("Element", "PerformInsertReplace");
            return false;
        }
    
        elementName = "UpdateValues";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateDataDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!updateValues_.jsonDecode(*tree, "")) {
            Log(Error, "UpdateDataDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
