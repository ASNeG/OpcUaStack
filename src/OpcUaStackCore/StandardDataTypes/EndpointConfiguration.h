/*
    DataTypeClass: EndpointConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EndpointConfiguration_h__
#define __OpcUaStackCore_EndpointConfiguration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EndpointConfiguration
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<EndpointConfiguration> SPtr;
        typedef std::vector<EndpointConfiguration::SPtr> Vec;
    
        EndpointConfiguration(void);
        EndpointConfiguration(const EndpointConfiguration& value);
        virtual ~EndpointConfiguration(void);
        
        OpcUaInt32& operationTimeout(void);
        OpcUaBoolean& useBinaryEncoding(void);
        OpcUaInt32& maxStringLength(void);
        OpcUaInt32& maxByteStringLength(void);
        OpcUaInt32& maxArrayLength(void);
        OpcUaInt32& maxMessageSize(void);
        OpcUaInt32& maxBufferSize(void);
        OpcUaInt32& channelLifetime(void);
        OpcUaInt32& securityTokenLifetime(void);
        
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
        
        void copyTo(EndpointConfiguration& value);
        bool operator==(const EndpointConfiguration& value);
        bool operator!=(const EndpointConfiguration& value);
        EndpointConfiguration& operator=(const EndpointConfiguration& value);
    
      private:
        OpcUaInt32 operationTimeout_;
        OpcUaBoolean useBinaryEncoding_;
        OpcUaInt32 maxStringLength_;
        OpcUaInt32 maxByteStringLength_;
        OpcUaInt32 maxArrayLength_;
        OpcUaInt32 maxMessageSize_;
        OpcUaInt32 maxBufferSize_;
        OpcUaInt32 channelLifetime_;
        OpcUaInt32 securityTokenLifetime_;
    
    };
    
    class DLLEXPORT EndpointConfigurationArray
    : public OpcUaArray<EndpointConfiguration::SPtr, SPtrTypeCoder<EndpointConfiguration> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EndpointConfigurationArray> SPtr;
    };

}

#endif
