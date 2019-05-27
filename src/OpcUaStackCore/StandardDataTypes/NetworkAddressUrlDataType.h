/*
    DataTypeClass: NetworkAddressUrlDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
