/*
    DataTypeClass: AggregateFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AggregateFilter_h__
#define __OpcUaStackCore_AggregateFilter_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoringFilter.h"
#include "OpcUaStackCore/StandardDataTypes/AggregateConfiguration.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AggregateFilter
    : public MonitoringFilter
    {
      public:
        typedef boost::shared_ptr<AggregateFilter> SPtr;
        typedef std::vector<AggregateFilter::SPtr> Vec;
    
        AggregateFilter(void);
        AggregateFilter(const AggregateFilter& value);
        virtual ~AggregateFilter(void);
        
        OpcUaUtcTime& startTime(void);
        OpcUaNodeId& aggregateType(void);
        OpcUaDuration& processingInterval(void);
        AggregateConfiguration& aggregateConfiguration(void);
        
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
        
        void copyTo(AggregateFilter& value);
        bool operator==(const AggregateFilter& value);
        bool operator!=(const AggregateFilter& value);
        AggregateFilter& operator=(const AggregateFilter& value);
    
      private:
        OpcUaUtcTime startTime_;
        OpcUaNodeId aggregateType_;
        OpcUaDuration processingInterval_;
        AggregateConfiguration aggregateConfiguration_;
    
    };
    
    class DLLEXPORT AggregateFilterArray
    : public OpcUaArray<AggregateFilter::SPtr, SPtrTypeCoder<AggregateFilter> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AggregateFilterArray> SPtr;
    };

}

#endif
