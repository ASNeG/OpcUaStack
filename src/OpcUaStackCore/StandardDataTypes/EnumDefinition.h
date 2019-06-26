/*
    DataTypeClass: EnumDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EnumDefinition_h__
#define __OpcUaStackCore_EnumDefinition_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
