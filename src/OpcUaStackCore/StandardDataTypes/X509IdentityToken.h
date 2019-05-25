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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
