/*
    DataTypeClass: ContentFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ContentFilterResult.h"

namespace OpcUaStackCore
{
    
    ContentFilterResult::ContentFilterResult(void)
    : Object()
    , ExtensionObjectBase()
    , elementResults_()
    , elementDiagnosticInfos_()
    {
    }
    
    ContentFilterResult::ContentFilterResult(const ContentFilterResult& value)
    : Object()
    , ExtensionObjectBase()
    , elementResults_()
    , elementDiagnosticInfos_()
    {
        const_cast<ContentFilterResult*>(&value)->copyTo(*this);
    }
    
    ContentFilterResult::~ContentFilterResult(void)
    {
    }
    
    ContentFilterElementResultArray&
    ContentFilterResult::elementResults(void)
    {
        return elementResults_;
    }
    
    OpcUaDiagnosticInfoArray&
    ContentFilterResult::elementDiagnosticInfos(void)
    {
        return elementDiagnosticInfos_;
    }
    
    bool
    ContentFilterResult::operator==(const ContentFilterResult& value)
    {
        ContentFilterResult* dst = const_cast<ContentFilterResult*>(&value);
        if (elementResults_ != dst->elementResults()) return false;
        if (elementDiagnosticInfos_ != dst->elementDiagnosticInfos()) return false;
        return true;
    }
    
    bool
    ContentFilterResult::operator!=(const ContentFilterResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    ContentFilterResult::copyTo(ContentFilterResult& value)
    {
        elementResults_.copyTo(value.elementResults());
        elementDiagnosticInfos_.copyTo(value.elementDiagnosticInfos());
    }
    
    ContentFilterResult&
    ContentFilterResult::operator=(const ContentFilterResult& value)
    {
        const_cast<ContentFilterResult*>(&value)->copyTo(*this);
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
    ContentFilterResult::factory(void)
    {
    	return constructSPtr<ContentFilterResult>();
    }
    
    std::string
    ContentFilterResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ContentFilterResult::typeName(void)
    {
    	return "ContentFilterResult";
    }
    
    OpcUaNodeId
    ContentFilterResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)607,0);
    }
    
    OpcUaNodeId
    ContentFilterResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)609, 0);
    }
    
    OpcUaNodeId
    ContentFilterResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)608, 0);
    }
    
    OpcUaNodeId
    ContentFilterResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15228, 0);
    }
    
    void
    ContentFilterResult::opcUaBinaryEncode(std::ostream& os) const
    {
        elementResults_.opcUaBinaryEncode(os);
        elementDiagnosticInfos_.opcUaBinaryEncode(os);
    }
    
    void
    ContentFilterResult::opcUaBinaryDecode(std::istream& is)
    {
        elementResults_.opcUaBinaryDecode(is);
        elementDiagnosticInfos_.opcUaBinaryDecode(is);
    }
    
    bool
    ContentFilterResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ContentFilterResult encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ContentFilterResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!elementResults_.xmlEncode(elementTree, "ContentFilterElementResult", xmlns)) {
            Log(Error, "ContentFilterResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ElementResults", elementTree));
    
        elementTree.clear();
        if (!elementDiagnosticInfos_.xmlEncode(elementTree, "DiagnosticInfo", xmlns)) {
            Log(Error, "ContentFilterResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ElementDiagnosticInfos", elementTree));
    
        return true;
    }
    
    bool
    ContentFilterResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ContentFilterResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ElementResults");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elementResults_.xmlDecode(*tree, "ContentFilterElementResult", xmlns)) {
            Log(Error, "ContentFilterResult decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ElementDiagnosticInfos");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elementDiagnosticInfos_.xmlDecode(*tree, "DiagnosticInfo", xmlns)) {
            Log(Error, "ContentFilterResult decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ContentFilterResult::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!elementResults_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ContentFilterResult json encoder error")
    		     .parameter("Element", "elementResults_");
            return false;
        }
        pt.push_back(std::make_pair("ElementResults", elementTree));
    
        elementTree.clear();
        if (!elementDiagnosticInfos_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ContentFilterResult json encoder error")
    		     .parameter("Element", "elementDiagnosticInfos_");
            return false;
        }
        pt.push_back(std::make_pair("ElementDiagnosticInfos", elementTree));
    
        return true;
    }
    
    bool
    ContentFilterResult::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ElementResults";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilterResult decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elementResults_.jsonDecode(*tree, "")) {
            Log(Error, "ContentFilterResult decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ElementDiagnosticInfos";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilterResult decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elementDiagnosticInfos_.jsonDecode(*tree, "")) {
            Log(Error, "ContentFilterResult decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ContentFilterResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ContentFilterResult* dst = dynamic_cast<ContentFilterResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ContentFilterResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ContentFilterResult* dst = dynamic_cast<ContentFilterResult*>(&extensionObjectBase);
    	return *const_cast<ContentFilterResult*>(this) == *dst;
    }
    
    void
    ContentFilterResult::out(std::ostream& os)
    {
        os << "ElementResults="; elementResults_.out(os);
        os << ", ElementDiagnosticInfos="; elementDiagnosticInfos_.out(os);
    }

}
