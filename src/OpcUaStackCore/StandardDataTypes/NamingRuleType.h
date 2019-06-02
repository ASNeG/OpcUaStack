/*
    EnumTypeClass: NamingRuleType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NamingRuleType_h__
#define __OpcUaStackCore_NamingRuleType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    /**
     * Describes a value that specifies the significance of the BrowseName for an instance declaration.
     */
    class DLLEXPORT NamingRuleType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NamingRuleType> SPtr;
    
        typedef enum {
            EnumMandatory = 1,     //!< The BrowseName must appear in all instances of the type.
            EnumOptional = 2,     //!< The BrowseName may appear in an instance of the type.
            EnumConstraint = 3,     //!< The modelling rule defines a constraint and the BrowseName is not used in an instance of the type.
        } Enum;
    
        NamingRuleType(void);
        NamingRuleType(Enum enumeration);
        NamingRuleType(NamingRuleType& value);
        virtual ~NamingRuleType(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
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
        
        void copyTo(NamingRuleType& value);
        bool operator==(const NamingRuleType& value) const;
        bool operator!=(const NamingRuleType& value) const;
        NamingRuleType& operator=(const NamingRuleType& value);
        NamingRuleType& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT NamingRuleTypeArray
    : public OpcUaArray<NamingRuleType::SPtr, SPtrTypeCoder<NamingRuleType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NamingRuleTypeArray> SPtr;
    };

}

#endif
