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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
