/*
    DataTypeClass: EventFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EventFilter_h__
#define __OpcUaStackCore_EventFilter_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
