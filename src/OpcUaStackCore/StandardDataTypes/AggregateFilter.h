/*
    DataTypeClass: AggregateFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AggregateFilter_h__
#define __OpcUaStackCore_AggregateFilter_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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
