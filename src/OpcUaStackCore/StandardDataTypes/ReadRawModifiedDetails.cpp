/*
    DataTypeClass: ReadRawModifiedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"

namespace OpcUaStackCore
{
    
    ReadRawModifiedDetails::ReadRawModifiedDetails(void)
    : HistoryReadDetails()
    , isReadModified_()
    , startTime_()
    , endTime_()
    , numValuesPerNode_()
    , returnBounds_()
    {
    }
    
    ReadRawModifiedDetails::~ReadRawModifiedDetails(void)
    {
    }
    
    OpcUaBoolean&
    ReadRawModifiedDetails::isReadModified(void)
    {
        return isReadModified_;
    }
    
    OpcUaUtcTime&
    ReadRawModifiedDetails::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    ReadRawModifiedDetails::endTime(void)
    {
        return endTime_;
    }
    
    OpcUaCounter&
    ReadRawModifiedDetails::numValuesPerNode(void)
    {
        return numValuesPerNode_;
    }
    
    OpcUaBoolean&
    ReadRawModifiedDetails::returnBounds(void)
    {
        return returnBounds_;
    }
    
    bool
    ReadRawModifiedDetails::operator==(const ReadRawModifiedDetails& value)
    {
        ReadRawModifiedDetails* dst = const_cast<ReadRawModifiedDetails*>(&value);
        if (isReadModified_ != dst->isReadModified()) return false;
        if (startTime_ != dst->startTime()) return false;
        if (endTime_ != dst->endTime()) return false;
        if (numValuesPerNode_ != dst->numValuesPerNode()) return false;
        if (returnBounds_ != dst->returnBounds()) return false;
        return true;
    }
    
    bool
    ReadRawModifiedDetails::operator!=(const ReadRawModifiedDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadRawModifiedDetails::copyTo(ReadRawModifiedDetails& value)
    {
        value.isReadModified_ = isReadModified_;
        startTime_.copyTo(value.startTime());
        endTime_.copyTo(value.endTime());
        value.numValuesPerNode_ = numValuesPerNode_;
        value.returnBounds_ = returnBounds_;
    }
    
    ReadRawModifiedDetails&
    ReadRawModifiedDetails::operator=(const ReadRawModifiedDetails& value)
    {
        const_cast<ReadRawModifiedDetails*>(&value)->copyTo(*this);
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
    ReadRawModifiedDetails::factory(void)
    {
    	return constructSPtr<ReadRawModifiedDetails>();
    }
    
    std::string
    ReadRawModifiedDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadRawModifiedDetails::typeName(void)
    {
    	return "ReadRawModifiedDetails";
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)647,0);
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)649, 0);
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)648, 0);
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15263, 0);
    }
    
    void
    ReadRawModifiedDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isReadModified_);
        startTime_.opcUaBinaryEncode(os);
        endTime_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,numValuesPerNode_);
        OpcUaNumber::opcUaBinaryEncode(os,returnBounds_);
    }
    
    void
    ReadRawModifiedDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isReadModified_);
        startTime_.opcUaBinaryDecode(is);
        endTime_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,numValuesPerNode_);
        OpcUaNumber::opcUaBinaryDecode(is,returnBounds_);
    }
    
    bool
    ReadRawModifiedDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ReadRawModifiedDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ReadRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isReadModified_)) return false;
        pt.push_back(std::make_pair("IsReadModified", elementTree));
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, numValuesPerNode_)) return false;
        pt.push_back(std::make_pair("NumValuesPerNode", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, returnBounds_)) return false;
        pt.push_back(std::make_pair("ReturnBounds", elementTree));
    
        return true;
    }
    
    bool
    ReadRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("IsReadModified");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, isReadModified_)) return false;
    
        tree = pt.get_child_optional("StartTime");
        if (!tree) return false;
        if (!startTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EndTime");
        if (!tree) return false;
        if (!endTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("NumValuesPerNode");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, numValuesPerNode_)) return false;
    
        tree = pt.get_child_optional("ReturnBounds");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, returnBounds_)) return false;
    
        return true;
    }
    
    bool
    ReadRawModifiedDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ReadRawModifiedDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ReadRawModifiedDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ReadRawModifiedDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ReadRawModifiedDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadRawModifiedDetails* dst = dynamic_cast<ReadRawModifiedDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadRawModifiedDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadRawModifiedDetails* dst = dynamic_cast<ReadRawModifiedDetails*>(&extensionObjectBase);
    	return *const_cast<ReadRawModifiedDetails*>(this) == *dst;
    }
    
    void
    ReadRawModifiedDetails::out(std::ostream& os)
    {
        os << "IsReadModified=" << isReadModified_;
        os << ", StartTime="; startTime_.out(os);
        os << ", EndTime="; endTime_.out(os);
        os << ", NumValuesPerNode=" << numValuesPerNode_;
        os << ", ReturnBounds=" << returnBounds_;
    }

}
