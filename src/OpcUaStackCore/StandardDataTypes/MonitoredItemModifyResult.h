/*
    DataTypeClass: MonitoredItemModifyResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MonitoredItemModifyResult_h__
#define __OpcUaStackCore_MonitoredItemModifyResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
