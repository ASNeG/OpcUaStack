/*
    DataTypeClass: StatusResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"

namespace OpcUaStackCore
{
    
    StatusResult::StatusResult(void)
    : Object()
    , ExtensionObjectBase()
    , statusCode_()
    , diagnosticInfo_()
    {
    }
    
    StatusResult::~StatusResult(void)
    {
    }
    
    OpcUaStatus&
    StatusResult::statusCode(void)
    {
        return statusCode_;
    }
    
    OpcUaDiagnosticInfo&
    StatusResult::diagnosticInfo(void)
    {
        return diagnosticInfo_;
    }
    
    bool
    StatusResult::operator==(const StatusResult& value)
    {
        StatusResult* dst = const_cast<StatusResult*>(&value);
        if (statusCode_ != dst->statusCode()) return false;
        if (diagnosticInfo_ != dst->diagnosticInfo()) return false;
        return true;
    }
    
    bool
    StatusResult::operator!=(const StatusResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    StatusResult::copyTo(StatusResult& value)
    {
        statusCode_.copyTo(value.statusCode());
        diagnosticInfo_.copyTo(value.diagnosticInfo());
    }
    
    StatusResult&
    StatusResult::operator=(const StatusResult& value)
    {
        const_cast<StatusResult*>(&value)->copyTo(*this);
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
    StatusResult::factory(void)
    {
    	return constructSPtr<StatusResult>();
    }
    
    std::string
    StatusResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StatusResult::typeName(void)
    {
    	return "StatusResult";
    }
    
    OpcUaNodeId
    StatusResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)299,0);
    }
    
    OpcUaNodeId
    StatusResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)301, 0);
    }
    
    OpcUaNodeId
    StatusResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)300, 0);
    }
    
    OpcUaNodeId
    StatusResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15371, 0);
    }
    
    void
    StatusResult::opcUaBinaryEncode(std::ostream& os) const
    {
        statusCode_.opcUaBinaryEncode(os);
        diagnosticInfo_.opcUaBinaryEncode(os);
    }
    
    void
    StatusResult::opcUaBinaryDecode(std::istream& is)
    {
        statusCode_.opcUaBinaryDecode(is);
        diagnosticInfo_.opcUaBinaryDecode(is);
    }
    
    bool
    StatusResult::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    StatusResult::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    StatusResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StatusResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!statusCode_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StatusCode", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfo_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DiagnosticInfo", elementTree));
    
        return true;
    }
    
    bool
    StatusResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StatusResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("StatusCode");
        if (!tree) return false;
        if (!statusCode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DiagnosticInfo");
        if (!tree) return false;
        if (!diagnosticInfo_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    StatusResult::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    StatusResult::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    StatusResult::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    StatusResult::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    StatusResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StatusResult* dst = dynamic_cast<StatusResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StatusResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StatusResult* dst = dynamic_cast<StatusResult*>(&extensionObjectBase);
    	return *const_cast<StatusResult*>(this) == *dst;
    }
    
    void
    StatusResult::out(std::ostream& os)
    {
        os << "StatusCode="; statusCode_.out(os);
        os << ", DiagnosticInfo="; diagnosticInfo_.out(os);
    }

}
