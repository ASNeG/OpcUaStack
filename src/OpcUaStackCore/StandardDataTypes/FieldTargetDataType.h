/*
    DataTypeClass: FieldTargetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_FieldTargetDataType_h__
#define __OpcUaStackCore_FieldTargetDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
