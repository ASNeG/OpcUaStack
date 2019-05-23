/*
    DataTypeClass: ProgramDiagnosticDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ProgramDiagnosticDataType_h__
#define __OpcUaStackCore_ProgramDiagnosticDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/Argument.h"
#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ProgramDiagnosticDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ProgramDiagnosticDataType> SPtr;
        typedef std::vector<ProgramDiagnosticDataType::SPtr> Vec;
    
        ProgramDiagnosticDataType(void);
        ProgramDiagnosticDataType(const ProgramDiagnosticDataType& value);
        virtual ~ProgramDiagnosticDataType(void);
        
        OpcUaNodeId& createSessionId(void);
        OpcUaString& createClientName(void);
        OpcUaUtcTime& invocationCreationTime(void);
        OpcUaUtcTime& lastTransitionTime(void);
        OpcUaString& lastMethodCall(void);
        OpcUaNodeId& lastMethodSessionId(void);
        ArgumentArray& lastMethodInputArguments(void);
        ArgumentArray& lastMethodOutputArguments(void);
        OpcUaUtcTime& lastMethodCallTime(void);
        StatusResult& lastMethodReturnStatus(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(ProgramDiagnosticDataType& value);
        bool operator==(const ProgramDiagnosticDataType& value);
        bool operator!=(const ProgramDiagnosticDataType& value);
        ProgramDiagnosticDataType& operator=(const ProgramDiagnosticDataType& value);
    
      private:
        OpcUaNodeId createSessionId_;
        OpcUaString createClientName_;
        OpcUaUtcTime invocationCreationTime_;
        OpcUaUtcTime lastTransitionTime_;
        OpcUaString lastMethodCall_;
        OpcUaNodeId lastMethodSessionId_;
        ArgumentArray lastMethodInputArguments_;
        ArgumentArray lastMethodOutputArguments_;
        OpcUaUtcTime lastMethodCallTime_;
        StatusResult lastMethodReturnStatus_;
    
    };
    
    class DLLEXPORT ProgramDiagnosticDataTypeArray
    : public OpcUaArray<ProgramDiagnosticDataType::SPtr, SPtrTypeCoder<ProgramDiagnosticDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ProgramDiagnosticDataTypeArray> SPtr;
    };

}

#endif
