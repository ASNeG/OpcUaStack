/*
    DataTypeClass: EndpointType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EndpointType_h__
#define __OpcUaStackCore_EndpointType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EndpointType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<EndpointType> SPtr;
        typedef std::vector<EndpointType::SPtr> Vec;
    
        EndpointType(void);
        EndpointType(const EndpointType& value);
        virtual ~EndpointType(void);
        
        OpcUaString& endpointUrl(void);
        MessageSecurityMode& securityMode(void);
        OpcUaString& securityPolicyUri(void);
        OpcUaString& transportProfileUri(void);
        
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
        
        void copyTo(EndpointType& value);
        bool operator==(const EndpointType& value);
        bool operator!=(const EndpointType& value);
        EndpointType& operator=(const EndpointType& value);
    
      private:
        OpcUaString endpointUrl_;
        MessageSecurityMode securityMode_;
        OpcUaString securityPolicyUri_;
        OpcUaString transportProfileUri_;
    
    };
    
    class DLLEXPORT EndpointTypeArray
    : public OpcUaArray<EndpointType::SPtr, SPtrTypeCoder<EndpointType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EndpointTypeArray> SPtr;
    };

}

#endif
