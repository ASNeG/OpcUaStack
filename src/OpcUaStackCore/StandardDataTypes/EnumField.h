/*
    DataTypeClass: EnumField

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EnumField_h__
#define __OpcUaStackCore_EnumField_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/EnumValueType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EnumField
    : public EnumValueType
    {
      public:
        typedef boost::shared_ptr<EnumField> SPtr;
        typedef std::vector<EnumField::SPtr> Vec;
    
        EnumField(void);
        EnumField(const EnumField& value);
        virtual ~EnumField(void);
        
        OpcUaString& name(void);
        
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
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(EnumField& value);
        bool operator==(const EnumField& value);
        bool operator!=(const EnumField& value);
        EnumField& operator=(const EnumField& value);
    
      private:
        OpcUaString name_;
    
    };
    
    class DLLEXPORT EnumFieldArray
    : public OpcUaArray<EnumField::SPtr, SPtrTypeCoder<EnumField> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EnumFieldArray> SPtr;
    };

}

#endif
