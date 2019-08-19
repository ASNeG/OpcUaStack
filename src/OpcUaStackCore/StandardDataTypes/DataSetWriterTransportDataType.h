/*
    DataTypeClass: DataSetWriterTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataSetWriterTransportDataType_h__
#define __OpcUaStackCore_DataSetWriterTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataSetWriterTransportDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DataSetWriterTransportDataType> SPtr;
        typedef std::vector<DataSetWriterTransportDataType::SPtr> Vec;
    
        DataSetWriterTransportDataType(void);
        DataSetWriterTransportDataType(const DataSetWriterTransportDataType& value);
        virtual ~DataSetWriterTransportDataType(void);
        
        
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
        
        void copyTo(DataSetWriterTransportDataType& value);
        bool operator==(const DataSetWriterTransportDataType& value);
        bool operator!=(const DataSetWriterTransportDataType& value);
        DataSetWriterTransportDataType& operator=(const DataSetWriterTransportDataType& value);
    
      private:
    
    };
    
    class DLLEXPORT DataSetWriterTransportDataTypeArray
    : public OpcUaArray<DataSetWriterTransportDataType::SPtr, SPtrTypeCoder<DataSetWriterTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataSetWriterTransportDataTypeArray> SPtr;
    };

}

#endif
