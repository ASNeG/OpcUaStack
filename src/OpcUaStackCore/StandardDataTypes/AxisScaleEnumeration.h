/*
    EnumTypeClass: AxisScaleEnumeration

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor:     Kai Huebl (kai@huebl-sgh.de)
    BuildDate: 2018-Oct-25 09:23:30.462163
*/

#ifndef __OpcUaStackCore_AxisScaleEnumeration_h__
#define __OpcUaStackCore_AxisScaleEnumeration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class AxisScaleEnumeration
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<AxisScaleEnumeration> SPtr;
    
        typedef enum {
            EnumLinear = 0,
            EnumLog = 1,
            EnumLn = 2,
        } Enum;
    
        AxisScaleEnumeration(void);
        AxisScaleEnumeration(Enum enumeration);
        virtual ~AxisScaleEnumeration(void);
        
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
        
        void copyTo(AxisScaleEnumeration& value);
        bool operator==(const AxisScaleEnumeration& value) const;
        bool operator!=(const AxisScaleEnumeration& value) const;
    
      private:
        uint32_t value_;
    
    };

}

#endif
