/*
    DataTypeClass: DatagramWriterGroupTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DatagramWriterGroupTransportDataType_h__
#define __OpcUaStackCore_DatagramWriterGroupTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/WriterGroupTransportDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DatagramWriterGroupTransportDataType
    : public WriterGroupTransportDataType
    {
      public:
        typedef boost::shared_ptr<DatagramWriterGroupTransportDataType> SPtr;
        typedef std::vector<DatagramWriterGroupTransportDataType::SPtr> Vec;
    
        DatagramWriterGroupTransportDataType(void);
        DatagramWriterGroupTransportDataType(const DatagramWriterGroupTransportDataType& value);
        virtual ~DatagramWriterGroupTransportDataType(void);
        
        OpcUaByte& messageRepeatCount(void);
        OpcUaDuration& messageRepeatDelay(void);
        
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
        
        void copyTo(DatagramWriterGroupTransportDataType& value);
        bool operator==(const DatagramWriterGroupTransportDataType& value);
        bool operator!=(const DatagramWriterGroupTransportDataType& value);
        DatagramWriterGroupTransportDataType& operator=(const DatagramWriterGroupTransportDataType& value);
    
      private:
        OpcUaByte messageRepeatCount_;
        OpcUaDuration messageRepeatDelay_;
    
    };
    
    class DLLEXPORT DatagramWriterGroupTransportDataTypeArray
    : public OpcUaArray<DatagramWriterGroupTransportDataType::SPtr, SPtrTypeCoder<DatagramWriterGroupTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DatagramWriterGroupTransportDataTypeArray> SPtr;
    };

}

#endif
