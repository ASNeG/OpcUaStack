/*
    DataTypeClass: IssuedIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_IssuedIdentityToken_h__
#define __OpcUaStackCore_IssuedIdentityToken_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/UserIdentityToken.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT IssuedIdentityToken
    : public UserIdentityToken
    {
      public:
        typedef boost::shared_ptr<IssuedIdentityToken> SPtr;
        typedef std::vector<IssuedIdentityToken::SPtr> Vec;
    
        IssuedIdentityToken(void);
        IssuedIdentityToken(const IssuedIdentityToken& value);
        virtual ~IssuedIdentityToken(void);
        
        OpcUaByteString& tokenData(void);
        OpcUaString& encryptionAlgorithm(void);
        
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
        
        void copyTo(IssuedIdentityToken& value);
        bool operator==(const IssuedIdentityToken& value);
        bool operator!=(const IssuedIdentityToken& value);
        IssuedIdentityToken& operator=(const IssuedIdentityToken& value);
    
      private:
        OpcUaByteString tokenData_; //!< The XML token encrypted with the server certificate.
        OpcUaString encryptionAlgorithm_; //!< The algorithm used to encrypt the certificate.
    
    };
    
    class DLLEXPORT IssuedIdentityTokenArray
    : public OpcUaArray<IssuedIdentityToken::SPtr, SPtrTypeCoder<IssuedIdentityToken> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<IssuedIdentityTokenArray> SPtr;
    };

}

#endif
