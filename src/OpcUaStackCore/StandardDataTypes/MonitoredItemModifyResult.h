/*
    DataTypeClass: MonitoredItemModifyResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MonitoredItemModifyResult_h__
#define __OpcUaStackCore_MonitoredItemModifyResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT MonitoredItemModifyResult
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<MonitoredItemModifyResult> SPtr;
        typedef std::vector<MonitoredItemModifyResult::SPtr> Vec;
    
        MonitoredItemModifyResult(void);
        MonitoredItemModifyResult(const MonitoredItemModifyResult& value);
        virtual ~MonitoredItemModifyResult(void);
        
        OpcUaStatus& statusCode(void);
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
        
        void copyTo(MonitoredItemModifyResult& value);
        bool operator==(const MonitoredItemModifyResult& value);
        bool operator!=(const MonitoredItemModifyResult& value);
        MonitoredItemModifyResult& operator=(const MonitoredItemModifyResult& value);
    
      private:
        OpcUaStatus statusCode_;
        OpcUaDuration revisedSamplingInterval_;
        OpcUaCounter revisedQueueSize_;
        OpcUaExtensibleParameter filterResult_;
    
    };
    
    class DLLEXPORT MonitoredItemModifyResultArray
    : public OpcUaArray<MonitoredItemModifyResult::SPtr, SPtrTypeCoder<MonitoredItemModifyResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MonitoredItemModifyResultArray> SPtr;
    };

}

#endif
