/*
    DataTypeClass: EnumDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EnumDescription_h__
#define __OpcUaStackCore_EnumDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDescription.h"
#include "OpcUaStackCore/StandardDataTypes/EnumDefinition.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EnumDescription
    : public DataTypeDescription
    {
      public:
        typedef boost::shared_ptr<EnumDescription> SPtr;
        typedef std::vector<EnumDescription::SPtr> Vec;
    
        EnumDescription(void);
        EnumDescription(const EnumDescription& value);
        virtual ~EnumDescription(void);
        
        EnumDefinition& enumDefinition(void);
        OpcUaByte& builtInType(void);
        
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
        
        void copyTo(EnumDescription& value);
        bool operator==(const EnumDescription& value);
        bool operator!=(const EnumDescription& value);
        EnumDescription& operator=(const EnumDescription& value);
    
      private:
        EnumDefinition enumDefinition_;
        OpcUaByte builtInType_;
    
    };
    
    class DLLEXPORT EnumDescriptionArray
    : public OpcUaArray<EnumDescription::SPtr, SPtrTypeCoder<EnumDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EnumDescriptionArray> SPtr;
    };

}

#endif
