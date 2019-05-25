/*
    DataTypeClass: MdnsDiscoveryConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MdnsDiscoveryConfiguration_h__
#define __OpcUaStackCore_MdnsDiscoveryConfiguration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
