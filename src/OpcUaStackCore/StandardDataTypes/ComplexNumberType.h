/*
    DataTypeClass: ComplexNumberType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ComplexNumberType_h__
#define __OpcUaStackCore_ComplexNumberType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

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
