/*
    EnumTypeClass: ExceptionDeviationFormat

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ExceptionDeviationFormat_h__
#define __OpcUaStackCore_ExceptionDeviationFormat_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ExceptionDeviationFormat
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ExceptionDeviationFormat> SPtr;
    
        typedef enum {
            EnumAbsoluteValue = 0,
            EnumPercentOfValue = 1,
            EnumPercentOfRange = 2,
            EnumPercentOfEURange = 3,
            EnumUnknown = 4,
        } Enum;
    
        ExceptionDeviationFormat(void);
        ExceptionDeviationFormat(Enum enumeration);
        ExceptionDeviationFormat(ExceptionDeviationFormat& value);
        virtual ~ExceptionDeviationFormat(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        static Enum str2Enum(const std::string& enumerationString);
        static std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        static bool exist(const std::string& enumerationString);
        static bool exist(Enum enumeration);
        
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
        
        void copyTo(ExceptionDeviationFormat& value);
        bool operator==(const ExceptionDeviationFormat& value) const;
        bool operator!=(const ExceptionDeviationFormat& value) const;
        ExceptionDeviationFormat& operator=(const ExceptionDeviationFormat& value);
        ExceptionDeviationFormat& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT ExceptionDeviationFormatArray
    : public OpcUaArray<ExceptionDeviationFormat::SPtr, SPtrTypeCoder<ExceptionDeviationFormat> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ExceptionDeviationFormatArray> SPtr;
    };

}

#endif
