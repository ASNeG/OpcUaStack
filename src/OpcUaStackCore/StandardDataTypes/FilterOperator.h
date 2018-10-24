/*
    EnumTypeClass: FilterOperator

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor:     Kai Huebl (kai@huebl-sgh.de)
    BuildDate: 2018-Oct-24 20:58:47.015488
*/

#ifndef __OpcUaStackCore_FilterOperator_h__
#define __OpcUaStackCore_FilterOperator_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class FilterOperator
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<FilterOperator> SPtr;
    
        typedef enum {
            Equals = 0,
            IsNull = 1,
            GreaterThan = 2,
            LessThan = 3,
            GreaterThanOrEqual = 4,
            LessThanOrEqual = 5,
            Like = 6,
            Not = 7,
            Between = 8,
            InList = 9,
            And = 10,
            Or = 11,
            Cast = 12,
            InView = 13,
            OfType = 14,
            RelatedTo = 15,
            BitwiseAnd = 16,
            BitwiseOr = 17,
        } Enum;
    
        FilterOperator(void);
        virtual ~FilterOperator(void);
        
        uint32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(FilterOperator& value);
        bool operator==(const FilterOperator& value) const;
        bool operator!=(const FilterOperator& value) const;
    
      private:
        uint32_t value_;
    
    };

}

#endif
