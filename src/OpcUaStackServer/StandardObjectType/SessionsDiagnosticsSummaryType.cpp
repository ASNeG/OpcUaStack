/*
    VariableTypeClass: SessionsDiagnosticsSummaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/SessionsDiagnosticsSummaryType.h"

namespace OpcUaStackServer
{
    
    /**
     * Provides a summary of session level diagnostics.
     */
    SessionsDiagnosticsSummaryType::SessionsDiagnosticsSummaryType(void)
    : ObjectBase()
    , sessionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionDiagnosticsArray_Variable"))
    , sessionSecurityDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnosticsArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2026);
        setServerVariable(sessionDiagnosticsArray_Variable_);
        setServerVariable(sessionSecurityDiagnosticsArray_Variable_);
    }
    
    /**
     * Provides a summary of session level diagnostics.
     */
    SessionsDiagnosticsSummaryType::SessionsDiagnosticsSummaryType(const SessionsDiagnosticsSummaryType& value)
    : ObjectBase()
    , sessionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionDiagnosticsArray_Variable"))
    , sessionSecurityDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnosticsArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2026);
        setServerVariable(sessionDiagnosticsArray_Variable_);
        setServerVariable(sessionSecurityDiagnosticsArray_Variable_);
    }
    
    SessionsDiagnosticsSummaryType::~SessionsDiagnosticsSummaryType(void)
    {
    }

    ServerVariable::SPtr&
    SessionsDiagnosticsSummaryType::sessionDiagnosticsArray_Variable(void)
    {
        return sessionDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    SessionsDiagnosticsSummaryType::sessionSecurityDiagnosticsArray_Variable(void)
    {
        return sessionSecurityDiagnosticsArray_Variable_;
    }

    void
    SessionsDiagnosticsSummaryType::sessionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    SessionsDiagnosticsSummaryType::sessionSecurityDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnosticsArray_Variable_ = serverVariable;
    }

    bool
    SessionsDiagnosticsSummaryType::get_SessionDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    SessionsDiagnosticsSummaryType::get_SessionSecurityDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    SessionsDiagnosticsSummaryType::set_SessionDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    SessionsDiagnosticsSummaryType::set_SessionSecurityDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

}
