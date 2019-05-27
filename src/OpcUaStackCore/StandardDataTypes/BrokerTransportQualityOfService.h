/*
    EnumTypeClass: BrokerTransportQualityOfService

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerTransportQualityOfService_h__
#define __OpcUaStackCore_BrokerTransportQualityOfService_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BrokerTransportQualityOfService
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<BrokerTransportQualityOfService> SPtr;
    
        typedef enum {
            EnumNotSpecified = 0,
            EnumBestEffort = 1,
            EnumAtLeastOnce = 2,
            EnumAtMostOnce = 3,
            EnumExactlyOnce = 4,
        } Enum;
    
        BrokerTransportQualityOfService(void);
        BrokerTransportQualityOfService(Enum enumeration);
        BrokerTransportQualityOfService(BrokerTransportQualityOfService& value);
        virtual ~BrokerTransportQualityOfService(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
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
        
        void copyTo(BrokerTransportQualityOfService& value);
        bool operator==(const BrokerTransportQualityOfService& value) const;
        bool operator!=(const BrokerTransportQualityOfService& value) const;
        BrokerTransportQualityOfService& operator=(const BrokerTransportQualityOfService& value);
        BrokerTransportQualityOfService& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT BrokerTransportQualityOfServiceArray
    : public OpcUaArray<BrokerTransportQualityOfService::SPtr, SPtrTypeCoder<BrokerTransportQualityOfService> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BrokerTransportQualityOfServiceArray> SPtr;
    };

}

#endif
