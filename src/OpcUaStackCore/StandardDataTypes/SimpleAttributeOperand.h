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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
