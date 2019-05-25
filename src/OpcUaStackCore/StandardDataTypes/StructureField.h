/*
    DataTypeClass: StructureField

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_StructureField_h__
#define __OpcUaStackCore_StructureField_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT StructureField
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<StructureField> SPtr;
        typedef std::vector<StructureField::SPtr> Vec;
    
        StructureField(void);
        StructureField(const StructureField& value);
        virtual ~StructureField(void);
        
        OpcUaString& name(void);
        OpcUaLocalizedText& description(void);
        OpcUaNodeId& dataType(void);
        OpcUaInt32& valueRank(void);
        OpcUaUInt32Array& arrayDimensions(void);
        OpcUaUInt32& maxStringLength(void);
        OpcUaBoolean& isOptional(void);
        
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
        
        void copyTo(StructureField& value);
        bool operator==(const StructureField& value);
        bool operator!=(const StructureField& value);
        StructureField& operator=(const StructureField& value);
    
      private:
        OpcUaString name_;
        OpcUaLocalizedText description_;
        OpcUaNodeId dataType_;
        OpcUaInt32 valueRank_;
        OpcUaUInt32Array arrayDimensions_;
        OpcUaUInt32 maxStringLength_;
        OpcUaBoolean isOptional_;
    
    };
    
    class DLLEXPORT StructureFieldArray
    : public OpcUaArray<StructureField::SPtr, SPtrTypeCoder<StructureField> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<StructureFieldArray> SPtr;
    };

}

#endif
