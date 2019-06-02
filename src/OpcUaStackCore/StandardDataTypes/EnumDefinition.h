/*
    DataTypeClass: EnumDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EnumDefinition_h__
#define __OpcUaStackCore_EnumDefinition_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/EnumField.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EnumDefinition
    : public DataTypeDefinition
    {
      public:
        typedef boost::shared_ptr<EnumDefinition> SPtr;
        typedef std::vector<EnumDefinition::SPtr> Vec;
    
        EnumDefinition(void);
        EnumDefinition(const EnumDefinition& value);
        virtual ~EnumDefinition(void);
        
        EnumFieldArray& fields(void);
        
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
        
        void copyTo(EnumDefinition& value);
        bool operator==(const EnumDefinition& value);
        bool operator!=(const EnumDefinition& value);
        EnumDefinition& operator=(const EnumDefinition& value);
    
      private:
        EnumFieldArray fields_;
    
    };
    
    class DLLEXPORT EnumDefinitionArray
    : public OpcUaArray<EnumDefinition::SPtr, SPtrTypeCoder<EnumDefinition> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EnumDefinitionArray> SPtr;
    };

}

#endif
