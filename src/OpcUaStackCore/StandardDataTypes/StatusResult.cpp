/*
    DataTypeClass: StatusResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
    
    StatusResult::StatusResult(const StatusResult& value)
    : Object()
    , ExtensionObjectBase()
    , statusCode_()
    , diagnosticInfo_()
    {
        const_cast<StatusResult*>(&value)->copyTo(*this);
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
    	return boost::make_shared<StatusResult>();
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
    
    bool
    StatusResult::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= statusCode_.opcUaBinaryEncode(os);
        rc &= diagnosticInfo_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    StatusResult::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= statusCode_.opcUaBinaryDecode(is);
        rc &= diagnosticInfo_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    StatusResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "StatusResult encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StatusResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!statusCode_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StatusResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StatusCode", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfo_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StatusResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiagnosticInfo", elementTree));
    
        return true;
    }
    
    bool
    StatusResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StatusResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("StatusCode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!statusCode_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StatusResult decode xml error - decode failed")
                .parameter("Element", "StatusCode");
            return false;
        }
    
        elementName = xmlns.addPrefix("DiagnosticInfo");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!diagnosticInfo_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StatusResult decode xml error - decode failed")
                .parameter("Element", "DiagnosticInfo");
            return false;
        }
    
        return true;
    }
    
    bool
    StatusResult::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, statusCode_, "StatusCode", true);
        rc = rc & jsonObjectEncode(pt, diagnosticInfo_, "DiagnosticInfo", true);
    
        return rc;
    }
    
    bool
    StatusResult::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, statusCode_, "StatusCode", true);
        rc = rc & jsonObjectDecode(pt, diagnosticInfo_, "DiagnosticInfo", true);
    
        return rc;
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
