/*
    DataTypeClass: NetworkAddressDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NetworkAddressDataType_h__
#define __OpcUaStackCore_NetworkAddressDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NetworkAddressDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NetworkAddressDataType> SPtr;
        typedef std::vector<NetworkAddressDataType::SPtr> Vec;
    
        NetworkAddressDataType(void);
        NetworkAddressDataType(const NetworkAddressDataType& value);
        virtual ~NetworkAddressDataType(void);
        
        OpcUaString& networkInterface(void);
        
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
        
        void copyTo(NetworkAddressDataType& value);
        bool operator==(const NetworkAddressDataType& value);
        bool operator!=(const NetworkAddressDataType& value);
        NetworkAddressDataType& operator=(const NetworkAddressDataType& value);
    
      private:
        OpcUaString networkInterface_;
    
    };
    
    class DLLEXPORT NetworkAddressDataTypeArray
    : public OpcUaArray<NetworkAddressDataType::SPtr, SPtrTypeCoder<NetworkAddressDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NetworkAddressDataTypeArray> SPtr;
    };

}

#endif
