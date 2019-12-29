/*
    DataTypeClass: TrustListDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_TrustListDataType_h__
#define __OpcUaStackCore_TrustListDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT TrustListDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<TrustListDataType> SPtr;
        typedef std::vector<TrustListDataType::SPtr> Vec;
    
        TrustListDataType(void);
        TrustListDataType(const TrustListDataType& value);
        virtual ~TrustListDataType(void);
        
        OpcUaUInt32& specifiedLists(void);
        OpcUaByteStringArray& trustedCertificates(void);
        OpcUaByteStringArray& trustedCrls(void);
        OpcUaByteStringArray& issuerCertificates(void);
        OpcUaByteStringArray& issuerCrls(void);
        
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
        
        void copyTo(TrustListDataType& value);
        bool operator==(const TrustListDataType& value);
        bool operator!=(const TrustListDataType& value);
        TrustListDataType& operator=(const TrustListDataType& value);
    
      private:
        OpcUaUInt32 specifiedLists_;
        OpcUaByteStringArray trustedCertificates_;
        OpcUaByteStringArray trustedCrls_;
        OpcUaByteStringArray issuerCertificates_;
        OpcUaByteStringArray issuerCrls_;
    
    };
    
    class DLLEXPORT TrustListDataTypeArray
    : public OpcUaArray<TrustListDataType::SPtr, SPtrTypeCoder<TrustListDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<TrustListDataTypeArray> SPtr;
    };

}

#endif
