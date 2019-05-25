/*
    DataTypeClass: ServiceCounterDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ServiceCounterDataType_h__
#define __OpcUaStackCore_ServiceCounterDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ServiceCounterDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ServiceCounterDataType> SPtr;
        typedef std::vector<ServiceCounterDataType::SPtr> Vec;
    
        ServiceCounterDataType(void);
        ServiceCounterDataType(const ServiceCounterDataType& value);
        virtual ~ServiceCounterDataType(void);
        
        OpcUaUInt32& totalCount(void);
        OpcUaUInt32& errorCount(void);
        
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
        
        void copyTo(ServiceCounterDataType& value);
        bool operator==(const ServiceCounterDataType& value);
        bool operator!=(const ServiceCounterDataType& value);
        ServiceCounterDataType& operator=(const ServiceCounterDataType& value);
    
      private:
        OpcUaUInt32 totalCount_;
        OpcUaUInt32 errorCount_;
    
    };
    
    class DLLEXPORT ServiceCounterDataTypeArray
    : public OpcUaArray<ServiceCounterDataType::SPtr, SPtrTypeCoder<ServiceCounterDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ServiceCounterDataTypeArray> SPtr;
    };

}

#endif
