/*
    DataTypeClass: UserTokenPolicy

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UserTokenPolicy_h__
#define __OpcUaStackCore_UserTokenPolicy_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/UserTokenType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UserTokenPolicy
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<UserTokenPolicy> SPtr;
        typedef std::vector<UserTokenPolicy::SPtr> Vec;
    
        UserTokenPolicy(void);
        UserTokenPolicy(const UserTokenPolicy& value);
        virtual ~UserTokenPolicy(void);
        
        OpcUaString& policyId(void);
        UserTokenType& tokenType(void);
        OpcUaString& issuedTokenType(void);
        OpcUaString& issuerEndpointUrl(void);
        OpcUaString& securityPolicyUri(void);
        
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
        
        void copyTo(UserTokenPolicy& value);
        bool operator==(const UserTokenPolicy& value);
        bool operator!=(const UserTokenPolicy& value);
        UserTokenPolicy& operator=(const UserTokenPolicy& value);
    
      private:
        OpcUaString policyId_; //!< A identifier for the policy assigned by the server.
        UserTokenType tokenType_; //!< The type of user token.
        OpcUaString issuedTokenType_; //!< The type of issued token.
        OpcUaString issuerEndpointUrl_; //!< The endpoint or any other information need to contruct an issued token URL.
        OpcUaString securityPolicyUri_; //!< The security policy to use when encrypting or signing the user token.
    
    };
    
    class DLLEXPORT UserTokenPolicyArray
    : public OpcUaArray<UserTokenPolicy::SPtr, SPtrTypeCoder<UserTokenPolicy> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UserTokenPolicyArray> SPtr;
    };

}

#endif
