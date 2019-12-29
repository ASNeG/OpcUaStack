/*
    DataTypeClass: MonitoringFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MonitoringFilterResult_h__
#define __OpcUaStackCore_MonitoringFilterResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT MonitoringFilterResult
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<MonitoringFilterResult> SPtr;
        typedef std::vector<MonitoringFilterResult::SPtr> Vec;
    
        MonitoringFilterResult(void);
        MonitoringFilterResult(const MonitoringFilterResult& value);
        virtual ~MonitoringFilterResult(void);
        
        
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
        
        void copyTo(MonitoringFilterResult& value);
        bool operator==(const MonitoringFilterResult& value);
        bool operator!=(const MonitoringFilterResult& value);
        MonitoringFilterResult& operator=(const MonitoringFilterResult& value);
    
      private:
    
    };
    
    class DLLEXPORT MonitoringFilterResultArray
    : public OpcUaArray<MonitoringFilterResult::SPtr, SPtrTypeCoder<MonitoringFilterResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MonitoringFilterResultArray> SPtr;
    };

}

#endif
