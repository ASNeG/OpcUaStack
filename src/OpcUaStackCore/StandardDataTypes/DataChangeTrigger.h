/*
    EnumTypeClass: DataChangeTrigger

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataChangeTrigger_h__
#define __OpcUaStackCore_DataChangeTrigger_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataChangeTrigger
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DataChangeTrigger> SPtr;
    
        typedef enum {
            EnumStatus = 0,
            EnumStatusValue = 1,
            EnumStatusValueTimestamp = 2,
        } Enum;
    
        DataChangeTrigger(void);
        DataChangeTrigger(Enum enumeration);
        DataChangeTrigger(DataChangeTrigger& value);
        virtual ~DataChangeTrigger(void);
        
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
        
        void copyTo(DataChangeTrigger& value);
        bool operator==(const DataChangeTrigger& value) const;
        bool operator!=(const DataChangeTrigger& value) const;
        DataChangeTrigger& operator=(const DataChangeTrigger& value);
        DataChangeTrigger& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DataChangeTriggerArray
    : public OpcUaArray<DataChangeTrigger::SPtr, SPtrTypeCoder<DataChangeTrigger> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataChangeTriggerArray> SPtr;
    };

}

#endif
