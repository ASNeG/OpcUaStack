/*
    DataTypeClass: ServerDiagnosticsSummaryDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ServerDiagnosticsSummaryDataType_h__
#define __OpcUaStackCore_ServerDiagnosticsSummaryDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ServerDiagnosticsSummaryDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ServerDiagnosticsSummaryDataType> SPtr;
        typedef std::vector<ServerDiagnosticsSummaryDataType::SPtr> Vec;
    
        ServerDiagnosticsSummaryDataType(void);
        ServerDiagnosticsSummaryDataType(const ServerDiagnosticsSummaryDataType& value);
        virtual ~ServerDiagnosticsSummaryDataType(void);
        
        OpcUaUInt32& serverViewCount(void);
        OpcUaUInt32& currentSessionCount(void);
        OpcUaUInt32& cumulatedSessionCount(void);
        OpcUaUInt32& securityRejectedSessionCount(void);
        OpcUaUInt32& rejectedSessionCount(void);
        OpcUaUInt32& sessionTimeoutCount(void);
        OpcUaUInt32& sessionAbortCount(void);
        OpcUaUInt32& currentSubscriptionCount(void);
        OpcUaUInt32& cumulatedSubscriptionCount(void);
        OpcUaUInt32& publishingIntervalCount(void);
        OpcUaUInt32& securityRejectedRequestsCount(void);
        OpcUaUInt32& rejectedRequestsCount(void);
        
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
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(ServerDiagnosticsSummaryDataType& value);
        bool operator==(const ServerDiagnosticsSummaryDataType& value);
        bool operator!=(const ServerDiagnosticsSummaryDataType& value);
        ServerDiagnosticsSummaryDataType& operator=(const ServerDiagnosticsSummaryDataType& value);
    
      private:
        OpcUaUInt32 serverViewCount_;
        OpcUaUInt32 currentSessionCount_;
        OpcUaUInt32 cumulatedSessionCount_;
        OpcUaUInt32 securityRejectedSessionCount_;
        OpcUaUInt32 rejectedSessionCount_;
        OpcUaUInt32 sessionTimeoutCount_;
        OpcUaUInt32 sessionAbortCount_;
        OpcUaUInt32 currentSubscriptionCount_;
        OpcUaUInt32 cumulatedSubscriptionCount_;
        OpcUaUInt32 publishingIntervalCount_;
        OpcUaUInt32 securityRejectedRequestsCount_;
        OpcUaUInt32 rejectedRequestsCount_;
    
    };
    
    class DLLEXPORT ServerDiagnosticsSummaryDataTypeArray
    : public OpcUaArray<ServerDiagnosticsSummaryDataType::SPtr, SPtrTypeCoder<ServerDiagnosticsSummaryDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ServerDiagnosticsSummaryDataTypeArray> SPtr;
    };

}

#endif
