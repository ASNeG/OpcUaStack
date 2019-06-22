/*
    DataTypeClass: TrustListDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_TrustListDataType_h__
#define __OpcUaStackCore_TrustListDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
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
