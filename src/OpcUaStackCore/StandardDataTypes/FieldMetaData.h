/*
    DataTypeClass: FieldMetaData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_FieldMetaData_h__
#define __OpcUaStackCore_FieldMetaData_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
