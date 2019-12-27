/*
    DataTypeClass: LiteralOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_LiteralOperand_h__
#define __OpcUaStackCore_LiteralOperand_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
