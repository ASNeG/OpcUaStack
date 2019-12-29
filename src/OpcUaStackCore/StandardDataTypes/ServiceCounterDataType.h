/*
    DataTypeClass: ServiceCounterDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ServiceCounterDataType_h__
#define __OpcUaStackCore_ServiceCounterDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

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
