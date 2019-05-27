/*
    DataTypeClass: ProgramDiagnosticDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ProgramDiagnosticDataType.h"

namespace OpcUaStackCore
{
    
    ProgramDiagnosticDataType::ProgramDiagnosticDataType(void)
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
    , lastMethodCallTime_()
    , lastMethodReturnStatus_()
    {
    }
    
    ProgramDiagnosticDataType::ProgramDiagnosticDataType(const ProgramDiagnosticDataType& value)
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
    , lastMethodCallTime_()
    , lastMethodReturnStatus_()
    {
        const_cast<ProgramDiagnosticDataType*>(&value)->copyTo(*this);
    }
    
    ProgramDiagnosticDataType::~ProgramDiagnosticDataType(void)
    {
    }
    
    OpcUaNodeId&
    ProgramDiagnosticDataType::createSessionId(void)
    {
        return createSessionId_;
    }
    
    OpcUaString&
    ProgramDiagnosticDataType::createClientName(void)
    {
        return createClientName_;
    }
    
    OpcUaUtcTime&
    ProgramDiagnosticDataType::invocationCreationTime(void)
    {
        return invocationCreationTime_;
    }
    
    OpcUaUtcTime&
    ProgramDiagnosticDataType::lastTransitionTime(void)
    {
        return lastTransitionTime_;
    }
    
    OpcUaString&
    ProgramDiagnosticDataType::lastMethodCall(void)
    {
        return lastMethodCall_;
    }
    
    OpcUaNodeId&
    ProgramDiagnosticDataType::lastMethodSessionId(void)
    {
        return lastMethodSessionId_;
    }
    
    ArgumentArray&
    ProgramDiagnosticDataType::lastMethodInputArguments(void)
    {
        return lastMethodInputArguments_;
    }
    
    ArgumentArray&
    ProgramDiagnosticDataType::lastMethodOutputArguments(void)
    {
        return lastMethodOutputArguments_;
    }
    
    OpcUaUtcTime&
    ProgramDiagnosticDataType::lastMethodCallTime(void)
    {
        return lastMethodCallTime_;
    }
    
    StatusResult&
    ProgramDiagnosticDataType::lastMethodReturnStatus(void)
    {
        return lastMethodReturnStatus_;
    }
    
    bool
    ProgramDiagnosticDataType::operator==(const ProgramDiagnosticDataType& value)
    {
        ProgramDiagnosticDataType* dst = const_cast<ProgramDiagnosticDataType*>(&value);
        if (createSessionId_ != dst->createSessionId()) return false;
        if (createClientName_ != dst->createClientName()) return false;
        if (invocationCreationTime_ != dst->invocationCreationTime()) return false;
        if (lastTransitionTime_ != dst->lastTransitionTime()) return false;
        if (lastMethodCall_ != dst->lastMethodCall()) return false;
        if (lastMethodSessionId_ != dst->lastMethodSessionId()) return false;
        if (lastMethodInputArguments_ != dst->lastMethodInputArguments()) return false;
        if (lastMethodOutputArguments_ != dst->lastMethodOutputArguments()) return false;
        if (lastMethodCallTime_ != dst->lastMethodCallTime()) return false;
        if (lastMethodReturnStatus_ != dst->lastMethodReturnStatus()) return false;
        return true;
    }
    
    bool
    ProgramDiagnosticDataType::operator!=(const ProgramDiagnosticDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ProgramDiagnosticDataType::copyTo(ProgramDiagnosticDataType& value)
    {
        createSessionId_.copyTo(value.createSessionId());
        createClientName_.copyTo(value.createClientName());
        invocationCreationTime_.copyTo(value.invocationCreationTime());
        lastTransitionTime_.copyTo(value.lastTransitionTime());
        lastMethodCall_.copyTo(value.lastMethodCall());
        lastMethodSessionId_.copyTo(value.lastMethodSessionId());
        lastMethodInputArguments_.copyTo(value.lastMethodInputArguments());
        lastMethodOutputArguments_.copyTo(value.lastMethodOutputArguments());
        lastMethodCallTime_.copyTo(value.lastMethodCallTime());
        lastMethodReturnStatus_.copyTo(value.lastMethodReturnStatus());
    }
    
    ProgramDiagnosticDataType&
    ProgramDiagnosticDataType::operator=(const ProgramDiagnosticDataType& value)
    {
        const_cast<ProgramDiagnosticDataType*>(&value)->copyTo(*this);
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
    ProgramDiagnosticDataType::factory(void)
    {
    	return constructSPtr<ProgramDiagnosticDataType>();
    }
    
    std::string
    ProgramDiagnosticDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ProgramDiagnosticDataType::typeName(void)
    {
    	return "ProgramDiagnosticDataType";
    }
    
    OpcUaNodeId
    ProgramDiagnosticDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)894,0);
    }
    
    OpcUaNodeId
    ProgramDiagnosticDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)896, 0);
    }
    
    OpcUaNodeId
    ProgramDiagnosticDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)895, 0);
    }
    
    OpcUaNodeId
    ProgramDiagnosticDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15381, 0);
    }
    
    void
    ProgramDiagnosticDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        createSessionId_.opcUaBinaryEncode(os);
        createClientName_.opcUaBinaryEncode(os);
        invocationCreationTime_.opcUaBinaryEncode(os);
        lastTransitionTime_.opcUaBinaryEncode(os);
        lastMethodCall_.opcUaBinaryEncode(os);
        lastMethodSessionId_.opcUaBinaryEncode(os);
        lastMethodInputArguments_.opcUaBinaryEncode(os);
        lastMethodOutputArguments_.opcUaBinaryEncode(os);
        lastMethodCallTime_.opcUaBinaryEncode(os);
        lastMethodReturnStatus_.opcUaBinaryEncode(os);
    }
    
    void
    ProgramDiagnosticDataType::opcUaBinaryDecode(std::istream& is)
    {
        createSessionId_.opcUaBinaryDecode(is);
        createClientName_.opcUaBinaryDecode(is);
        invocationCreationTime_.opcUaBinaryDecode(is);
        lastTransitionTime_.opcUaBinaryDecode(is);
        lastMethodCall_.opcUaBinaryDecode(is);
        lastMethodSessionId_.opcUaBinaryDecode(is);
        lastMethodInputArguments_.opcUaBinaryDecode(is);
        lastMethodOutputArguments_.opcUaBinaryDecode(is);
        lastMethodCallTime_.opcUaBinaryDecode(is);
        lastMethodReturnStatus_.opcUaBinaryDecode(is);
    }
    
    bool
    ProgramDiagnosticDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ProgramDiagnosticDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!createSessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CreateSessionId", elementTree));
    
        elementTree.clear();
        if (!createClientName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CreateClientName", elementTree));
    
        elementTree.clear();
        if (!invocationCreationTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("InvocationCreationTime", elementTree));
    
        elementTree.clear();
        if (!lastTransitionTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastTransitionTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodCall_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCall", elementTree));
    
        elementTree.clear();
        if (!lastMethodSessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodSessionId", elementTree));
    
        elementTree.clear();
        if (!lastMethodInputArguments_.xmlEncode(elementTree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodInputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodOutputArguments_.xmlEncode(elementTree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodOutputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodCallTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCallTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodReturnStatus_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodReturnStatus", elementTree));
    
        return true;
    }
    
    bool
    ProgramDiagnosticDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ProgramDiagnosticDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("CreateSessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createSessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "CreateSessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("CreateClientName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createClientName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "CreateClientName");
            return false;
        }
    
        elementName = xmlns.addPrefix("InvocationCreationTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!invocationCreationTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "InvocationCreationTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastTransitionTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastTransitionTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "LastTransitionTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodCall");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCall_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "LastMethodCall");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodSessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodSessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "LastMethodSessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodInputArguments");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodInputArguments_.xmlDecode(*tree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodOutputArguments");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodOutputArguments_.xmlDecode(*tree, "Argument", xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodCallTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCallTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "LastMethodCallTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("LastMethodReturnStatus");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodReturnStatus_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ProgramDiagnosticDataType decode xml error - decode failed")
                .parameter("Element", "LastMethodReturnStatus");
            return false;
        }
    
        return true;
    }
    
    bool
    ProgramDiagnosticDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!createSessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "createSessionId_");
            return false;
        }
        pt.push_back(std::make_pair("CreateSessionId", elementTree));
    
        elementTree.clear();
        if (!createClientName_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "createClientName_");
            return false;
        }
        pt.push_back(std::make_pair("CreateClientName", elementTree));
    
        elementTree.clear();
        if (!invocationCreationTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "invocationCreationTime_");
            return false;
        }
        pt.push_back(std::make_pair("InvocationCreationTime", elementTree));
    
        elementTree.clear();
        if (!lastTransitionTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastTransitionTime_");
            return false;
        }
        pt.push_back(std::make_pair("LastTransitionTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodCall_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastMethodCall_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCall", elementTree));
    
        elementTree.clear();
        if (!lastMethodSessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastMethodSessionId_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodSessionId", elementTree));
    
        elementTree.clear();
        if (!lastMethodInputArguments_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastMethodInputArguments_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodInputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodOutputArguments_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastMethodOutputArguments_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodOutputArguments", elementTree));
    
        elementTree.clear();
        if (!lastMethodCallTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastMethodCallTime_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodCallTime", elementTree));
    
        elementTree.clear();
        if (!lastMethodReturnStatus_.jsonEncode(elementTree))
        {
    	     Log(Error, "ProgramDiagnosticDataType json encoder error")
    		     .parameter("Element", "lastMethodReturnStatus_");
            return false;
        }
        pt.push_back(std::make_pair("LastMethodReturnStatus", elementTree));
    
        return true;
    }
    
    bool
    ProgramDiagnosticDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "CreateSessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createSessionId_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "CreateSessionId");
            return false;
        }
    
        elementName = "CreateClientName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createClientName_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "CreateClientName");
            return false;
        }
    
        elementName = "InvocationCreationTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!invocationCreationTime_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "InvocationCreationTime");
            return false;
        }
    
        elementName = "LastTransitionTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastTransitionTime_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "LastTransitionTime");
            return false;
        }
    
        elementName = "LastMethodCall";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCall_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "LastMethodCall");
            return false;
        }
    
        elementName = "LastMethodSessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodSessionId_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "LastMethodSessionId");
            return false;
        }
    
        elementName = "LastMethodInputArguments";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodInputArguments_.jsonDecode(*tree, "")) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LastMethodOutputArguments";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodOutputArguments_.jsonDecode(*tree, "")) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LastMethodCallTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodCallTime_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "LastMethodCallTime");
            return false;
        }
    
        elementName = "LastMethodReturnStatus";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ProgramDiagnosticDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!lastMethodReturnStatus_.jsonDecode(*tree)) {
            Log(Error, "ProgramDiagnosticDataType decode json error - decode failed")
                .parameter("Element", "LastMethodReturnStatus");
            return false;
        }
    
        return true;
    }
    
    void
    ProgramDiagnosticDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ProgramDiagnosticDataType* dst = dynamic_cast<ProgramDiagnosticDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ProgramDiagnosticDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ProgramDiagnosticDataType* dst = dynamic_cast<ProgramDiagnosticDataType*>(&extensionObjectBase);
    	return *const_cast<ProgramDiagnosticDataType*>(this) == *dst;
    }
    
    void
    ProgramDiagnosticDataType::out(std::ostream& os)
    {
        os << "CreateSessionId="; createSessionId_.out(os);
        os << ", CreateClientName="; createClientName_.out(os);
        os << ", InvocationCreationTime="; invocationCreationTime_.out(os);
        os << ", LastTransitionTime="; lastTransitionTime_.out(os);
        os << ", LastMethodCall="; lastMethodCall_.out(os);
        os << ", LastMethodSessionId="; lastMethodSessionId_.out(os);
        os << ", LastMethodInputArguments="; lastMethodInputArguments_.out(os);
        os << ", LastMethodOutputArguments="; lastMethodOutputArguments_.out(os);
        os << ", LastMethodCallTime="; lastMethodCallTime_.out(os);
        os << ", LastMethodReturnStatus="; lastMethodReturnStatus_.out(os);
    }

}
