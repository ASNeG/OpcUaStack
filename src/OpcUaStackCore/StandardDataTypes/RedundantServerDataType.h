/*
    DataTypeClass: RedundantServerDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RedundantServerDataType_h__
#define __OpcUaStackCore_RedundantServerDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ServerState.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RedundantServerDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<RedundantServerDataType> SPtr;
        typedef std::vector<RedundantServerDataType::SPtr> Vec;
    
        RedundantServerDataType(void);
        RedundantServerDataType(const RedundantServerDataType& value);
        virtual ~RedundantServerDataType(void);
        
        OpcUaString& serverId(void);
        OpcUaByte& serviceLevel(void);
        ServerState& serverState(void);
        
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
        
        void copyTo(RedundantServerDataType& value);
        bool operator==(const RedundantServerDataType& value);
        bool operator!=(const RedundantServerDataType& value);
        RedundantServerDataType& operator=(const RedundantServerDataType& value);
    
      private:
        OpcUaString serverId_;
        OpcUaByte serviceLevel_;
        ServerState serverState_;
    
    };
    
    class DLLEXPORT RedundantServerDataTypeArray
    : public OpcUaArray<RedundantServerDataType::SPtr, SPtrTypeCoder<RedundantServerDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RedundantServerDataTypeArray> SPtr;
    };

}

#endif
