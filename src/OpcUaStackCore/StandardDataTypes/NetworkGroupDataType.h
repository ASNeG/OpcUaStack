/*
    DataTypeClass: NetworkGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NetworkGroupDataType_h__
#define __OpcUaStackCore_NetworkGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointUrlListDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NetworkGroupDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NetworkGroupDataType> SPtr;
        typedef std::vector<NetworkGroupDataType::SPtr> Vec;
    
        NetworkGroupDataType(void);
        NetworkGroupDataType(const NetworkGroupDataType& value);
        virtual ~NetworkGroupDataType(void);
        
        OpcUaString& serverUri(void);
        EndpointUrlListDataTypeArray& networkPaths(void);
        
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
        
        void copyTo(NetworkGroupDataType& value);
        bool operator==(const NetworkGroupDataType& value);
        bool operator!=(const NetworkGroupDataType& value);
        NetworkGroupDataType& operator=(const NetworkGroupDataType& value);
    
      private:
        OpcUaString serverUri_;
        EndpointUrlListDataTypeArray networkPaths_;
    
    };
    
    class DLLEXPORT NetworkGroupDataTypeArray
    : public OpcUaArray<NetworkGroupDataType::SPtr, SPtrTypeCoder<NetworkGroupDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NetworkGroupDataTypeArray> SPtr;
    };

}

#endif
