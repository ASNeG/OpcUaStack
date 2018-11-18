/*
    DataTypeClass: UABinaryFileDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UABinaryFileDataType.h"

namespace OpcUaStackCore
{
    
    UABinaryFileDataType::UABinaryFileDataType(void)
    : DataTypeSchemaHeader()
    , schemaLocation_()
    , fileHeader_()
    , body_()
    {
    }
    
    UABinaryFileDataType::~UABinaryFileDataType(void)
    {
    }
    
    OpcUaString&
    UABinaryFileDataType::schemaLocation(void)
    {
        return schemaLocation_;
    }
    
    KeyValuePairArray&
    UABinaryFileDataType::fileHeader(void)
    {
        return fileHeader_;
    }
    
    OpcUaVariant&
    UABinaryFileDataType::body(void)
    {
        return body_;
    }
    
    bool
    UABinaryFileDataType::operator==(const UABinaryFileDataType& value)
    {
        UABinaryFileDataType* dst = const_cast<UABinaryFileDataType*>(&value);
        if (schemaLocation_ != dst->schemaLocation()) return false;
        if (fileHeader_ != dst->fileHeader()) return false;
        if (body_ != dst->body()) return false;
        return true;
    }
    
    bool
    UABinaryFileDataType::operator!=(const UABinaryFileDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    UABinaryFileDataType::copyTo(UABinaryFileDataType& value)
    {
        schemaLocation_.copyTo(value.schemaLocation());
        fileHeader_.copyTo(value.fileHeader());
        body_.copyTo(value.body());
    }
    
    UABinaryFileDataType&
    UABinaryFileDataType::operator=(const UABinaryFileDataType& value)
    {
        const_cast<UABinaryFileDataType*>(&value)->copyTo(*this);
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
    UABinaryFileDataType::factory(void)
    {
    	return constructSPtr<UABinaryFileDataType>();
    }
    
    std::string
    UABinaryFileDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UABinaryFileDataType::typeName(void)
    {
    	return "UABinaryFileDataType";
    }
    
    OpcUaNodeId
    UABinaryFileDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15006,0);
    }
    
    OpcUaNodeId
    UABinaryFileDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15422, 0);
    }
    
    OpcUaNodeId
    UABinaryFileDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15531, 0);
    }
    
    OpcUaNodeId
    UABinaryFileDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15714, 0);
    }
    
    void
    UABinaryFileDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        schemaLocation_.opcUaBinaryEncode(os);
        fileHeader_.opcUaBinaryEncode(os);
        body_.opcUaBinaryEncode(os);
    }
    
    void
    UABinaryFileDataType::opcUaBinaryDecode(std::istream& is)
    {
        schemaLocation_.opcUaBinaryDecode(is);
        fileHeader_.opcUaBinaryDecode(is);
        body_.opcUaBinaryDecode(is);
    }
    
    bool
    UABinaryFileDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UABinaryFileDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UABinaryFileDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UABinaryFileDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!schemaLocation_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SchemaLocation", elementTree));
    
        elementTree.clear();
        if (!fileHeader_.xmlEncode(elementTree, "KeyValuePair", xmlns)) return false;
        pt.push_back(std::make_pair("FileHeader", elementTree));
    
        elementTree.clear();
        if (!body_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Body", elementTree));
    
        return true;
    }
    
    bool
    UABinaryFileDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UABinaryFileDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("SchemaLocation");
        if (!tree) return false;
        if (!schemaLocation_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("FileHeader");
        if (!tree) return false;
        if (!fileHeader_.xmlDecode(*tree, "KeyValuePair", xmlns)) return false;
    
        tree = pt.get_child_optional("Body");
        if (!tree) return false;
        if (!body_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    UABinaryFileDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UABinaryFileDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UABinaryFileDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UABinaryFileDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    UABinaryFileDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UABinaryFileDataType* dst = dynamic_cast<UABinaryFileDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UABinaryFileDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UABinaryFileDataType* dst = dynamic_cast<UABinaryFileDataType*>(&extensionObjectBase);
    	return *const_cast<UABinaryFileDataType*>(this) == *dst;
    }
    
    void
    UABinaryFileDataType::out(std::ostream& os)
    {
        os << "SchemaLocation="; schemaLocation_.out(os);
        os << ", FileHeader="; fileHeader_.out(os);
        os << ", Body="; body_.out(os);
    }

}
