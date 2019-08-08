/*
    DataTypeClass: PubSubConfigurationDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PubSubConfigurationDataType_h__
#define __OpcUaStackCore_PubSubConfigurationDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/PublishedDataSetDataType.h"
#include "OpcUaStackCore/StandardDataTypes/PubSubConnectionDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PubSubConfigurationDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<PubSubConfigurationDataType> SPtr;
        typedef std::vector<PubSubConfigurationDataType::SPtr> Vec;
    
        PubSubConfigurationDataType(void);
        PubSubConfigurationDataType(const PubSubConfigurationDataType& value);
        virtual ~PubSubConfigurationDataType(void);
        
        PublishedDataSetDataTypeArray& publishedDataSets(void);
        PubSubConnectionDataTypeArray& connections(void);
        OpcUaBoolean& enabled(void);
        
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
        
        void copyTo(PubSubConfigurationDataType& value);
        bool operator==(const PubSubConfigurationDataType& value);
        bool operator!=(const PubSubConfigurationDataType& value);
        PubSubConfigurationDataType& operator=(const PubSubConfigurationDataType& value);
    
      private:
        PublishedDataSetDataTypeArray publishedDataSets_;
        PubSubConnectionDataTypeArray connections_;
        OpcUaBoolean enabled_;
    
    };
    
    class DLLEXPORT PubSubConfigurationDataTypeArray
    : public OpcUaArray<PubSubConfigurationDataType::SPtr, SPtrTypeCoder<PubSubConfigurationDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PubSubConfigurationDataTypeArray> SPtr;
    };

}

#endif
