/*
    DataTypeClass: FieldMetaData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_FieldMetaData_h__
#define __OpcUaStackCore_FieldMetaData_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT FieldMetaData
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<FieldMetaData> SPtr;
        typedef std::vector<FieldMetaData::SPtr> Vec;
    
        FieldMetaData(void);
        FieldMetaData(const FieldMetaData& value);
        virtual ~FieldMetaData(void);
        
        OpcUaString& name(void);
        OpcUaLocalizedText& description(void);
        OpcUaDataSetFieldFlag& fieldFlags(void);
        OpcUaByte& builtInType(void);
        OpcUaNodeId& dataType(void);
        OpcUaInt32& valueRank(void);
        OpcUaUInt32Array& arrayDimensions(void);
        OpcUaUInt32& maxStringLength(void);
        OpcUaGuid& dataSetFieldId(void);
        KeyValuePairArray& properties(void);
        
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
        
        void copyTo(FieldMetaData& value);
        bool operator==(const FieldMetaData& value);
        bool operator!=(const FieldMetaData& value);
        FieldMetaData& operator=(const FieldMetaData& value);
    
      private:
        OpcUaString name_;
        OpcUaLocalizedText description_;
        OpcUaDataSetFieldFlag fieldFlags_;
        OpcUaByte builtInType_;
        OpcUaNodeId dataType_;
        OpcUaInt32 valueRank_;
        OpcUaUInt32Array arrayDimensions_;
        OpcUaUInt32 maxStringLength_;
        OpcUaGuid dataSetFieldId_;
        KeyValuePairArray properties_;
    
    };
    
    class DLLEXPORT FieldMetaDataArray
    : public OpcUaArray<FieldMetaData::SPtr, SPtrTypeCoder<FieldMetaData> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<FieldMetaDataArray> SPtr;
    };

}

#endif
