/*
    DataTypeClass: DataSetMetaDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataSetMetaDataType_h__
#define __OpcUaStackCore_DataSetMetaDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
