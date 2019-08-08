/*
    DataTypeClass: PublishedVariableDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedVariableDataType_h__
#define __OpcUaStackCore_PublishedVariableDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PublishedVariableDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<PublishedVariableDataType> SPtr;
        typedef std::vector<PublishedVariableDataType::SPtr> Vec;
    
        PublishedVariableDataType(void);
        PublishedVariableDataType(const PublishedVariableDataType& value);
        virtual ~PublishedVariableDataType(void);
        
        OpcUaNodeId& publishedVariable(void);
        OpcUaIntegerId& attributeId(void);
        OpcUaDuration& samplingIntervalHint(void);
        OpcUaUInt32& deadbandType(void);
        OpcUaDouble& deadbandValue(void);
        OpcUaNumericRange& indexRange(void);
        OpcUaVariant& substituteValue(void);
        OpcUaQualifiedNameArray& metaDataProperties(void);
        
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
        
        void copyTo(PublishedVariableDataType& value);
        bool operator==(const PublishedVariableDataType& value);
        bool operator!=(const PublishedVariableDataType& value);
        PublishedVariableDataType& operator=(const PublishedVariableDataType& value);
    
      private:
        OpcUaNodeId publishedVariable_;
        OpcUaIntegerId attributeId_;
        OpcUaDuration samplingIntervalHint_;
        OpcUaUInt32 deadbandType_;
        OpcUaDouble deadbandValue_;
        OpcUaNumericRange indexRange_;
        OpcUaVariant substituteValue_;
        OpcUaQualifiedNameArray metaDataProperties_;
    
    };
    
    class DLLEXPORT PublishedVariableDataTypeArray
    : public OpcUaArray<PublishedVariableDataType::SPtr, SPtrTypeCoder<PublishedVariableDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PublishedVariableDataTypeArray> SPtr;
    };

}

#endif
