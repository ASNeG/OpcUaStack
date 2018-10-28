/*
    DataTypeClass: ServerStatusDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ServerStatusDataType_h__
#define __OpcUaStackCore_ServerStatusDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ServerState.h"
#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{
    
    class ServerStatusDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ServerStatusDataType> SPtr;
    
        ServerStatusDataType(void);
        virtual ~ServerStatusDataType(void);
        
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& currentTime(void);
        ServerState& state(void);
        BuildInfo& buildInfo(void);
        OpcUaUInt32& secondsTillShutdown(void);
        OpcUaLocalizedText& shutdownReason(void);
        
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
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(ServerStatusDataType& value);
        bool operator==(const ServerStatusDataType& value) const;
        bool operator!=(const ServerStatusDataType& value) const;
        ServerStatusDataType& operator=(const ServerStatusDataType& value);
    
      private:
        OpcUaUtcTime startTime_;
        OpcUaUtcTime currentTime_;
        ServerState state_;
        BuildInfo buildInfo_;
        OpcUaUInt32 secondsTillShutdown_;
        OpcUaLocalizedText shutdownReason_;
    
    };

}

#endif
