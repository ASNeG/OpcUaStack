/*
    DataTypeClass: BrokerConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerConnectionTransportDataType_h__
#define __OpcUaStackCore_BrokerConnectionTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ConnectionTransportDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BrokerConnectionTransportDataType
    : public ConnectionTransportDataType
    {
      public:
        typedef boost::shared_ptr<BrokerConnectionTransportDataType> SPtr;
        typedef std::vector<BrokerConnectionTransportDataType::SPtr> Vec;
    
        BrokerConnectionTransportDataType(void);
        BrokerConnectionTransportDataType(const BrokerConnectionTransportDataType& value);
        virtual ~BrokerConnectionTransportDataType(void);
        
        OpcUaString& resourceUri(void);
        OpcUaString& authenticationProfileUri(void);
        
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
        
        void copyTo(BrokerConnectionTransportDataType& value);
        bool operator==(const BrokerConnectionTransportDataType& value);
        bool operator!=(const BrokerConnectionTransportDataType& value);
        BrokerConnectionTransportDataType& operator=(const BrokerConnectionTransportDataType& value);
    
      private:
        OpcUaString resourceUri_;
        OpcUaString authenticationProfileUri_;
    
    };
    
    class DLLEXPORT BrokerConnectionTransportDataTypeArray
    : public OpcUaArray<BrokerConnectionTransportDataType::SPtr, SPtrTypeCoder<BrokerConnectionTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BrokerConnectionTransportDataTypeArray> SPtr;
    };

}

#endif
