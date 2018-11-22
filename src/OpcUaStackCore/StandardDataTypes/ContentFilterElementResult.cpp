/*
    DataTypeClass: ContentFilterElementResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ContentFilterElementResult.h"

namespace OpcUaStackCore
{
    
    ContentFilterElementResult::ContentFilterElementResult(void)
    : Object()
    , ExtensionObjectBase()
    , statusCode_()
    , operandStatusCodes_()
    , operandDiagnosticInfos_()
    {
    }
    
    ContentFilterElementResult::~ContentFilterElementResult(void)
    {
    }
    
    OpcUaStatus&
    ContentFilterElementResult::statusCode(void)
    {
        return statusCode_;
    }
    
    OpcUaStatusArray&
    ContentFilterElementResult::operandStatusCodes(void)
    {
        return operandStatusCodes_;
    }
    
    OpcUaDiagnosticInfoArray&
    ContentFilterElementResult::operandDiagnosticInfos(void)
    {
        return operandDiagnosticInfos_;
    }
    
    bool
    ContentFilterElementResult::operator==(const ContentFilterElementResult& value)
    {
        ContentFilterElementResult* dst = const_cast<ContentFilterElementResult*>(&value);
        if (statusCode_ != dst->statusCode()) return false;
        if (operandStatusCodes_ != dst->operandStatusCodes()) return false;
        if (operandDiagnosticInfos_ != dst->operandDiagnosticInfos()) return false;
        return true;
    }
    
    bool
    ContentFilterElementResult::operator!=(const ContentFilterElementResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    ContentFilterElementResult::copyTo(ContentFilterElementResult& value)
    {
        statusCode_.copyTo(value.statusCode());
        operandStatusCodes_.copyTo(value.operandStatusCodes());
        operandDiagnosticInfos_.copyTo(value.operandDiagnosticInfos());
    }
    
    ContentFilterElementResult&
    ContentFilterElementResult::operator=(const ContentFilterElementResult& value)
    {
        const_cast<ContentFilterElementResult*>(&value)->copyTo(*this);
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
    ContentFilterElementResult::factory(void)
    {
    	return constructSPtr<ContentFilterElementResult>();
    }
    
    std::string
    ContentFilterElementResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ContentFilterElementResult::typeName(void)
    {
    	return "ContentFilterElementResult";
    }
    
    OpcUaNodeId
    ContentFilterElementResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)604,0);
    }
    
    OpcUaNodeId
    ContentFilterElementResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)606, 0);
    }
    
    OpcUaNodeId
    ContentFilterElementResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)605, 0);
    }
    
    OpcUaNodeId
    ContentFilterElementResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15211, 0);
    }
    
    void
    ContentFilterElementResult::opcUaBinaryEncode(std::ostream& os) const
    {
        statusCode_.opcUaBinaryEncode(os);
        operandStatusCodes_.opcUaBinaryEncode(os);
        operandDiagnosticInfos_.opcUaBinaryEncode(os);
    }
    
    void
    ContentFilterElementResult::opcUaBinaryDecode(std::istream& is)
    {
        statusCode_.opcUaBinaryDecode(is);
        operandStatusCodes_.opcUaBinaryDecode(is);
        operandDiagnosticInfos_.opcUaBinaryDecode(is);
    }
    
    bool
    ContentFilterElementResult::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ContentFilterElementResult::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ContentFilterElementResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ContentFilterElementResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!statusCode_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StatusCode", elementTree));
    
        elementTree.clear();
        if (!operandStatusCodes_.xmlEncode(elementTree, "Status", xmlns)) return false;
        pt.push_back(std::make_pair("OperandStatusCodes", elementTree));
    
        elementTree.clear();
        if (!operandDiagnosticInfos_.xmlEncode(elementTree, "DiagnosticInfo", xmlns)) return false;
        pt.push_back(std::make_pair("OperandDiagnosticInfos", elementTree));
    
        return true;
    }
    
    bool
    ContentFilterElementResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ContentFilterElementResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("StatusCode");
        if (!tree) return false;
        if (!statusCode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("OperandStatusCodes");
        if (!tree) return false;
        if (!operandStatusCodes_.xmlDecode(*tree, "Status", xmlns)) return false;
    
        tree = pt.get_child_optional("OperandDiagnosticInfos");
        if (!tree) return false;
        if (!operandDiagnosticInfos_.xmlDecode(*tree, "DiagnosticInfo", xmlns)) return false;
    
        return true;
    }
    
    bool
    ContentFilterElementResult::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ContentFilterElementResult::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ContentFilterElementResult::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ContentFilterElementResult::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ContentFilterElementResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ContentFilterElementResult* dst = dynamic_cast<ContentFilterElementResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ContentFilterElementResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ContentFilterElementResult* dst = dynamic_cast<ContentFilterElementResult*>(&extensionObjectBase);
    	return *const_cast<ContentFilterElementResult*>(this) == *dst;
    }
    
    void
    ContentFilterElementResult::out(std::ostream& os)
    {
        os << "StatusCode="; statusCode_.out(os);
        os << ", OperandStatusCodes="; operandStatusCodes_.out(os);
        os << ", OperandDiagnosticInfos="; operandDiagnosticInfos_.out(os);
    }

}
