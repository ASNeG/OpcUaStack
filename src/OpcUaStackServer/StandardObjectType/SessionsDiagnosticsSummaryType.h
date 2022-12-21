/*
    ObjectTypeClass: SessionsDiagnosticsSummaryType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionsDiagnosticsSummaryType_h__
#define __OpcUaStackServer_SessionsDiagnosticsSummaryType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionsDiagnosticsSummaryType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SessionsDiagnosticsSummaryType> SPtr;
       typedef std::vector<SessionsDiagnosticsSummaryType::SPtr> Vec;
   
       SessionsDiagnosticsSummaryType(void);
       SessionsDiagnosticsSummaryType(const SessionsDiagnosticsSummaryType& value);
       virtual ~SessionsDiagnosticsSummaryType(void);

        //
        // SessionDiagnosticsDataType (Array)
        //
        void sessionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnosticsArray_Variable(void);
        bool get_SessionDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SessionDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType (Array)
        //
        void sessionSecurityDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnosticsArray_Variable(void);
        bool get_SessionSecurityDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr sessionDiagnosticsArray_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnosticsArray_Variable_;
   
   };

}

#endif
