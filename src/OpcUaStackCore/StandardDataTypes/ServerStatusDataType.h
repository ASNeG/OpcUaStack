/*
    DataTypeClass: ServerStatusDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ServerStatusDataType_h__
#define __OpcUaStackCore_ServerStatusDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ServerState.h"
#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ServerStatusDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ServerStatusDataType> SPtr;
        typedef std::vector<ServerStatusDataType::SPtr> Vec;
    
        ServerStatusDataType(void);
        ServerStatusDataType(const ServerStatusDataType& value);
        virtual ~ServerStatusDataType(void);
        
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& currentTime(void);
        ServerState& state(void);
        BuildInfo& buildInfo(void);
        OpcUaUInt32& secondsTillShutdown(void);
        OpcUaLocalizedText& shutdownReason(void);
        
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
        
        void copyTo(ServerStatusDataType& value);
        bool operator==(const ServerStatusDataType& value);
        bool operator!=(const ServerStatusDataType& value);
        ServerStatusDataType& operator=(const ServerStatusDataType& value);
    
      private:
        OpcUaUtcTime startTime_;
        OpcUaUtcTime currentTime_;
        ServerState state_;
        BuildInfo buildInfo_;
        OpcUaUInt32 secondsTillShutdown_;
        OpcUaLocalizedText shutdownReason_;
    
    };
    
    class DLLEXPORT ServerStatusDataTypeArray
    : public OpcUaArray<ServerStatusDataType::SPtr, SPtrTypeCoder<ServerStatusDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ServerStatusDataTypeArray> SPtr;
    };

}

#endif
