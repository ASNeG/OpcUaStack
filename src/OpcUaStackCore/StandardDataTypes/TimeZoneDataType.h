/*
    DataTypeClass: TimeZoneDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_TimeZoneDataType_h__
#define __OpcUaStackCore_TimeZoneDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT TimeZoneDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<TimeZoneDataType> SPtr;
        typedef std::vector<TimeZoneDataType::SPtr> Vec;
    
        TimeZoneDataType(void);
        TimeZoneDataType(const TimeZoneDataType& value);
        virtual ~TimeZoneDataType(void);
        
        OpcUaInt16& offset(void);
        OpcUaBoolean& daylightSavingInOffset(void);
        
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
        
        void copyTo(TimeZoneDataType& value);
        bool operator==(const TimeZoneDataType& value);
        bool operator!=(const TimeZoneDataType& value);
        TimeZoneDataType& operator=(const TimeZoneDataType& value);
    
      private:
        OpcUaInt16 offset_;
        OpcUaBoolean daylightSavingInOffset_;
    
    };
    
    class DLLEXPORT TimeZoneDataTypeArray
    : public OpcUaArray<TimeZoneDataType::SPtr, SPtrTypeCoder<TimeZoneDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<TimeZoneDataTypeArray> SPtr;
    };

}

#endif
