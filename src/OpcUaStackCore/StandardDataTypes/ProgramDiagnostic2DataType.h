/*
    DataTypeClass: ProgramDiagnostic2DataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ProgramDiagnostic2DataType_h__
#define __OpcUaStackCore_ProgramDiagnostic2DataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/Argument.h"
#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ProgramDiagnostic2DataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ProgramDiagnostic2DataType> SPtr;
        typedef std::vector<ProgramDiagnostic2DataType::SPtr> Vec;
    
        ProgramDiagnostic2DataType(void);
        ProgramDiagnostic2DataType(const ProgramDiagnostic2DataType& value);
        virtual ~ProgramDiagnostic2DataType(void);
        
        OpcUaNodeId& createSessionId(void);
        OpcUaString& createClientName(void);
        OpcUaUtcTime& invocationCreationTime(void);
        OpcUaUtcTime& lastTransitionTime(void);
        OpcUaString& lastMethodCall(void);
        OpcUaNodeId& lastMethodSessionId(void);
        ArgumentArray& lastMethodInputArguments(void);
        ArgumentArray& lastMethodOutputArguments(void);
        OpcUaVariantArray& lastMethodInputValues(void);
        OpcUaVariantArray& lastMethodOutputValues(void);
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
        
        void copyTo(ProgramDiagnostic2DataType& value);
        bool operator==(const ProgramDiagnostic2DataType& value);
        bool operator!=(const ProgramDiagnostic2DataType& value);
        ProgramDiagnostic2DataType& operator=(const ProgramDiagnostic2DataType& value);
    
      private:
        OpcUaNodeId createSessionId_;
        OpcUaString createClientName_;
        OpcUaUtcTime invocationCreationTime_;
        OpcUaUtcTime lastTransitionTime_;
        OpcUaString lastMethodCall_;
        OpcUaNodeId lastMethodSessionId_;
        ArgumentArray lastMethodInputArguments_;
        ArgumentArray lastMethodOutputArguments_;
        OpcUaVariantArray lastMethodInputValues_;
        OpcUaVariantArray lastMethodOutputValues_;
        OpcUaUtcTime lastMethodCallTime_;
        StatusResult lastMethodReturnStatus_;
    
    };
    
    class DLLEXPORT ProgramDiagnostic2DataTypeArray
    : public OpcUaArray<ProgramDiagnostic2DataType::SPtr, SPtrTypeCoder<ProgramDiagnostic2DataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ProgramDiagnostic2DataTypeArray> SPtr;
    };

}

#endif
