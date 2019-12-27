/*
    DataTypeClass: SimpleTypeDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SimpleTypeDescription_h__
#define __OpcUaStackCore_SimpleTypeDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDescription.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SimpleTypeDescription
    : public DataTypeDescription
    {
      public:
        typedef boost::shared_ptr<SimpleTypeDescription> SPtr;
        typedef std::vector<SimpleTypeDescription::SPtr> Vec;
    
        SimpleTypeDescription(void);
        SimpleTypeDescription(const SimpleTypeDescription& value);
        virtual ~SimpleTypeDescription(void);
        
        OpcUaNodeId& baseDataType(void);
        OpcUaByte& builtInType(void);
        
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
        
        void copyTo(SimpleTypeDescription& value);
        bool operator==(const SimpleTypeDescription& value);
        bool operator!=(const SimpleTypeDescription& value);
        SimpleTypeDescription& operator=(const SimpleTypeDescription& value);
    
      private:
        OpcUaNodeId baseDataType_;
        OpcUaByte builtInType_;
    
    };
    
    class DLLEXPORT SimpleTypeDescriptionArray
    : public OpcUaArray<SimpleTypeDescription::SPtr, SPtrTypeCoder<SimpleTypeDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SimpleTypeDescriptionArray> SPtr;
    };

}

#endif
