/*
    DataTypeClass: MonitoredItemCreateResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MonitoredItemCreateResult_h__
#define __OpcUaStackCore_MonitoredItemCreateResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
