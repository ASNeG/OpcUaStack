/*
    DataTypeClass: BrokerWriterGroupTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerWriterGroupTransportDataType_h__
#define __OpcUaStackCore_BrokerWriterGroupTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/WriterGroupTransportDataType.h"
#include "OpcUaStackCore/StandardDataTypes/BrokerTransportQualityOfService.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BrokerWriterGroupTransportDataType
    : public WriterGroupTransportDataType
    {
      public:
        typedef boost::shared_ptr<BrokerWriterGroupTransportDataType> SPtr;
        typedef std::vector<BrokerWriterGroupTransportDataType::SPtr> Vec;
    
        BrokerWriterGroupTransportDataType(void);
        BrokerWriterGroupTransportDataType(const BrokerWriterGroupTransportDataType& value);
        virtual ~BrokerWriterGroupTransportDataType(void);
        
        OpcUaString& queueName(void);
        OpcUaString& resourceUri(void);
        OpcUaString& authenticationProfileUri(void);
        BrokerTransportQualityOfService& requestedDeliveryGuarantee(void);
        
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
        
        void copyTo(BrokerWriterGroupTransportDataType& value);
        bool operator==(const BrokerWriterGroupTransportDataType& value);
        bool operator!=(const BrokerWriterGroupTransportDataType& value);
        BrokerWriterGroupTransportDataType& operator=(const BrokerWriterGroupTransportDataType& value);
    
      private:
        OpcUaString queueName_;
        OpcUaString resourceUri_;
        OpcUaString authenticationProfileUri_;
        BrokerTransportQualityOfService requestedDeliveryGuarantee_;
    
    };
    
    class DLLEXPORT BrokerWriterGroupTransportDataTypeArray
    : public OpcUaArray<BrokerWriterGroupTransportDataType::SPtr, SPtrTypeCoder<BrokerWriterGroupTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BrokerWriterGroupTransportDataTypeArray> SPtr;
    };

}

#endif
