/*
    DataTypeClass: RegisteredServer

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RegisteredServer_h__
#define __OpcUaStackCore_RegisteredServer_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RegisteredServer
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<RegisteredServer> SPtr;
        typedef std::vector<RegisteredServer::SPtr> Vec;
    
        RegisteredServer(void);
        RegisteredServer(const RegisteredServer& value);
        virtual ~RegisteredServer(void);
        
        OpcUaString& serverUri(void);
        OpcUaString& productUri(void);
        OpcUaLocalizedTextArray& serverNames(void);
        ApplicationType& serverType(void);
        OpcUaString& gatewayServerUri(void);
        OpcUaStringArray& discoveryUrls(void);
        OpcUaString& semaphoreFilePath(void);
        OpcUaBoolean& isOnline(void);
        
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
        
        void copyTo(RegisteredServer& value);
        bool operator==(const RegisteredServer& value);
        bool operator!=(const RegisteredServer& value);
        RegisteredServer& operator=(const RegisteredServer& value);
    
      private:
        OpcUaString serverUri_; //!< The globally unique identifier for the server.
        OpcUaString productUri_; //!< The globally unique identifier for the product.
        OpcUaLocalizedTextArray serverNames_; //!< The name of server in multiple lcoales.
        ApplicationType serverType_; //!< The type of server.
        OpcUaString gatewayServerUri_; //!< The globally unique identifier for the server that is acting as a gateway for the server.
        OpcUaStringArray discoveryUrls_; //!< The URLs for the server's discovery endpoints.
        OpcUaString semaphoreFilePath_; //!< A path to a file that is deleted when the server is no longer accepting connections.
        OpcUaBoolean isOnline_; //!< If FALSE the server will save the registration information to a persistent datastore.
    
    };
    
    class DLLEXPORT RegisteredServerArray
    : public OpcUaArray<RegisteredServer::SPtr, SPtrTypeCoder<RegisteredServer> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RegisteredServerArray> SPtr;
    };

}

#endif
