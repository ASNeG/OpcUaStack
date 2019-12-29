/*
    DataTypeClass: PubSubGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PubSubGroupDataType_h__
#define __OpcUaStackCore_PubSubGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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
