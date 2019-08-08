/*
    DataTypeClass: EndpointConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EndpointConfiguration_h__
#define __OpcUaStackCore_EndpointConfiguration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

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
