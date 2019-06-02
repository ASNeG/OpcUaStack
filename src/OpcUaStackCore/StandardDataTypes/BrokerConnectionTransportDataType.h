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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
