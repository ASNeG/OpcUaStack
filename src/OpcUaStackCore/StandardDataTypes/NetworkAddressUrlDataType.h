/*
    DataTypeClass: NetworkAddressUrlDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NetworkAddressUrlDataType_h__
#define __OpcUaStackCore_NetworkAddressUrlDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NetworkAddressDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NetworkAddressUrlDataType
    : public NetworkAddressDataType
    {
      public:
        typedef boost::shared_ptr<NetworkAddressUrlDataType> SPtr;
        typedef std::vector<NetworkAddressUrlDataType::SPtr> Vec;
    
        NetworkAddressUrlDataType(void);
        NetworkAddressUrlDataType(const NetworkAddressUrlDataType& value);
        virtual ~NetworkAddressUrlDataType(void);
        
        OpcUaString& url(void);
        
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
        
        void copyTo(NetworkAddressUrlDataType& value);
        bool operator==(const NetworkAddressUrlDataType& value);
        bool operator!=(const NetworkAddressUrlDataType& value);
        NetworkAddressUrlDataType& operator=(const NetworkAddressUrlDataType& value);
    
      private:
        OpcUaString url_;
    
    };
    
    class DLLEXPORT NetworkAddressUrlDataTypeArray
    : public OpcUaArray<NetworkAddressUrlDataType::SPtr, SPtrTypeCoder<NetworkAddressUrlDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NetworkAddressUrlDataTypeArray> SPtr;
    };

}

#endif
