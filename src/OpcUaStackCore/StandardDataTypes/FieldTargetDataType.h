/*
    DataTypeClass: FieldTargetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_FieldTargetDataType_h__
#define __OpcUaStackCore_FieldTargetDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/OverrideValueHandling.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT FieldTargetDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<FieldTargetDataType> SPtr;
        typedef std::vector<FieldTargetDataType::SPtr> Vec;
    
        FieldTargetDataType(void);
        FieldTargetDataType(const FieldTargetDataType& value);
        virtual ~FieldTargetDataType(void);
        
        OpcUaGuid& dataSetFieldId(void);
        OpcUaNumericRange& receiverIndexRange(void);
        OpcUaNodeId& targetNodeId(void);
        OpcUaIntegerId& attributeId(void);
        OpcUaNumericRange& writeIndexRange(void);
        OverrideValueHandling& overrideValueHandling(void);
        OpcUaVariant& overrideValue(void);
        
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
        
        void copyTo(FieldTargetDataType& value);
        bool operator==(const FieldTargetDataType& value);
        bool operator!=(const FieldTargetDataType& value);
        FieldTargetDataType& operator=(const FieldTargetDataType& value);
    
      private:
        OpcUaGuid dataSetFieldId_;
        OpcUaNumericRange receiverIndexRange_;
        OpcUaNodeId targetNodeId_;
        OpcUaIntegerId attributeId_;
        OpcUaNumericRange writeIndexRange_;
        OverrideValueHandling overrideValueHandling_;
        OpcUaVariant overrideValue_;
    
    };
    
    class DLLEXPORT FieldTargetDataTypeArray
    : public OpcUaArray<FieldTargetDataType::SPtr, SPtrTypeCoder<FieldTargetDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<FieldTargetDataTypeArray> SPtr;
    };

}

#endif
