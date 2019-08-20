/*
    DataTypeClass: X509IdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_X509IdentityToken_h__
#define __OpcUaStackCore_X509IdentityToken_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/UserIdentityToken.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT X509IdentityToken
    : public UserIdentityToken
    {
      public:
        typedef boost::shared_ptr<X509IdentityToken> SPtr;
        typedef std::vector<X509IdentityToken::SPtr> Vec;
    
        X509IdentityToken(void);
        X509IdentityToken(const X509IdentityToken& value);
        virtual ~X509IdentityToken(void);
        
        OpcUaByteString& certificateData(void);
        
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
        
        void copyTo(X509IdentityToken& value);
        bool operator==(const X509IdentityToken& value);
        bool operator!=(const X509IdentityToken& value);
        X509IdentityToken& operator=(const X509IdentityToken& value);
    
      private:
        OpcUaByteString certificateData_; //!< The certificate.
    
    };
    
    class DLLEXPORT X509IdentityTokenArray
    : public OpcUaArray<X509IdentityToken::SPtr, SPtrTypeCoder<X509IdentityToken> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<X509IdentityTokenArray> SPtr;
    };

}

#endif
