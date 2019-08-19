/*
    DataTypeClass: SimpleAttributeOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SimpleAttributeOperand_h__
#define __OpcUaStackCore_SimpleAttributeOperand_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/FilterOperand.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SimpleAttributeOperand
    : public FilterOperand
    {
      public:
        typedef boost::shared_ptr<SimpleAttributeOperand> SPtr;
        typedef std::vector<SimpleAttributeOperand::SPtr> Vec;
    
        SimpleAttributeOperand(void);
        SimpleAttributeOperand(const SimpleAttributeOperand& value);
        virtual ~SimpleAttributeOperand(void);
        
        OpcUaNodeId& typeDefinitionId(void);
        OpcUaQualifiedNameArray& browsePath(void);
        OpcUaIntegerId& attributeId(void);
        OpcUaNumericRange& indexRange(void);
        
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
        
        void copyTo(SimpleAttributeOperand& value);
        bool operator==(const SimpleAttributeOperand& value);
        bool operator!=(const SimpleAttributeOperand& value);
        SimpleAttributeOperand& operator=(const SimpleAttributeOperand& value);
    
      private:
        OpcUaNodeId typeDefinitionId_;
        OpcUaQualifiedNameArray browsePath_;
        OpcUaIntegerId attributeId_;
        OpcUaNumericRange indexRange_;
    
    };
    
    class DLLEXPORT SimpleAttributeOperandArray
    : public OpcUaArray<SimpleAttributeOperand::SPtr, SPtrTypeCoder<SimpleAttributeOperand> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SimpleAttributeOperandArray> SPtr;
    };

}

#endif
