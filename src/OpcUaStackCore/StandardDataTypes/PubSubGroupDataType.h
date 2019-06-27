/*
    DataTypeClass: PubSubGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PubSubGroupDataType_h__
#define __OpcUaStackCore_PubSubGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PubSubGroupDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<PubSubGroupDataType> SPtr;
        typedef std::vector<PubSubGroupDataType::SPtr> Vec;
    
        PubSubGroupDataType(void);
        PubSubGroupDataType(const PubSubGroupDataType& value);
        virtual ~PubSubGroupDataType(void);
        
        OpcUaString& name(void);
        OpcUaBoolean& enabled(void);
        MessageSecurityMode& securityMode(void);
        OpcUaString& securityGroupId(void);
        EndpointDescriptionArray& securityKeyServices(void);
        OpcUaUInt32& maxNetworkMessageSize(void);
        KeyValuePairArray& groupProperties(void);
        
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
        
        void copyTo(PubSubGroupDataType& value);
        bool operator==(const PubSubGroupDataType& value);
        bool operator!=(const PubSubGroupDataType& value);
        PubSubGroupDataType& operator=(const PubSubGroupDataType& value);
    
      private:
        OpcUaString name_;
        OpcUaBoolean enabled_;
        MessageSecurityMode securityMode_;
        OpcUaString securityGroupId_;
        EndpointDescriptionArray securityKeyServices_;
        OpcUaUInt32 maxNetworkMessageSize_;
        KeyValuePairArray groupProperties_;
    
    };
    
    class DLLEXPORT PubSubGroupDataTypeArray
    : public OpcUaArray<PubSubGroupDataType::SPtr, SPtrTypeCoder<PubSubGroupDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PubSubGroupDataTypeArray> SPtr;
    };

}

#endif
