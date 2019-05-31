/*
    DataTypeClass: DataSetMetaDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataSetMetaDataType_h__
#define __OpcUaStackCore_DataSetMetaDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeSchemaHeader.h"
#include "OpcUaStackCore/StandardDataTypes/FieldMetaData.h"
#include "OpcUaStackCore/StandardDataTypes/ConfigurationVersionDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataSetMetaDataType
    : public DataTypeSchemaHeader
    {
      public:
        typedef boost::shared_ptr<DataSetMetaDataType> SPtr;
        typedef std::vector<DataSetMetaDataType::SPtr> Vec;
    
        DataSetMetaDataType(void);
        DataSetMetaDataType(const DataSetMetaDataType& value);
        virtual ~DataSetMetaDataType(void);
        
        OpcUaString& name(void);
        OpcUaLocalizedText& description(void);
        FieldMetaDataArray& fields(void);
        OpcUaGuid& dataSetClassId(void);
        ConfigurationVersionDataType& configurationVersion(void);
        
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
        
        void copyTo(DataSetMetaDataType& value);
        bool operator==(const DataSetMetaDataType& value);
        bool operator!=(const DataSetMetaDataType& value);
        DataSetMetaDataType& operator=(const DataSetMetaDataType& value);
    
      private:
        OpcUaString name_;
        OpcUaLocalizedText description_;
        FieldMetaDataArray fields_;
        OpcUaGuid dataSetClassId_;
        ConfigurationVersionDataType configurationVersion_;
    
    };
    
    class DLLEXPORT DataSetMetaDataTypeArray
    : public OpcUaArray<DataSetMetaDataType::SPtr, SPtrTypeCoder<DataSetMetaDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataSetMetaDataTypeArray> SPtr;
    };

}

#endif
