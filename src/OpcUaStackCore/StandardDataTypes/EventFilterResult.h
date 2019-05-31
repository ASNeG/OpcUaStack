/*
    DataTypeClass: EventFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EventFilterResult_h__
#define __OpcUaStackCore_EventFilterResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoringFilterResult.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilterResult.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EventFilterResult
    : public MonitoringFilterResult
    {
      public:
        typedef boost::shared_ptr<EventFilterResult> SPtr;
        typedef std::vector<EventFilterResult::SPtr> Vec;
    
        EventFilterResult(void);
        EventFilterResult(const EventFilterResult& value);
        virtual ~EventFilterResult(void);
        
        OpcUaStatusArray& selectClauseResults(void);
        OpcUaDiagnosticInfoArray& selectClauseDiagnosticInfos(void);
        ContentFilterResult& whereClauseResult(void);
        
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
        
        void copyTo(EventFilterResult& value);
        bool operator==(const EventFilterResult& value);
        bool operator!=(const EventFilterResult& value);
        EventFilterResult& operator=(const EventFilterResult& value);
    
      private:
        OpcUaStatusArray selectClauseResults_;
        OpcUaDiagnosticInfoArray selectClauseDiagnosticInfos_;
        ContentFilterResult whereClauseResult_;
    
    };
    
    class DLLEXPORT EventFilterResultArray
    : public OpcUaArray<EventFilterResult::SPtr, SPtrTypeCoder<EventFilterResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EventFilterResultArray> SPtr;
    };

}

#endif
