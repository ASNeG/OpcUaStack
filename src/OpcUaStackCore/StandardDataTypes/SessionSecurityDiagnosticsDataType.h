/*
    DataTypeClass: SessionSecurityDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SessionSecurityDiagnosticsDataType_h__
#define __OpcUaStackCore_SessionSecurityDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SessionSecurityDiagnosticsDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SessionSecurityDiagnosticsDataType> SPtr;
        typedef std::vector<SessionSecurityDiagnosticsDataType::SPtr> Vec;
    
        SessionSecurityDiagnosticsDataType(void);
        SessionSecurityDiagnosticsDataType(const SessionSecurityDiagnosticsDataType& value);
        virtual ~SessionSecurityDiagnosticsDataType(void);
        
        OpcUaNodeId& sessionId(void);
        OpcUaString& clientUserIdOfSession(void);
        OpcUaStringArray& clientUserIdHistory(void);
        OpcUaString& authenticationMechanism(void);
        OpcUaString& encoding(void);
        OpcUaString& transportProtocol(void);
        MessageSecurityMode& securityMode(void);
        OpcUaString& securityPolicyUri(void);
        OpcUaByteString& clientCertificate(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(SessionSecurityDiagnosticsDataType& value);
        bool operator==(const SessionSecurityDiagnosticsDataType& value);
        bool operator!=(const SessionSecurityDiagnosticsDataType& value);
        SessionSecurityDiagnosticsDataType& operator=(const SessionSecurityDiagnosticsDataType& value);
    
      private:
        OpcUaNodeId sessionId_;
        OpcUaString clientUserIdOfSession_;
        OpcUaStringArray clientUserIdHistory_;
        OpcUaString authenticationMechanism_;
        OpcUaString encoding_;
        OpcUaString transportProtocol_;
        MessageSecurityMode securityMode_;
        OpcUaString securityPolicyUri_;
        OpcUaByteString clientCertificate_;
    
    };
    
    class DLLEXPORT SessionSecurityDiagnosticsDataTypeArray
    : public OpcUaArray<SessionSecurityDiagnosticsDataType::SPtr, SPtrTypeCoder<SessionSecurityDiagnosticsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SessionSecurityDiagnosticsDataTypeArray> SPtr;
    };

}

#endif
