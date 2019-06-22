/*
    DataTypeClass: DataSetWriterTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataSetWriterTransportDataType_h__
#define __OpcUaStackCore_DataSetWriterTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
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
