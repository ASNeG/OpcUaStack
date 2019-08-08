/*
    DataTypeClass: UserIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UserIdentityToken_h__
#define __OpcUaStackCore_UserIdentityToken_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UserIdentityToken
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<UserIdentityToken> SPtr;
        typedef std::vector<UserIdentityToken::SPtr> Vec;
    
        UserIdentityToken(void);
        UserIdentityToken(const UserIdentityToken& value);
        virtual ~UserIdentityToken(void);
        
        OpcUaString& policyId(void);
        
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
        
        void copyTo(UserIdentityToken& value);
        bool operator==(const UserIdentityToken& value);
        bool operator!=(const UserIdentityToken& value);
        UserIdentityToken& operator=(const UserIdentityToken& value);
    
      private:
        OpcUaString policyId_; //!< The policy id specified in a user token policy for the endpoint being used.
    
    };
    
    class DLLEXPORT UserIdentityTokenArray
    : public OpcUaArray<UserIdentityToken::SPtr, SPtrTypeCoder<UserIdentityToken> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UserIdentityTokenArray> SPtr;
    };

}

#endif
