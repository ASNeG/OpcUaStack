/*
    DataTypeClass: DatagramWriterGroupTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DatagramWriterGroupTransportDataType.h"

namespace OpcUaStackCore
{
    
    DatagramWriterGroupTransportDataType::DatagramWriterGroupTransportDataType(void)
    : WriterGroupTransportDataType()
    , messageRepeatCount_()
    , messageRepeatDelay_()
    {
    }
    
    DatagramWriterGroupTransportDataType::DatagramWriterGroupTransportDataType(const DatagramWriterGroupTransportDataType& value)
    : WriterGroupTransportDataType()
    , messageRepeatCount_()
    , messageRepeatDelay_()
    {
        const_cast<DatagramWriterGroupTransportDataType*>(&value)->copyTo(*this);
    }
    
    DatagramWriterGroupTransportDataType::~DatagramWriterGroupTransportDataType(void)
    {
    }
    
    OpcUaByte&
    DatagramWriterGroupTransportDataType::messageRepeatCount(void)
    {
        return messageRepeatCount_;
    }
    
    OpcUaDuration&
    DatagramWriterGroupTransportDataType::messageRepeatDelay(void)
    {
        return messageRepeatDelay_;
    }
    
    bool
    DatagramWriterGroupTransportDataType::operator==(const DatagramWriterGroupTransportDataType& value)
    {
        DatagramWriterGroupTransportDataType* dst = const_cast<DatagramWriterGroupTransportDataType*>(&value);
        if (messageRepeatCount_ != dst->messageRepeatCount()) return false;
        if (messageRepeatDelay_ != dst->messageRepeatDelay()) return false;
        return true;
    }
    
    bool
    DatagramWriterGroupTransportDataType::operator!=(const DatagramWriterGroupTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DatagramWriterGroupTransportDataType::copyTo(DatagramWriterGroupTransportDataType& value)
    {
        value.messageRepeatCount_ = messageRepeatCount_;
        value.messageRepeatDelay_ = messageRepeatDelay_;
    }
    
    DatagramWriterGroupTransportDataType&
    DatagramWriterGroupTransportDataType::operator=(const DatagramWriterGroupTransportDataType& value)
    {
        const_cast<DatagramWriterGroupTransportDataType*>(&value)->copyTo(*this);
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
    DatagramWriterGroupTransportDataType::factory(void)
    {
    	return constructSPtr<DatagramWriterGroupTransportDataType>();
    }
    
    std::string
    DatagramWriterGroupTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DatagramWriterGroupTransportDataType::typeName(void)
    {
    	return "DatagramWriterGroupTransportDataType";
    }
    
    OpcUaNodeId
    DatagramWriterGroupTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15532,0);
    }
    
    OpcUaNodeId
    DatagramWriterGroupTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21155, 0);
    }
    
    OpcUaNodeId
    DatagramWriterGroupTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21179, 0);
    }
    
    OpcUaNodeId
    DatagramWriterGroupTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21203, 0);
    }
    
    void
    DatagramWriterGroupTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        WriterGroupTransportDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,messageRepeatCount_);
        OpcUaNumber::opcUaBinaryEncode(os,messageRepeatDelay_);
    }
    
    void
    DatagramWriterGroupTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
        WriterGroupTransportDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,messageRepeatCount_);
        OpcUaNumber::opcUaBinaryDecode(is,messageRepeatDelay_);
    }
    
    bool
    DatagramWriterGroupTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DatagramWriterGroupTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DatagramWriterGroupTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, messageRepeatCount_))
        {
            Log(Error, "DatagramWriterGroupTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MessageRepeatCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, messageRepeatDelay_))
        {
            Log(Error, "DatagramWriterGroupTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MessageRepeatDelay", elementTree));
    
        return true;
    }
    
    bool
    DatagramWriterGroupTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramWriterGroupTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DatagramWriterGroupTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("MessageRepeatCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramWriterGroupTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, messageRepeatCount_)) {
            Log(Error, "DatagramWriterGroupTransportDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MessageRepeatDelay");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramWriterGroupTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, messageRepeatDelay_)) {
            Log(Error, "DatagramWriterGroupTransportDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DatagramWriterGroupTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, messageRepeatCount_))
        {
    	     Log(Error, "DatagramWriterGroupTransportDataType json encoder error")
    		     .parameter("Element", "messageRepeatCount_");
           return false;
        }
        pt.push_back(std::make_pair("MessageRepeatCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, messageRepeatDelay_))
        {
    	     Log(Error, "DatagramWriterGroupTransportDataType json encoder error")
    		     .parameter("Element", "messageRepeatDelay_");
           return false;
        }
        pt.push_back(std::make_pair("MessageRepeatDelay", elementTree));
    
        return true;
    }
    
    bool
    DatagramWriterGroupTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "MessageRepeatCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramWriterGroupTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, messageRepeatCount_)) {
            Log(Error, "DatagramWriterGroupTransportDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MessageRepeatDelay";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramWriterGroupTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, messageRepeatDelay_)) {
            Log(Error, "DatagramWriterGroupTransportDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DatagramWriterGroupTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DatagramWriterGroupTransportDataType* dst = dynamic_cast<DatagramWriterGroupTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DatagramWriterGroupTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DatagramWriterGroupTransportDataType* dst = dynamic_cast<DatagramWriterGroupTransportDataType*>(&extensionObjectBase);
    	return *const_cast<DatagramWriterGroupTransportDataType*>(this) == *dst;
    }
    
    void
    DatagramWriterGroupTransportDataType::out(std::ostream& os)
    {
        os << "MessageRepeatCount=" << messageRepeatCount_;
        os << ", MessageRepeatDelay=" << messageRepeatDelay_;
    }

}
