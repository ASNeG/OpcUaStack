/*
    DataTypeClass: MdnsDiscoveryConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MdnsDiscoveryConfiguration_h__
#define __OpcUaStackCore_MdnsDiscoveryConfiguration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DiscoveryConfiguration.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT MdnsDiscoveryConfiguration
    : public DiscoveryConfiguration
    {
      public:
        typedef boost::shared_ptr<MdnsDiscoveryConfiguration> SPtr;
        typedef std::vector<MdnsDiscoveryConfiguration::SPtr> Vec;
    
        MdnsDiscoveryConfiguration(void);
        MdnsDiscoveryConfiguration(const MdnsDiscoveryConfiguration& value);
        virtual ~MdnsDiscoveryConfiguration(void);
        
        OpcUaString& mdnsServerName(void);
        OpcUaStringArray& serverCapabilities(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(MdnsDiscoveryConfiguration& value);
        bool operator==(const MdnsDiscoveryConfiguration& value);
        bool operator!=(const MdnsDiscoveryConfiguration& value);
        MdnsDiscoveryConfiguration& operator=(const MdnsDiscoveryConfiguration& value);
    
      private:
        OpcUaString mdnsServerName_; //!< The name for server that is broadcast via mDNS.
        OpcUaStringArray serverCapabilities_; //!< The server capabilities that are broadcast via mDNS.
    
    };
    
    class DLLEXPORT MdnsDiscoveryConfigurationArray
    : public OpcUaArray<MdnsDiscoveryConfiguration::SPtr, SPtrTypeCoder<MdnsDiscoveryConfiguration> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MdnsDiscoveryConfigurationArray> SPtr;
    };

}

#endif
