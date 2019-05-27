/*
    EnumTypeClass: FilterOperator

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_FilterOperator_h__
#define __OpcUaStackCore_FilterOperator_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT FilterOperator
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<FilterOperator> SPtr;
    
        typedef enum {
            EnumEquals = 0,
            EnumIsNull = 1,
            EnumGreaterThan = 2,
            EnumLessThan = 3,
            EnumGreaterThanOrEqual = 4,
            EnumLessThanOrEqual = 5,
            EnumLike = 6,
            EnumNot = 7,
            EnumBetween = 8,
            EnumInList = 9,
            EnumAnd = 10,
            EnumOr = 11,
            EnumCast = 12,
            EnumInView = 13,
            EnumOfType = 14,
            EnumRelatedTo = 15,
            EnumBitwiseAnd = 16,
            EnumBitwiseOr = 17,
        } Enum;
    
        FilterOperator(void);
        FilterOperator(Enum enumeration);
        FilterOperator(FilterOperator& value);
        virtual ~FilterOperator(void);
        
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
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(FilterOperator& value);
        bool operator==(const FilterOperator& value) const;
        bool operator!=(const FilterOperator& value) const;
        FilterOperator& operator=(const FilterOperator& value);
        FilterOperator& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT FilterOperatorArray
    : public OpcUaArray<FilterOperator::SPtr, SPtrTypeCoder<FilterOperator> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<FilterOperatorArray> SPtr;
    };

}

#endif
