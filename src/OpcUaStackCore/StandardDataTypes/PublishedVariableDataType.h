/*
    DataTypeClass: PublishedVariableDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
