/*
    DataTypeClass: ServerOnNetwork

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ServerOnNetwork_h__
#define __OpcUaStackCore_ServerOnNetwork_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ServerOnNetwork
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ServerOnNetwork> SPtr;
        typedef std::vector<ServerOnNetwork::SPtr> Vec;
    
        ServerOnNetwork(void);
        ServerOnNetwork(const ServerOnNetwork& value);
        virtual ~ServerOnNetwork(void);
        
        OpcUaUInt32& recordId(void);
        OpcUaString& serverName(void);
        OpcUaString& discoveryUrl(void);
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
        
        void copyTo(ServerOnNetwork& value);
        bool operator==(const ServerOnNetwork& value);
        bool operator!=(const ServerOnNetwork& value);
        ServerOnNetwork& operator=(const ServerOnNetwork& value);
    
      private:
        OpcUaUInt32 recordId_;
        OpcUaString serverName_;
        OpcUaString discoveryUrl_;
        OpcUaStringArray serverCapabilities_;
    
    };
    
    class DLLEXPORT ServerOnNetworkArray
    : public OpcUaArray<ServerOnNetwork::SPtr, SPtrTypeCoder<ServerOnNetwork> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ServerOnNetworkArray> SPtr;
    };

}

#endif
