/*
    DataTypeClass: SignedSoftwareCertificate

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SignedSoftwareCertificate_h__
#define __OpcUaStackCore_SignedSoftwareCertificate_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SignedSoftwareCertificate
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SignedSoftwareCertificate> SPtr;
        typedef std::vector<SignedSoftwareCertificate::SPtr> Vec;
    
        SignedSoftwareCertificate(void);
        SignedSoftwareCertificate(const SignedSoftwareCertificate& value);
        virtual ~SignedSoftwareCertificate(void);
        
        OpcUaByteString& certificateData(void);
        OpcUaByteString& signature(void);
        
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
        
        void copyTo(SignedSoftwareCertificate& value);
        bool operator==(const SignedSoftwareCertificate& value);
        bool operator!=(const SignedSoftwareCertificate& value);
        SignedSoftwareCertificate& operator=(const SignedSoftwareCertificate& value);
    
      private:
        OpcUaByteString certificateData_; //!< The data of the certificate.
        OpcUaByteString signature_; //!< The digital signature.
    
    };
    
    class DLLEXPORT SignedSoftwareCertificateArray
    : public OpcUaArray<SignedSoftwareCertificate::SPtr, SPtrTypeCoder<SignedSoftwareCertificate> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SignedSoftwareCertificateArray> SPtr;
    };

}

#endif
