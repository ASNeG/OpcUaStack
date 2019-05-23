/*
    DataTypeClass: BrokerDataSetWriterTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerDataSetWriterTransportDataType_h__
#define __OpcUaStackCore_BrokerDataSetWriterTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetWriterTransportDataType.h"
#include "OpcUaStackCore/StandardDataTypes/BrokerTransportQualityOfService.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BrokerDataSetWriterTransportDataType
    : public DataSetWriterTransportDataType
    {
      public:
        typedef boost::shared_ptr<BrokerDataSetWriterTransportDataType> SPtr;
        typedef std::vector<BrokerDataSetWriterTransportDataType::SPtr> Vec;
    
        BrokerDataSetWriterTransportDataType(void);
        BrokerDataSetWriterTransportDataType(const BrokerDataSetWriterTransportDataType& value);
        virtual ~BrokerDataSetWriterTransportDataType(void);
        
        OpcUaString& queueName(void);
        OpcUaString& resourceUri(void);
        OpcUaString& authenticationProfileUri(void);
        BrokerTransportQualityOfService& requestedDeliveryGuarantee(void);
        OpcUaString& metaDataQueueName(void);
        OpcUaDuration& metaDataUpdateTime(void);
        
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
        
        void copyTo(BrokerDataSetWriterTransportDataType& value);
        bool operator==(const BrokerDataSetWriterTransportDataType& value);
        bool operator!=(const BrokerDataSetWriterTransportDataType& value);
        BrokerDataSetWriterTransportDataType& operator=(const BrokerDataSetWriterTransportDataType& value);
    
      private:
        OpcUaString queueName_;
        OpcUaString resourceUri_;
        OpcUaString authenticationProfileUri_;
        BrokerTransportQualityOfService requestedDeliveryGuarantee_;
        OpcUaString metaDataQueueName_;
        OpcUaDuration metaDataUpdateTime_;
    
    };
    
    class DLLEXPORT BrokerDataSetWriterTransportDataTypeArray
    : public OpcUaArray<BrokerDataSetWriterTransportDataType::SPtr, SPtrTypeCoder<BrokerDataSetWriterTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BrokerDataSetWriterTransportDataTypeArray> SPtr;
    };

}

#endif
