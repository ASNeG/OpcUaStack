/*
    DataTypeClass: EndpointDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EndpointDescription_h__
#define __OpcUaStackCore_EndpointDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"
#include "OpcUaStackCore/StandardDataTypes/UserTokenPolicy.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EndpointDescription
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<EndpointDescription> SPtr;
        typedef std::vector<EndpointDescription::SPtr> Vec;
    
        EndpointDescription(void);
        EndpointDescription(const EndpointDescription& value);
        virtual ~EndpointDescription(void);
        
        OpcUaString& endpointUrl(void);
        ApplicationDescription& server(void);
        OpcUaApplicationInstanceCertificate& serverCertificate(void);
        MessageSecurityMode& securityMode(void);
        OpcUaString& securityPolicyUri(void);
        UserTokenPolicyArray& userIdentityTokens(void);
        OpcUaString& transportProfileUri(void);
        OpcUaByte& securityLevel(void);
        
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
        
        void copyTo(EndpointDescription& value);
        bool operator==(const EndpointDescription& value);
        bool operator!=(const EndpointDescription& value);
        EndpointDescription& operator=(const EndpointDescription& value);
    
      private:
        OpcUaString endpointUrl_; //!< The network endpoint to use when connecting to the server.
        ApplicationDescription server_; //!< The description of the server.
        OpcUaApplicationInstanceCertificate serverCertificate_; //!< The server's application certificate.
        MessageSecurityMode securityMode_; //!< The security mode that must be used when connecting to the endpoint.
        OpcUaString securityPolicyUri_; //!< The security policy to use when connecting to the endpoint.
        UserTokenPolicyArray userIdentityTokens_; //!< The user identity tokens that can be used with this endpoint.
        OpcUaString transportProfileUri_; //!< The transport profile to use when connecting to the endpoint.
        OpcUaByte securityLevel_; //!< A server assigned value that indicates how secure the endpoint is relative to other server endpoints.
    
    };
    
    class DLLEXPORT EndpointDescriptionArray
    : public OpcUaArray<EndpointDescription::SPtr, SPtrTypeCoder<EndpointDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EndpointDescriptionArray> SPtr;
    };

}

#endif
