/*
    DataTypeClass: EventFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EventFilterResult_h__
#define __OpcUaStackCore_EventFilterResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
