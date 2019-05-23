/*
    DataTypeClass: AttributeOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AttributeOperand_h__
#define __OpcUaStackCore_AttributeOperand_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/FilterOperand.h"
#include "OpcUaStackCore/StandardDataTypes/RelativePath.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AttributeOperand
    : public FilterOperand
    {
      public:
        typedef boost::shared_ptr<AttributeOperand> SPtr;
        typedef std::vector<AttributeOperand::SPtr> Vec;
    
        AttributeOperand(void);
        AttributeOperand(const AttributeOperand& value);
        virtual ~AttributeOperand(void);
        
        OpcUaNodeId& nodeId(void);
        OpcUaString& alias(void);
        RelativePath& browsePath(void);
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
        
        void copyTo(AttributeOperand& value);
        bool operator==(const AttributeOperand& value);
        bool operator!=(const AttributeOperand& value);
        AttributeOperand& operator=(const AttributeOperand& value);
    
      private:
        OpcUaNodeId nodeId_;
        OpcUaString alias_;
        RelativePath browsePath_;
        OpcUaIntegerId attributeId_;
        OpcUaNumericRange indexRange_;
    
    };
    
    class DLLEXPORT AttributeOperandArray
    : public OpcUaArray<AttributeOperand::SPtr, SPtrTypeCoder<AttributeOperand> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AttributeOperandArray> SPtr;
    };

}

#endif
