/*
    DataTypeClass: PublishedDataSetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PublishedDataSetDataType.h"

namespace OpcUaStackCore
{
    
    PublishedDataSetDataType::PublishedDataSetDataType(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , dataSetFolder_()
    , dataSetMetaData_()
    , extensionFields_()
    , dataSetSource_()
    {
    }
    
    PublishedDataSetDataType::PublishedDataSetDataType(const PublishedDataSetDataType& value)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , dataSetFolder_()
    , dataSetMetaData_()
    , extensionFields_()
    , dataSetSource_()
    {
        const_cast<PublishedDataSetDataType*>(&value)->copyTo(*this);
    }
    
    PublishedDataSetDataType::~PublishedDataSetDataType(void)
    {
    }
    
    OpcUaString&
    PublishedDataSetDataType::name(void)
    {
        return name_;
    }
    
    OpcUaStringArray&
    PublishedDataSetDataType::dataSetFolder(void)
    {
        return dataSetFolder_;
    }
    
    DataSetMetaDataType&
    PublishedDataSetDataType::dataSetMetaData(void)
    {
        return dataSetMetaData_;
    }
    
    KeyValuePairArray&
    PublishedDataSetDataType::extensionFields(void)
    {
        return extensionFields_;
    }
    
    OpcUaExtensibleParameter&
    PublishedDataSetDataType::dataSetSource(void)
    {
        return dataSetSource_;
    }
    
    bool
    PublishedDataSetDataType::operator==(const PublishedDataSetDataType& value)
    {
        PublishedDataSetDataType* dst = const_cast<PublishedDataSetDataType*>(&value);
        if (name_ != dst->name()) return false;
        if (dataSetFolder_ != dst->dataSetFolder()) return false;
        if (dataSetMetaData_ != dst->dataSetMetaData()) return false;
        if (extensionFields_ != dst->extensionFields()) return false;
        if (dataSetSource_ != dst->dataSetSource()) return false;
        return true;
    }
    
    bool
    PublishedDataSetDataType::operator!=(const PublishedDataSetDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PublishedDataSetDataType::copyTo(PublishedDataSetDataType& value)
    {
        name_.copyTo(value.name());
        dataSetFolder_.copyTo(value.dataSetFolder());
        dataSetMetaData_.copyTo(value.dataSetMetaData());
        extensionFields_.copyTo(value.extensionFields());
        dataSetSource_.copyTo(value.dataSetSource());
    }
    
    PublishedDataSetDataType&
    PublishedDataSetDataType::operator=(const PublishedDataSetDataType& value)
    {
        const_cast<PublishedDataSetDataType*>(&value)->copyTo(*this);
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
    PublishedDataSetDataType::factory(void)
    {
    	return constructSPtr<PublishedDataSetDataType>();
    }
    
    std::string
    PublishedDataSetDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PublishedDataSetDataType::typeName(void)
    {
    	return "PublishedDataSetDataType";
    }
    
    OpcUaNodeId
    PublishedDataSetDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15578,0);
    }
    
    OpcUaNodeId
    PublishedDataSetDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15677, 0);
    }
    
    OpcUaNodeId
    PublishedDataSetDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15951, 0);
    }
    
    OpcUaNodeId
    PublishedDataSetDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16152, 0);
    }
    
    void
    PublishedDataSetDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        dataSetFolder_.opcUaBinaryEncode(os);
        dataSetMetaData_.opcUaBinaryEncode(os);
        extensionFields_.opcUaBinaryEncode(os);
        dataSetSource_.opcUaBinaryEncode(os);
    }
    
    void
    PublishedDataSetDataType::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        dataSetFolder_.opcUaBinaryDecode(is);
        dataSetMetaData_.opcUaBinaryDecode(is);
        extensionFields_.opcUaBinaryDecode(is);
        dataSetSource_.opcUaBinaryDecode(is);
    }
    
    bool
    PublishedDataSetDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedDataSetDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedDataSetDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedDataSetDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!dataSetFolder_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "PublishedDataSetDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetFolder", elementTree));
    
        elementTree.clear();
        if (!dataSetMetaData_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedDataSetDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMetaData", elementTree));
    
        elementTree.clear();
        if (!extensionFields_.xmlEncode(elementTree, "KeyValuePair", xmlns)) {
            Log(Error, "PublishedDataSetDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ExtensionFields", elementTree));
    
        elementTree.clear();
        if (!dataSetSource_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedDataSetDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetSource", elementTree));
    
        return true;
    }
    
    bool
    PublishedDataSetDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedDataSetDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedDataSetDataType decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetFolder");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetFolder_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "PublishedDataSetDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetMetaData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetMetaData_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedDataSetDataType decode xml error - decode failed")
                .parameter("Element", "DataSetMetaData");
            return false;
        }
    
        elementName = xmlns.addPrefix("ExtensionFields");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!extensionFields_.xmlDecode(*tree, "KeyValuePair", xmlns)) {
            Log(Error, "PublishedDataSetDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetSource");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetSource_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedDataSetDataType decode xml error - decode failed")
                .parameter("Element", "DataSetSource");
            return false;
        }
    
        return true;
    }
    
    bool
    PublishedDataSetDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedDataSetDataType json encoder error")
    		     .parameter("Element", "name_");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!dataSetFolder_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PublishedDataSetDataType json encoder error")
    		     .parameter("Element", "dataSetFolder_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetFolder", elementTree));
    
        elementTree.clear();
        if (!dataSetMetaData_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedDataSetDataType json encoder error")
    		     .parameter("Element", "dataSetMetaData_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMetaData", elementTree));
    
        elementTree.clear();
        if (!extensionFields_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PublishedDataSetDataType json encoder error")
    		     .parameter("Element", "extensionFields_");
            return false;
        }
        pt.push_back(std::make_pair("ExtensionFields", elementTree));
    
        elementTree.clear();
        if (!dataSetSource_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedDataSetDataType json encoder error")
    		     .parameter("Element", "dataSetSource_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetSource", elementTree));
    
        return true;
    }
    
    bool
    PublishedDataSetDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Name";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.jsonDecode(*tree)) {
            Log(Error, "PublishedDataSetDataType decode json error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = "DataSetFolder";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetFolder_.jsonDecode(*tree, "")) {
            Log(Error, "PublishedDataSetDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetMetaData";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetMetaData_.jsonDecode(*tree)) {
            Log(Error, "PublishedDataSetDataType decode json error - decode failed")
                .parameter("Element", "DataSetMetaData");
            return false;
        }
    
        elementName = "ExtensionFields";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!extensionFields_.jsonDecode(*tree, "")) {
            Log(Error, "PublishedDataSetDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetSource";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataSetDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetSource_.jsonDecode(*tree)) {
            Log(Error, "PublishedDataSetDataType decode json error - decode failed")
                .parameter("Element", "DataSetSource");
            return false;
        }
    
        return true;
    }
    
    void
    PublishedDataSetDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PublishedDataSetDataType* dst = dynamic_cast<PublishedDataSetDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PublishedDataSetDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PublishedDataSetDataType* dst = dynamic_cast<PublishedDataSetDataType*>(&extensionObjectBase);
    	return *const_cast<PublishedDataSetDataType*>(this) == *dst;
    }
    
    void
    PublishedDataSetDataType::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", DataSetFolder="; dataSetFolder_.out(os);
        os << ", DataSetMetaData="; dataSetMetaData_.out(os);
        os << ", ExtensionFields="; extensionFields_.out(os);
        os << ", DataSetSource="; dataSetSource_.out(os);
    }

}
