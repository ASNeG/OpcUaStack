/*
    DataTypeClass: EndpointConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EndpointConfiguration.h"

namespace OpcUaStackCore
{
    
    EndpointConfiguration::EndpointConfiguration(void)
    : Object()
    , ExtensionObjectBase()
    , operationTimeout_()
    , useBinaryEncoding_()
    , maxStringLength_()
    , maxByteStringLength_()
    , maxArrayLength_()
    , maxMessageSize_()
    , maxBufferSize_()
    , channelLifetime_()
    , securityTokenLifetime_()
    {
    }
    
    EndpointConfiguration::EndpointConfiguration(const EndpointConfiguration& value)
    : Object()
    , ExtensionObjectBase()
    , operationTimeout_()
    , useBinaryEncoding_()
    , maxStringLength_()
    , maxByteStringLength_()
    , maxArrayLength_()
    , maxMessageSize_()
    , maxBufferSize_()
    , channelLifetime_()
    , securityTokenLifetime_()
    {
        const_cast<EndpointConfiguration*>(&value)->copyTo(*this);
    }
    
    EndpointConfiguration::~EndpointConfiguration(void)
    {
    }
    
    OpcUaInt32&
    EndpointConfiguration::operationTimeout(void)
    {
        return operationTimeout_;
    }
    
    OpcUaBoolean&
    EndpointConfiguration::useBinaryEncoding(void)
    {
        return useBinaryEncoding_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::maxStringLength(void)
    {
        return maxStringLength_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::maxByteStringLength(void)
    {
        return maxByteStringLength_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::maxArrayLength(void)
    {
        return maxArrayLength_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::maxMessageSize(void)
    {
        return maxMessageSize_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::maxBufferSize(void)
    {
        return maxBufferSize_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::channelLifetime(void)
    {
        return channelLifetime_;
    }
    
    OpcUaInt32&
    EndpointConfiguration::securityTokenLifetime(void)
    {
        return securityTokenLifetime_;
    }
    
    bool
    EndpointConfiguration::operator==(const EndpointConfiguration& value)
    {
        EndpointConfiguration* dst = const_cast<EndpointConfiguration*>(&value);
        if (operationTimeout_ != dst->operationTimeout()) return false;
        if (useBinaryEncoding_ != dst->useBinaryEncoding()) return false;
        if (maxStringLength_ != dst->maxStringLength()) return false;
        if (maxByteStringLength_ != dst->maxByteStringLength()) return false;
        if (maxArrayLength_ != dst->maxArrayLength()) return false;
        if (maxMessageSize_ != dst->maxMessageSize()) return false;
        if (maxBufferSize_ != dst->maxBufferSize()) return false;
        if (channelLifetime_ != dst->channelLifetime()) return false;
        if (securityTokenLifetime_ != dst->securityTokenLifetime()) return false;
        return true;
    }
    
    bool
    EndpointConfiguration::operator!=(const EndpointConfiguration& value)
    {
        return !this->operator==(value);
    }
    
    void
    EndpointConfiguration::copyTo(EndpointConfiguration& value)
    {
        value.operationTimeout_ = operationTimeout_;
        value.useBinaryEncoding_ = useBinaryEncoding_;
        value.maxStringLength_ = maxStringLength_;
        value.maxByteStringLength_ = maxByteStringLength_;
        value.maxArrayLength_ = maxArrayLength_;
        value.maxMessageSize_ = maxMessageSize_;
        value.maxBufferSize_ = maxBufferSize_;
        value.channelLifetime_ = channelLifetime_;
        value.securityTokenLifetime_ = securityTokenLifetime_;
    }
    
    EndpointConfiguration&
    EndpointConfiguration::operator=(const EndpointConfiguration& value)
    {
        const_cast<EndpointConfiguration*>(&value)->copyTo(*this);
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
    EndpointConfiguration::factory(void)
    {
    	return constructSPtr<EndpointConfiguration>();
    }
    
    std::string
    EndpointConfiguration::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EndpointConfiguration::typeName(void)
    {
    	return "EndpointConfiguration";
    }
    
    OpcUaNodeId
    EndpointConfiguration::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)331,0);
    }
    
    OpcUaNodeId
    EndpointConfiguration::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)333, 0);
    }
    
    OpcUaNodeId
    EndpointConfiguration::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)332, 0);
    }
    
    OpcUaNodeId
    EndpointConfiguration::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15199, 0);
    }
    
    void
    EndpointConfiguration::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,operationTimeout_);
        OpcUaNumber::opcUaBinaryEncode(os,useBinaryEncoding_);
        OpcUaNumber::opcUaBinaryEncode(os,maxStringLength_);
        OpcUaNumber::opcUaBinaryEncode(os,maxByteStringLength_);
        OpcUaNumber::opcUaBinaryEncode(os,maxArrayLength_);
        OpcUaNumber::opcUaBinaryEncode(os,maxMessageSize_);
        OpcUaNumber::opcUaBinaryEncode(os,maxBufferSize_);
        OpcUaNumber::opcUaBinaryEncode(os,channelLifetime_);
        OpcUaNumber::opcUaBinaryEncode(os,securityTokenLifetime_);
    }
    
    void
    EndpointConfiguration::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,operationTimeout_);
        OpcUaNumber::opcUaBinaryDecode(is,useBinaryEncoding_);
        OpcUaNumber::opcUaBinaryDecode(is,maxStringLength_);
        OpcUaNumber::opcUaBinaryDecode(is,maxByteStringLength_);
        OpcUaNumber::opcUaBinaryDecode(is,maxArrayLength_);
        OpcUaNumber::opcUaBinaryDecode(is,maxMessageSize_);
        OpcUaNumber::opcUaBinaryDecode(is,maxBufferSize_);
        OpcUaNumber::opcUaBinaryDecode(is,channelLifetime_);
        OpcUaNumber::opcUaBinaryDecode(is,securityTokenLifetime_);
    }
    
    bool
    EndpointConfiguration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointConfiguration encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EndpointConfiguration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, operationTimeout_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("OperationTimeout", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useBinaryEncoding_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UseBinaryEncoding", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxStringLength_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxByteStringLength_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxByteStringLength", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxArrayLength_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxArrayLength", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxMessageSize_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxMessageSize", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxBufferSize_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxBufferSize", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, channelLifetime_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ChannelLifetime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, securityTokenLifetime_))
        {
            Log(Error, "EndpointConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityTokenLifetime", elementTree));
    
        return true;
    }
    
    bool
    EndpointConfiguration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EndpointConfiguration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("OperationTimeout");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, operationTimeout_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UseBinaryEncoding");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, useBinaryEncoding_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxStringLength");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxStringLength_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxByteStringLength");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxByteStringLength_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxArrayLength");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxArrayLength_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxMessageSize");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxMessageSize_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxBufferSize");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxBufferSize_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ChannelLifetime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, channelLifetime_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityTokenLifetime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, securityTokenLifetime_)) {
            Log(Error, "EndpointConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    EndpointConfiguration::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, operationTimeout_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "operationTimeout_");
           return false;
        }
        pt.push_back(std::make_pair("OperationTimeout", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, useBinaryEncoding_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "useBinaryEncoding_");
           return false;
        }
        pt.push_back(std::make_pair("UseBinaryEncoding", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxStringLength_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "maxStringLength_");
           return false;
        }
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxByteStringLength_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "maxByteStringLength_");
           return false;
        }
        pt.push_back(std::make_pair("MaxByteStringLength", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxArrayLength_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "maxArrayLength_");
           return false;
        }
        pt.push_back(std::make_pair("MaxArrayLength", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxMessageSize_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "maxMessageSize_");
           return false;
        }
        pt.push_back(std::make_pair("MaxMessageSize", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxBufferSize_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "maxBufferSize_");
           return false;
        }
        pt.push_back(std::make_pair("MaxBufferSize", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, channelLifetime_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "channelLifetime_");
           return false;
        }
        pt.push_back(std::make_pair("ChannelLifetime", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, securityTokenLifetime_))
        {
    	     Log(Error, "EndpointConfiguration json encoder error")
    		     .parameter("Element", "securityTokenLifetime_");
           return false;
        }
        pt.push_back(std::make_pair("SecurityTokenLifetime", elementTree));
    
        return true;
    }
    
    bool
    EndpointConfiguration::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "OperationTimeout";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, operationTimeout_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "UseBinaryEncoding";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, useBinaryEncoding_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxStringLength";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxStringLength_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxByteStringLength";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxByteStringLength_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxArrayLength";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxArrayLength_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxMessageSize";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxMessageSize_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxBufferSize";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxBufferSize_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ChannelLifetime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, channelLifetime_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "SecurityTokenLifetime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, securityTokenLifetime_)) {
            Log(Error, "EndpointConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    EndpointConfiguration::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EndpointConfiguration* dst = dynamic_cast<EndpointConfiguration*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EndpointConfiguration::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EndpointConfiguration* dst = dynamic_cast<EndpointConfiguration*>(&extensionObjectBase);
    	return *const_cast<EndpointConfiguration*>(this) == *dst;
    }
    
    void
    EndpointConfiguration::out(std::ostream& os)
    {
        os << "OperationTimeout=" << operationTimeout_;
        os << ", UseBinaryEncoding=" << useBinaryEncoding_;
        os << ", MaxStringLength=" << maxStringLength_;
        os << ", MaxByteStringLength=" << maxByteStringLength_;
        os << ", MaxArrayLength=" << maxArrayLength_;
        os << ", MaxMessageSize=" << maxMessageSize_;
        os << ", MaxBufferSize=" << maxBufferSize_;
        os << ", ChannelLifetime=" << channelLifetime_;
        os << ", SecurityTokenLifetime=" << securityTokenLifetime_;
    }

}
