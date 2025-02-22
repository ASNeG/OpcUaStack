/*
    DataTypeClass: MonitoredItemCreateResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MonitoredItemCreateResult_h__
#define __OpcUaStackCore_MonitoredItemCreateResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT MonitoredItemCreateResult
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<MonitoredItemCreateResult> SPtr;
        typedef std::vector<MonitoredItemCreateResult::SPtr> Vec;
    
        MonitoredItemCreateResult(void);
        MonitoredItemCreateResult(const MonitoredItemCreateResult& value);
        virtual ~MonitoredItemCreateResult(void);
        
        OpcUaStatus& statusCode(void);
        OpcUaIntegerId& monitoredItemId(void);
        OpcUaDuration& revisedSamplingInterval(void);
        OpcUaCounter& revisedQueueSize(void);
        OpcUaExtensibleParameter& filterResult(void);
        
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
        
        void copyTo(MonitoredItemCreateResult& value);
        bool operator==(const MonitoredItemCreateResult& value);
        bool operator!=(const MonitoredItemCreateResult& value);
        MonitoredItemCreateResult& operator=(const MonitoredItemCreateResult& value);
    
      private:
        OpcUaStatus statusCode_;
        OpcUaIntegerId monitoredItemId_;
        OpcUaDuration revisedSamplingInterval_;
        OpcUaCounter revisedQueueSize_;
        OpcUaExtensibleParameter filterResult_;
    
    };
    
    class DLLEXPORT MonitoredItemCreateResultArray
    : public OpcUaArray<MonitoredItemCreateResult::SPtr, SPtrTypeCoder<MonitoredItemCreateResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MonitoredItemCreateResultArray> SPtr;
    };

}

#endif
