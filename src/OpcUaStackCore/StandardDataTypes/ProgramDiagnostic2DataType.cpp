/*
    DataTypeClass: ProgramDiagnostic2DataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ProgramDiagnostic2DataType.h"

namespace OpcUaStackCore
{
    
    ProgramDiagnostic2DataType::ProgramDiagnostic2DataType(void)
    : Object()
    , ExtensionObjectBase()
    , createSessionId_()
    , createClientName_()
    , invocationCreationTime_()
    , lastTransitionTime_()
    , lastMethodCall_()
    , lastMethodSessionId_()
    , lastMethodInputArguments_()
    , lastMethodOutputArguments_()
    , lastMethodInputValues_()
    , lastMethodOutputValues_()
    , lastMethodCallTime_()
    , lastMethodReturnStatus_()
    {
    }
    
    ProgramDiagnostic2DataType::ProgramDiagnostic2DataType(const ProgramDiagnostic2DataType& value)
    : Object()
    , ExtensionObjectBase()
    , createSessionId_()
    , createClientName_()
    , invocationCreationTime_()
    , lastTransitionTime_()
    , lastMethodCall_()
    , lastMethodSessionId_()
    , lastMethodInputArguments_()
    , lastMethodOutputArguments_()
    , lastMethodInputValues_()
    , lastMethodOutputValues_()
    , lastMethodCallTime_()
    , lastMethodReturnStatus_()
    {
        const_cast<ProgramDiagnostic2DataType*>(&value)->copyTo(*this);
    }
    
    ProgramDiagnostic2DataType::~ProgramDiagnostic2DataType(void)
    {
    }
    
    OpcUaNodeId&
    ProgramDiagnostic2DataType::createSessionId(void)
    {
        return createSessionId_;
    }
    
    OpcUaString&
    ProgramDiagnostic2DataType::createClientName(void)
    {
        return createClientName_;
    }
    
    OpcUaUtcTime&
    ProgramDiagnostic2DataType::invocationCreationTime(void)
    {
        return invocationCreationTime_;
    }
    
    OpcUaUtcTime&
    ProgramDiagnostic2DataType::lastTransitionTime(void)
    {
        return lastTransitionTime_;
    }
    
    OpcUaString&
    ProgramDiagnostic2DataType::lastMethodCall(void)
    {
        return lastMethodCall_;
    }
    
    OpcUaNodeId&
    ProgramDiagnostic2DataType::lastMethodSessionId(void)
    {
        return lastMethodSessionId_;
    }
    
    ArgumentArray&
    ProgramDiagnostic2DataType::lastMethodInputArguments(void)
    {
        return lastMethodInputArguments_;
    }
    
    ArgumentArray&
    ProgramDiagnostic2DataType::lastMethodOutputArguments(void)
    {
        return lastMethodOutputArguments_;
    }
    
    OpcUaVariantArray&
    ProgramDiagnostic2DataType::lastMethodInputValues(void)
    {
        return lastMethodInputValues_;
    }
    
    OpcUaVariantArray&
    ProgramDiagnostic2DataType::lastMethodOutputValues(void)
    {
        return lastMethodOutputValues_;
    }
    
    OpcUaUtcTime&
    ProgramDiagnostic2DataType::lastMethodCallTime(void)
    {
        return lastMethodCallTime_;
    }
    
    StatusResult&
    ProgramDiagnostic2DataType::lastMethodReturnStatus(void)
    {
        return lastMethodReturnStatus_;
    }
    
    bool
    ProgramDiagnostic2DataType::operator==(const ProgramDiagnostic2DataType& value)
    {
        ProgramDiagnostic2DataType* dst = const_cast<ProgramDiagnostic2DataType*>(&value);
        if (createSessionId_ != dst->createSessionId()) return false;
        if (createClientName_ != dst->createClientName()) return false;
        if (invocationCreationTime_ != dst->invocationCreationTime()) return false;
        if (lastTransitionTime_ != dst->lastTransitionTime()) return false;
        if (lastMethodCall_ != dst->lastMethodCall()) return false;
        if (lastMethodSessionId_ != dst->lastMethodSessionId()) return false;
        if (lastMethodInputArguments_ != dst->lastMethodInputArguments()) return false;
        if (lastMethodOutputArguments_ != dst->lastMethodOutputArguments()) return false;
        if (lastMethodInputValues_ != dst->lastMethodInputValues()) return false;
        if (lastMethodOutputValues_ != dst->lastMethodOutputValues()) return false;
        if (lastMethodCallTime_ != dst->lastMethodCallTime()) return false;
        if (lastMethodReturnStatus_ != dst->lastMethodReturnStatus()) return false;
        return true;
    }
    
    bool
    ProgramDiagnostic2DataType::operator!=(const ProgramDiagnostic2DataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ProgramDiagnostic2DataType::copyTo(ProgramDiagnostic2DataType& value)
    {
        createSessionId_.copyTo(value.createSessionId());
        createClientName_.copyTo(value.createClientName());
        invocationCreationTime_.copyTo(value.invocationCreationTime());
        lastTransitionTime_.copyTo(value.lastTransitionTime());
        lastMethodCall_.copyTo(value.lastMethodCall());
        lastMethodSessionId_.copyTo(value.lastMethodSessionId());
        lastMethodInputArguments_.copyTo(value.lastMethodInputArguments());
        lastMethodOutputArguments_.copyTo(value.lastMethodOutputArguments());
        lastMethodInputValues_.copyTo(value.lastMethodInputValues());
        lastMethodOutputValues_.copyTo(value.lastMethodOutputValues());
        lastMethodCallTime_.copyTo(value.lastMethodCallTime());
        lastMethodReturnStatus_.copyTo(value.lastMethodReturnStatus());
    }
    
    ProgramDiagnostic2DataType&
    ProgramDiagnostic2DataType::operator=(const ProgramDiagnostic2DataType& value)
    {
        const_cast<ProgramDiagnostic2DataType*>(&value)->copyTo(*this);
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
    ProgramDiagnostic2DataType::factory(void)
    {
    	return constructSPtr<ProgramDiagnostic2DataType>();
    }
    
    std::string
    ProgramDiagnostic2DataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ProgramDiagnostic2DataType::typeName(void)
    {
    	return "ProgramDiagnostic2DataType";
    }
    
    OpcUaNodeId
    ProgramDiagnostic2DataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15396,0);
    }
    
    OpcUaNodeId
    ProgramDiagnostic2DataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15397, 0);
    }
    
    OpcUaNodeId
    ProgramDiagnostic2DataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15401, 0);
    }
    
    OpcUaNodeId
    ProgramDiagnostic2DataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15405, 0);
    }
    
    void
    ProgramDiagnostic2DataType::opcUaBinaryEncode(std::ostream& os) const
    {
        createSessionId_.opcUaBinaryEncode(os);
        createClientName_.opcUaBinaryEncode(os);
        invocationCreationTime_.opcUaBinaryEncode(os);
        lastTransitionTime_.opcUaBinaryEncode(os);
        lastMethodCall_.opcUaBinaryEncode(os);
        lastMethodSessionId_.opcUaBinaryEncode(os);
        lastMethodInputArguments_.opcUaBinaryEncode(os);
        lastMethodOutputArguments_.opcUaBinaryEncode(os);
        lastMethodInputValues_.opcUaBinaryEncode(os);
        lastMethodOutputValues_.opcUaBinaryEncode(os);
        lastMethodCallTime_.opcUaBinaryEncode(os);
        lastMethodReturnStatus_.opcUaBinaryEncode(os);
    }
    
    void
    ProgramDiagnostic2DataType::opcUaBinaryDecode(std::istream& is)
    {
        createSessionId_.opcUaBinaryDecode(is);
        createClientName_.opcUaBinaryDecode(is);
        invocationCreationTime_.opcUaBinaryDecode(is);
        lastTransitionTime_.opcUaBinaryDecode(is);
        lastMethodCall_.opcUaBinaryDecode(is);
        lastMethodSessionId_.opcUaBinaryDecode(is);
        lastMethodInputArguments_.opcUaBinaryDecode(is);
        lastMethodOutputArguments_.opcUaBinaryDecode(is);
        lastMethodInputValues_.opcUaBinaryDecode(is);
        lastMethodOutputValues_.opcUaBinaryDecode(is);
        lastMethodCallTime_.opcUaBinaryDecode(is);
        lastMethodReturnStatus_.opcUaBinaryDecode(is);
    }
    
    bool
    ProgramDiagnostic2DataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ProgramDiagnostic2DataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!createSessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CreateSessionId", elementTree));
    
        elementTree.clear();
        if (!createClientName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CreateClientName", elementTree));
    
        elementTree.clear();
        if (!invocationCreationTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("InvocationCreationTime", elementTree));
    
        elementTree.clear();
        if (!lastTransitionTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastTransitionTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodCall_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCall", elementTree));
    
        elementTree.clear();
        if (!lastMethodSessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodSessionId", elementTree));
    
        elementTree.clear();
        if (!lastMethodInputArguments_.xmlEncode(elementTree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodInputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodOutputArguments_.xmlEncode(elementTree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodOutputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodInputValues_.xmlEncode(elementTree, "Variant", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodInputValues", elementTree));
    
        elementTree.clear();
        if (!lastMethodOutputValues_.xmlEncode(elementTree, "Variant", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodOutputValues", elementTree));
    
        elementTree.clear();
        if (!lastMethodCallTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCallTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodReturnStatus_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodReturnStatus", elementTree));
    
        return true;
    }
    
    bool
    ProgramDiagnostic2DataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ProgramDiagnostic2DataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("CreateSessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createSessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "CreateSessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("CreateClientName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createClientName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "CreateClientName");
            return false;
        }
    
        elementName = xmlns.addPrefix("InvocationCreationTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!invocationCreationTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "InvocationCreationTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastTransitionTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastTransitionTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "LastTransitionTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodCall");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCall_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "LastMethodCall");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodSessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodSessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "LastMethodSessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodInputArguments");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodInputArguments_.xmlDecode(*tree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodOutputArguments");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodOutputArguments_.xmlDecode(*tree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodInputValues");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodInputValues_.xmlDecode(*tree, "Variant", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodOutputValues");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodOutputValues_.xmlDecode(*tree, "Variant", xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodCallTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCallTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "LastMethodCallTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodReturnStatus");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodReturnStatus_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnostic2DataType decode xml error - decode failed")
                .parameter("Element", "LastMethodReturnStatus");
            return false;
        }
    
        return true;
    }
    
    bool
    ProgramDiagnostic2DataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!createSessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "createSessionId_");
            return false;
        }
        pt.push_back(std::make_pair("CreateSessionId", elementTree));
    
        elementTree.clear();
        if (!createClientName_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "createClientName_");
            return false;
        }
        pt.push_back(std::make_pair("CreateClientName", elementTree));
    
        elementTree.clear();
        if (!invocationCreationTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "invocationCreationTime_");
            return false;
        }
        pt.push_back(std::make_pair("InvocationCreationTime", elementTree));
    
        elementTree.clear();
        if (!lastTransitionTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastTransitionTime_");
            return false;
        }
        pt.push_back(std::make_pair("LastTransitionTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodCall_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodCall_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCall", elementTree));
    
        elementTree.clear();
        if (!lastMethodSessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodSessionId_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodSessionId", elementTree));
    
        elementTree.clear();
        if (!lastMethodInputArguments_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodInputArguments_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodInputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodOutputArguments_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodOutputArguments_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodOutputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodInputValues_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodInputValues_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodInputValues", elementTree));
    
        elementTree.clear();
        if (!lastMethodOutputValues_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodOutputValues_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodOutputValues", elementTree));
    
        elementTree.clear();
        if (!lastMethodCallTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodCallTime_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCallTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodReturnStatus_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnostic2DataType json encoder error")
    		     .parameter("Element", "lastMethodReturnStatus_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodReturnStatus", elementTree));
    
        return true;
    }
    
    bool
    ProgramDiagnostic2DataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "CreateSessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createSessionId_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "CreateSessionId");
            return false;
        }
    
        elementName = "CreateClientName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createClientName_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "CreateClientName");
            return false;
        }
    
        elementName = "InvocationCreationTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!invocationCreationTime_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "InvocationCreationTime");
            return false;
        }
    
        elementName = "LastTransitionTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastTransitionTime_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "LastTransitionTime");
            return false;
        }
    
        elementName = "LastMethodCall";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCall_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "LastMethodCall");
            return false;
        }
    
        elementName = "LastMethodSessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodSessionId_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "LastMethodSessionId");
            return false;
        }
    
        elementName = "LastMethodInputArguments";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodInputArguments_.jsonDecode(*tree, "")) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LastMethodOutputArguments";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodOutputArguments_.jsonDecode(*tree, "")) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LastMethodInputValues";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodInputValues_.jsonDecode(*tree, "")) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LastMethodOutputValues";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodOutputValues_.jsonDecode(*tree, "")) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LastMethodCallTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCallTime_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "LastMethodCallTime");
            return false;
        }
    
        elementName = "LastMethodReturnStatus";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodReturnStatus_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnostic2DataType decode json error - decode failed")
                .parameter("Element", "LastMethodReturnStatus");
            return false;
        }
    
        return true;
    }
    
    void
    ProgramDiagnostic2DataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ProgramDiagnostic2DataType* dst = dynamic_cast<ProgramDiagnostic2DataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ProgramDiagnostic2DataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ProgramDiagnostic2DataType* dst = dynamic_cast<ProgramDiagnostic2DataType*>(&extensionObjectBase);
    	return *const_cast<ProgramDiagnostic2DataType*>(this) == *dst;
    }
    
    void
    ProgramDiagnostic2DataType::out(std::ostream& os)
    {
        os << "CreateSessionId="; createSessionId_.out(os);
        os << ", CreateClientName="; createClientName_.out(os);
        os << ", InvocationCreationTime="; invocationCreationTime_.out(os);
        os << ", LastTransitionTime="; lastTransitionTime_.out(os);
        os << ", LastMethodCall="; lastMethodCall_.out(os);
        os << ", LastMethodSessionId="; lastMethodSessionId_.out(os);
        os << ", LastMethodInputArguments="; lastMethodInputArguments_.out(os);
        os << ", LastMethodOutputArguments="; lastMethodOutputArguments_.out(os);
        os << ", LastMethodInputValues="; lastMethodInputValues_.out(os);
        os << ", LastMethodOutputValues="; lastMethodOutputValues_.out(os);
        os << ", LastMethodCallTime="; lastMethodCallTime_.out(os);
        os << ", LastMethodReturnStatus="; lastMethodReturnStatus_.out(os);
    }

}
