/*
    DataTypeClass: BrokerDataSetReaderTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerDataSetReaderTransportDataType_h__
#define __OpcUaStackCore_BrokerDataSetReaderTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetReaderTransportDataType.h"
#include "OpcUaStackCore/StandardDataTypes/BrokerTransportQualityOfService.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BrokerDataSetReaderTransportDataType
    : public DataSetReaderTransportDataType
    {
      public:
        typedef boost::shared_ptr<BrokerDataSetReaderTransportDataType> SPtr;
        typedef std::vector<BrokerDataSetReaderTransportDataType::SPtr> Vec;
    
        BrokerDataSetReaderTransportDataType(void);
        BrokerDataSetReaderTransportDataType(const BrokerDataSetReaderTransportDataType& value);
        virtual ~BrokerDataSetReaderTransportDataType(void);
        
        OpcUaString& queueName(void);
        OpcUaString& resourceUri(void);
        OpcUaString& authenticationProfileUri(void);
        BrokerTransportQualityOfService& requestedDeliveryGuarantee(void);
        OpcUaString& metaDataQueueName(void);
        
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
        
        void copyTo(BrokerDataSetReaderTransportDataType& value);
        bool operator==(const BrokerDataSetReaderTransportDataType& value);
        bool operator!=(const BrokerDataSetReaderTransportDataType& value);
        BrokerDataSetReaderTransportDataType& operator=(const BrokerDataSetReaderTransportDataType& value);
    
      private:
        OpcUaString queueName_;
        OpcUaString resourceUri_;
        OpcUaString authenticationProfileUri_;
        BrokerTransportQualityOfService requestedDeliveryGuarantee_;
        OpcUaString metaDataQueueName_;
    
    };
    
    class DLLEXPORT BrokerDataSetReaderTransportDataTypeArray
    : public OpcUaArray<BrokerDataSetReaderTransportDataType::SPtr, SPtrTypeCoder<BrokerDataSetReaderTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BrokerDataSetReaderTransportDataTypeArray> SPtr;
    };

}

#endif
