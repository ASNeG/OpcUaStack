/*
    DataTypeClass: PubSubConfigurationDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
