/*
    DataTypeClass: LiteralOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_LiteralOperand_h__
#define __OpcUaStackCore_LiteralOperand_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/FilterOperand.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT LiteralOperand
    : public FilterOperand
    {
      public:
        typedef boost::shared_ptr<LiteralOperand> SPtr;
        typedef std::vector<LiteralOperand::SPtr> Vec;
    
        LiteralOperand(void);
        LiteralOperand(const LiteralOperand& value);
        virtual ~LiteralOperand(void);
        
        OpcUaVariant& value(void);
        
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
        
        void copyTo(LiteralOperand& value);
        bool operator==(const LiteralOperand& value);
        bool operator!=(const LiteralOperand& value);
        LiteralOperand& operator=(const LiteralOperand& value);
    
      private:
        OpcUaVariant value_;
    
    };
    
    class DLLEXPORT LiteralOperandArray
    : public OpcUaArray<LiteralOperand::SPtr, SPtrTypeCoder<LiteralOperand> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<LiteralOperandArray> SPtr;
    };

}

#endif
