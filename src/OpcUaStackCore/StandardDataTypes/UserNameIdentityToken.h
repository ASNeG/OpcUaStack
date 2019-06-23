/*
    DataTypeClass: UserNameIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UserNameIdentityToken_h__
#define __OpcUaStackCore_UserNameIdentityToken_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/UserIdentityToken.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UserNameIdentityToken
    : public UserIdentityToken
    {
      public:
        typedef boost::shared_ptr<UserNameIdentityToken> SPtr;
        typedef std::vector<UserNameIdentityToken::SPtr> Vec;
    
        UserNameIdentityToken(void);
        UserNameIdentityToken(const UserNameIdentityToken& value);
        virtual ~UserNameIdentityToken(void);
        
        OpcUaString& userName(void);
        OpcUaByteString& password(void);
        OpcUaString& encryptionAlgorithm(void);
        
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
        
        void copyTo(UserNameIdentityToken& value);
        bool operator==(const UserNameIdentityToken& value);
        bool operator!=(const UserNameIdentityToken& value);
        UserNameIdentityToken& operator=(const UserNameIdentityToken& value);
    
      private:
        OpcUaString userName_; //!< The user name.
        OpcUaByteString password_; //!< The password encrypted with the server certificate.
        OpcUaString encryptionAlgorithm_; //!< The algorithm used to encrypt the password.
    
    };
    
    class DLLEXPORT UserNameIdentityTokenArray
    : public OpcUaArray<UserNameIdentityToken::SPtr, SPtrTypeCoder<UserNameIdentityToken> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UserNameIdentityTokenArray> SPtr;
    };

}

#endif
