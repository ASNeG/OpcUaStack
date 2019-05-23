/*
    DataTypeClass: SessionSecurityDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SessionSecurityDiagnosticsDataType_h__
#define __OpcUaStackCore_SessionSecurityDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
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
