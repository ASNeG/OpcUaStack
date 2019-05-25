/*
    DataTypeClass: StructureDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_StructureDefinition_h__
#define __OpcUaStackCore_StructureDefinition_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/StructureType.h"
#include "OpcUaStackCore/StandardDataTypes/StructureField.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT StructureDefinition
    : public DataTypeDefinition
    {
      public:
        typedef boost::shared_ptr<StructureDefinition> SPtr;
        typedef std::vector<StructureDefinition::SPtr> Vec;
    
        StructureDefinition(void);
        StructureDefinition(const StructureDefinition& value);
        virtual ~StructureDefinition(void);
        
        OpcUaNodeId& defaultEncodingId(void);
        OpcUaNodeId& baseDataType(void);
        StructureType& structureType(void);
        StructureFieldArray& fields(void);
        
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
        
        void copyTo(StructureDefinition& value);
        bool operator==(const StructureDefinition& value);
        bool operator!=(const StructureDefinition& value);
        StructureDefinition& operator=(const StructureDefinition& value);
    
      private:
        OpcUaNodeId defaultEncodingId_;
        OpcUaNodeId baseDataType_;
        StructureType structureType_;
        StructureFieldArray fields_;
    
    };
    
    class DLLEXPORT StructureDefinitionArray
    : public OpcUaArray<StructureDefinition::SPtr, SPtrTypeCoder<StructureDefinition> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<StructureDefinitionArray> SPtr;
    };

}

#endif
