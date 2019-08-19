/*
    DataTypeClass: ComplexNumberType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ComplexNumberType_h__
#define __OpcUaStackCore_ComplexNumberType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ComplexNumberType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ComplexNumberType> SPtr;
        typedef std::vector<ComplexNumberType::SPtr> Vec;
    
        ComplexNumberType(void);
        ComplexNumberType(const ComplexNumberType& value);
        virtual ~ComplexNumberType(void);
        
        OpcUaFloat& real(void);
        OpcUaFloat& imaginary(void);
        
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
        
        void copyTo(ComplexNumberType& value);
        bool operator==(const ComplexNumberType& value);
        bool operator!=(const ComplexNumberType& value);
        ComplexNumberType& operator=(const ComplexNumberType& value);
    
      private:
        OpcUaFloat real_;
        OpcUaFloat imaginary_;
    
    };
    
    class DLLEXPORT ComplexNumberTypeArray
    : public OpcUaArray<ComplexNumberType::SPtr, SPtrTypeCoder<ComplexNumberType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ComplexNumberTypeArray> SPtr;
    };

}

#endif
