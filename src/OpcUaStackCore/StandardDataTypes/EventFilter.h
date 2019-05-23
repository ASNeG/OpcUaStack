/*
    DataTypeClass: EventFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EventFilter_h__
#define __OpcUaStackCore_EventFilter_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoringFilter.h"
#include "OpcUaStackCore/StandardDataTypes/SimpleAttributeOperand.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EventFilter
    : public MonitoringFilter
    {
      public:
        typedef boost::shared_ptr<EventFilter> SPtr;
        typedef std::vector<EventFilter::SPtr> Vec;
    
        EventFilter(void);
        EventFilter(const EventFilter& value);
        virtual ~EventFilter(void);
        
        SimpleAttributeOperandArray& selectClauses(void);
        ContentFilter& whereClause(void);
        
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
        
        void copyTo(EventFilter& value);
        bool operator==(const EventFilter& value);
        bool operator!=(const EventFilter& value);
        EventFilter& operator=(const EventFilter& value);
    
      private:
        SimpleAttributeOperandArray selectClauses_;
        ContentFilter whereClause_;
    
    };
    
    class DLLEXPORT EventFilterArray
    : public OpcUaArray<EventFilter::SPtr, SPtrTypeCoder<EventFilter> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EventFilterArray> SPtr;
    };

}

#endif
