/*
    DataTypeClass: BrokerConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BrokerConnectionTransportDataType_h__
#define __OpcUaStackCore_BrokerConnectionTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ConnectionTransportDataType.h"

namespace OpcUaStackCore
{
    
    class BrokerConnectionTransportDataType
    : public ConnectionTransportDataType
    {
      public:
        typedef boost::shared_ptr<BrokerConnectionTransportDataType> SPtr;
    
        BrokerConnectionTransportDataType(void);
        virtual ~BrokerConnectionTransportDataType(void);
        
        OpcUaString& resourceUri(void);
        OpcUaString& authenticationProfileUri(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(BrokerConnectionTransportDataType& value);
        bool operator==(const BrokerConnectionTransportDataType& value) const;
    
      private:
        OpcUaString resourceUri_;
        OpcUaString authenticationProfileUri_;
    
    };

}

#endif
