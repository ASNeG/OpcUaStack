/*
    DataTypeClass: ProgramDiagnosticDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ProgramDiagnosticDataType_h__
#define __OpcUaStackCore_ProgramDiagnosticDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual void opcUaBinaryEncode(std::ostream& os) const override;
        virtual void opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
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
