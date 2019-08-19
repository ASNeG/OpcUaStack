/*
    DataTypeClass: EnumValueType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EnumValueType_h__
#define __OpcUaStackCore_EnumValueType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EnumValueType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<EnumValueType> SPtr;
        typedef std::vector<EnumValueType::SPtr> Vec;
    
        EnumValueType(void);
        EnumValueType(const EnumValueType& value);
        virtual ~EnumValueType(void);
        
        OpcUaInt64& value(void);
        OpcUaLocalizedText& displayName(void);
        OpcUaLocalizedText& description(void);
        
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
        
        void copyTo(EnumValueType& value);
        bool operator==(const EnumValueType& value);
        bool operator!=(const EnumValueType& value);
        EnumValueType& operator=(const EnumValueType& value);
    
      private:
        OpcUaInt64 value_; //!< The value of the enumeration.
        OpcUaLocalizedText displayName_; //!< Human readable name for the value.
        OpcUaLocalizedText description_; //!< A description of the value.
    
    };
    
    class DLLEXPORT EnumValueTypeArray
    : public OpcUaArray<EnumValueType::SPtr, SPtrTypeCoder<EnumValueType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EnumValueTypeArray> SPtr;
    };

}

#endif
