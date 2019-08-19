/*
    DataTypeClass: IdentityMappingRuleType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_IdentityMappingRuleType_h__
#define __OpcUaStackCore_IdentityMappingRuleType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/IdentityCriteriaType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT IdentityMappingRuleType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<IdentityMappingRuleType> SPtr;
        typedef std::vector<IdentityMappingRuleType::SPtr> Vec;
    
        IdentityMappingRuleType(void);
        IdentityMappingRuleType(const IdentityMappingRuleType& value);
        virtual ~IdentityMappingRuleType(void);
        
        IdentityCriteriaType& criteriaType(void);
        OpcUaString& criteria(void);
        
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
        
        void copyTo(IdentityMappingRuleType& value);
        bool operator==(const IdentityMappingRuleType& value);
        bool operator!=(const IdentityMappingRuleType& value);
        IdentityMappingRuleType& operator=(const IdentityMappingRuleType& value);
    
      private:
        IdentityCriteriaType criteriaType_;
        OpcUaString criteria_;
    
    };
    
    class DLLEXPORT IdentityMappingRuleTypeArray
    : public OpcUaArray<IdentityMappingRuleType::SPtr, SPtrTypeCoder<IdentityMappingRuleType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<IdentityMappingRuleTypeArray> SPtr;
    };

}

#endif
