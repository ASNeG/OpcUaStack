/*
    DataTypeClass: BrokerWriterGroupTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerWriterGroupTransportDataType_h__
#define __OpcUaStackCore_BrokerWriterGroupTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
