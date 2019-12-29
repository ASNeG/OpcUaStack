/*
    DataTypeClass: SamplingIntervalDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SamplingIntervalDiagnosticsDataType_h__
#define __OpcUaStackCore_SamplingIntervalDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SamplingIntervalDiagnosticsDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SamplingIntervalDiagnosticsDataType> SPtr;
        typedef std::vector<SamplingIntervalDiagnosticsDataType::SPtr> Vec;
    
        SamplingIntervalDiagnosticsDataType(void);
        SamplingIntervalDiagnosticsDataType(const SamplingIntervalDiagnosticsDataType& value);
        virtual ~SamplingIntervalDiagnosticsDataType(void);
        
        OpcUaDuration& samplingInterval(void);
        OpcUaUInt32& monitoredItemCount(void);
        OpcUaUInt32& maxMonitoredItemCount(void);
        OpcUaUInt32& disabledMonitoredItemCount(void);
        
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
        
        void copyTo(SamplingIntervalDiagnosticsDataType& value);
        bool operator==(const SamplingIntervalDiagnosticsDataType& value);
        bool operator!=(const SamplingIntervalDiagnosticsDataType& value);
        SamplingIntervalDiagnosticsDataType& operator=(const SamplingIntervalDiagnosticsDataType& value);
    
      private:
        OpcUaDuration samplingInterval_;
        OpcUaUInt32 monitoredItemCount_;
        OpcUaUInt32 maxMonitoredItemCount_;
        OpcUaUInt32 disabledMonitoredItemCount_;
    
    };
    
    class DLLEXPORT SamplingIntervalDiagnosticsDataTypeArray
    : public OpcUaArray<SamplingIntervalDiagnosticsDataType::SPtr, SPtrTypeCoder<SamplingIntervalDiagnosticsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SamplingIntervalDiagnosticsDataTypeArray> SPtr;
    };

}

#endif
